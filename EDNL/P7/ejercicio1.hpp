
#include <vector>
#include <algorithm>

#include "../Material_Grafos/alg_grafoPMC.h"
#include "../Material_Grafos/grafoPMC.h"

typedef unsigned int tCoste;

// FUNCIONES AUXILIARES

template <typename tCoste>
matriz<tCoste> FloydMax(const GrafoP<tCoste>& G,
                     matriz<typename GrafoP<tCoste>::vertice>& P)
// Calcula los caminos de coste máximo entre cada
// par de vértices del grafo G. Devuelve una matriz
// de costes máximos A de tamaño n x n, con n = G.numVert()
// y una matriz de vértices P de tamaño n x n, tal que
// P[i][j] es el vértice por el que pasa el camino de coste
// máximo de i a j, si este vértice es i el camino es directo.
{
   typedef typename GrafoP<tCoste>::vertice vertice;
   const size_t n = G.numVert();
   matriz<tCoste> A(n);   // matriz de costes mínimos

   // Iniciar A y P con caminos directos entre cada par de vértices.
   P = matriz<vertice>(n);
   for (vertice i = 0; i < n; i++) {
      A[i] = G[i];                    // copia costes del grafo
      A[i][i] = 0;                    // diagonal a 0
      P[i] = vector<vertice>(n, i);   // caminos directos
   }
   // Calcular costes mínimos y caminos correspondientes
   // entre cualquier par de vértices i, j
   for (vertice k = 0; k < n; k++)
      for (vertice i = 0; i < n; i++)
         for (vertice j = 0; j < n; j++) {
            tCoste ikj = suma(A[i][k], A[k][j]);
            if (ikj != GrafoP<tCoste>::INFINITO && (A[i][j] == GrafoP<tCoste>::INFINITO || ikj > A[i][j])) {
               A[i][j] = ikj;
               P[i][j] = k;
            }
         }
   for (vertice i = 0; i < n; i++) {
      A[i][i] = 0;  // diagonal a 0
      P[i][i] = i;  // caminos directos
   }
   return A;
}

/*
1. Tu agencia de viajes “OTRAVEZUNGRAFO S.A.”  se enfrenta a un curioso cliente. 
Es un personaje sorprendente, no le importa el dinero y quiere hacer el viaje más 
caro posible entre las ciudades que ofertas. Su objetivo es gastarse la mayor 
cantidad de dinero posible (ojalá todos los clientes fueran así), no le importa 
el origen ni el destino del viaje.

Sabiendo que es imposible pasar dos veces por la misma ciudad, ya que casualmente 
el grafo de tu agencia de viajes resultó ser acíclico, devolver el coste, origen 
y destino de tan curioso viaje. Se parte de la matriz de costes directos entre 
las ciudades del grafo.
*/

template <typename tCoste> tCoste caminoMasCaro(const GrafoP<tCoste>& G, typename GrafoP<tCoste>::vertice& origen, typename GrafoP<tCoste>::vertice& destino)
{
    const int n = G.numVert();

    matriz<typename GrafoP<tCoste>::vertice> P(n);
    matriz<tCoste> A(n);
    
    A = FloydMax(G, P);

    tCoste costeMax = 0, costeActual;
    origen = 0;
    destino = 0;

    for( typename GrafoP<tCoste>::vertice i = 0; i < n; ++i )
        for( typename GrafoP<tCoste>::vertice j = 0; j < n; ++j )
        {
            costeActual = A[i][j];
            if( costeActual != GrafoP<tCoste>::INFINITO && costeMax < costeActual )
            {
                costeMax = costeActual;
                origen = i;
                destino = j;
            }
        }
    return costeMax;
}