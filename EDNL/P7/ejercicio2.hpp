#include <vector>
#include <algorithm>

#include "../Material_Grafos/alg_grafoPMC.h"
#include "../Material_Grafos/grafoPMC.h"

typedef unsigned int tCoste;
/*
2. Se dispone de un laberinto de NxN casillas del que se conocen las 
casillas de entrada y salida del mismo. Si te encuentras en una casilla 
sólo puedes moverte en las siguientes cuatro direcciones (arriba, 
abajo, derecha, izquierda). Por otra parte, entre algunas de las casillas 
hay una pared que impide moverse entre las dos casillas que separa 
dicha pared (en caso contrario  no sería un verdadero laberinto).
Implementa un subprograma que dados
- N (dimensión del laberinto),
- la lista de paredes del laberinto,
- la casilla de entrada, y
- la casilla de salida,
calcule el camino más corto para ir de la entrada a la salida y su longitud. 
*/
/*
Dada una casilla [i,j], su vértice asociado es i*N + j
Dado un vértice v, su casilla asociada es [v / N, v % N]

Matriz de costes de dimensión N^2 * N^2, cada vértice 
necesitará indicar los costes para cada una de las N casillas 
del laberinto, por tanto N^2 vértices por N^2 casillas.

Ejemplo:
N = 4
0--1--2--3
|  |  |  |
4--5--6--7
|  |  |  |
8--9--10-11
|  |  |  |
12-13-14-15
*/
template <typename tCoste> std::pair<std::vector<std::pair<size_t, size_t>>, size_t> laberinto(const size_t& N, const Lista<std::pair<size_t, size_t>>& paredes, const std::pair<size_t, size_t>& entrada, const std::pair<size_t, size_t>& salida)
{
    GrafoP<tCoste> gLab(N*N);
    matriz<tCoste> mLab(N*N, GrafoP<tCoste>::INFINITO);

    std::vector<std::pair<size_t,size_t>> caminoRes;

    //Crear conexiones entre casillas con los movimientos disponibles (arriba, abajo, izquierda y derecha)
    for( size_t i = 0; i < N*N; ++i )
    {
        if( (i + 1) % N )
        {
            mLab[i][i + 1] = 1;
            mLab[i + 1][i] = 1;
        }
        if( i + N < N*N )
        {
            mLab[i][i + N] = 1;
            mLab[i + N][i] = 1;
        }
    }

    //La casillas con paredes implican un camino inexistente entre nodos
    for( Lista<std::pair<size_t, size_t>>::posicion p = paredes.primera(); p != paredes.fin(); p = paredes.siguiente(p) )
    {
        mLab[paredes.elemento(p).first][paredes.elemento(p).second] = mLab[paredes.elemento(p).second][paredes.elemento(p).first] = GrafoP<tCoste>::INFINITO;
    }

    //Convertir matriz de costes a grafo
    for( size_t i = 0; i < N*N; ++i )
    {
        mLab[i][i] = 0; //Diagonal principal a 0
        gLab[i] = mLab[i];
    }
    
    //Calcular camino más corto con Dijkstra
    typename GrafoP<tCoste>::vertice origen = (entrada.first * N) + entrada.second, destino = (salida.first * N) + salida.second;
    std::vector<typename GrafoP<tCoste>::vertice> P;
    std::vector<tCoste> D = Dijkstra<tCoste>(gLab, origen, P);
    typename GrafoP<tCoste>::tCamino caminoG = camino<tCoste>(origen, destino, P);

    //Convertir tCamino en vector de casillas
    for( typename GrafoP<tCoste>::tCamino::posicion c = caminoG.primera(); c != caminoG.fin(); c = caminoG.siguiente(c) )
    {
        caminoRes.push_back(std::make_pair(caminoG.elemento(c) / N, caminoG.elemento(c) % N));
    }

    //for( size_t i = 0; i < N*N; ++i )
    //{
    //    for( size_t j = 0; j < N*N; ++j )
    //    {
    //        if( gLab[i][j] == GrafoP<tCoste>::INFINITO)
    //            std::cout << "INF,\t";
    //        else
    //            std::cout << mLab[i][j] << ",\t\t";
    //    }
    //    std::cout << std::endl;
    //}

    return std::make_pair(caminoRes, D[destino]);
}