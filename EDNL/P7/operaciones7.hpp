#ifndef OPERP7_HPP
#define OPERP7_HPP

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

/*
3. Eres el orgulloso dueño de una empresa de distribución. 
Tu misión radica en distribuir todo tu stock entre las diferentes
ciudades en las que tu empresa dispone de almacén.

Tienes un grafo representado mediante la matriz de costes, 
en el que aparece el coste (por unidad de producto) de transportar
los productos entre las diferentes ciudades del grafo.

Pero además resulta que los Ayuntamientos de las diferentes ciudades
en las que tienes almacén están muy interesados en que almacenes tus
productos en ellas, por lo que están dispuestos a subvencionarte con
un porcentaje de los gastos mínimos de transporte hasta la ciudad.
Para facilitar el problema, consideraremos despreciables los costes
de volver el camión a su base (centro de producción).

He aquí tu problema. Dispones de 

- el centro de producción, nodo origen en el que tienes tu producto (no tiene almacén),
- una cantidad de unidades de producto (cantidad),
- la matriz de costes del grafo de distribución con N ciudades,
- la capacidad de almacenamiento de cada una de ellas,
- el porcentaje de subvención (sobre los gastos mínimos) que te ofrece cada Ayuntamiento.

Las diferentes ciudades (almacenes) pueden tener distinta capacidad,
y además la capacidad total puede ser superior a la cantidad disponible
de producto, por lo que debes decidir cuántas unidades de producto
almacenas en cada una de las ciudades.

Debes tener en cuenta además las subvenciones que recibirás de los diferentes
Ayuntamientos, las cuales pueden ser distintas en cada uno y estarán entre el
0% y el 100% de los costes mínimos.

La solución del problema debe incluir las cantidades a almacenar en cada ciudad
bajo estas condiciones y el coste mínimo total de la operación de distribución
para tu empresa.
*/

struct Ruta
{
    size_t coste; 
    std::vector<size_t> almacenado;
    Ruta(size_t co, std::vector<size_t> ca) : coste(co), almacenado(ca) {}
};

template <typename tCoste> /*std::pair<tCoste, std::vector<size_t>>*/Ruta distribuidora(const typename GrafoP<tCoste>::vertice& origen, size_t cantidad, const matriz<tCoste>& M, size_t N, const std::vector<size_t>& capacidad, const std::vector<size_t>& subvencion)
{
    typedef typename GrafoP<tCoste>::vertice vertice;
    GrafoP<tCoste> G(N);

    for( vertice i = 0; i < N; ++i )
        G[i] = M[i];

    std::vector<vertice> P;
    std::vector<tCoste> minimos = Dijkstra<tCoste>(G, origen, P);

    minimos[origen] = GrafoP<tCoste>::INFINITO; //En origen no hay almacén

    //Aplicar subvenciones
    for( vertice i = 0; i < N; ++i )
        if( minimos[i] != GrafoP<tCoste>::INFINITO )
        {
            minimos[i] *= 1.0 - subvencion[i] / 100;
            minimos[i] += capacidad[i];
        }

    //std::cout << "LLEGA" << std::endl;

    //Calcular la ruta más cara
    vertice destino = 0;
    tCoste maximo = 0;
    for( vertice i = 0; i < N; ++i )
        if( minimos[i] != GrafoP<tCoste>::INFINITO && maximo < minimos[i] )
        {
            maximo = minimos[i];
            destino = i;
        }

    typename GrafoP<tCoste>::tCamino ruta = camino<tCoste>(origen, destino, P);

    size_t cantidadRestante = cantidad;
    std::vector<size_t> almacenado(N, 0);
    vertice actual;
    for( typename GrafoP<tCoste>::tCamino::posicion r = ruta.primera(); r != ruta.fin() && cantidadRestante > 0; r = ruta.siguiente(r) )
    {
        actual = ruta.elemento(r);
        std::cout << actual << ", ";
        if( cantidadRestante >= capacidad[actual] )
        {
            almacenado[actual] = capacidad[actual];
            cantidadRestante -= capacidad[actual];
        }
        else
        {
            almacenado[actual] = cantidadRestante;
            cantidadRestante -= 0;
        }
    }

    //return std::make_pair<tCoste, std::vector<size_t> >(minimos[origen][destino], almacenado);
    return Ruta(minimos[destino], almacenado);
}

/*
4. Eres el orgulloso dueño de la empresa “Cementos de Zuelandia S.A”. 
Empresa dedicada a la fabricación y distribución de cemento, sita en 
la capital de Zuelandia. Para la distribución del cemento entre tus 
diferentes clientes (ciudades de Zuelandia) dispones de una flota de 
camiones y de una plantilla de conductores zuelandeses.

El problema a resolver tiene que ver con el carácter del zuelandés.
El zuelandés es una persona que se toma demasiadas “libertades” en
su trabajo, de hecho, tienes fundadas sospechas de que tus conductores
utilizan los camiones de la empresa para usos particulares (es decir
indebidos, y a tu costa) por lo que quieres controlar los kilómetros
que recorren tus camiones. 

Todos los días se genera el parte de trabajo, en el que se incluyen
el número de cargas de cemento (1 carga = 1 camión lleno de cemento)
que debes enviar a cada cliente (cliente =  ciudad de Zuelandia).
Es innecesario indicar que no todos los días hay que enviar cargas a
todos los clientes, y además, puedes suponer razonablemente que tu flota
de camiones es capaz de hacer el trabajo diario.

Para la resolución del problema quizá sea interesante recordar que
Zuelandia es un país cuya especial orografía sólo permite que las
carreteras tengan un sentido de circulación.

Implementa una función que dado el grafo con las distancias directas
entre las diferentes ciudades zuelandesas, el parte de trabajo diario,
y la capital de Zuelandia, devuelva la distancia total en kilómetros
que deben recorrer tus camiones en el día, para que puedas descubrir
si es cierto o no que usan tus camiones en actividades ajenas a la empresa. 
*/

template <typename tCoste> tCoste cementos(const GrafoP<tCoste>& G, const typename GrafoP<tCoste>::vertice& capital, const std::vector<size_t>& cargas)
{
    std::vector<typename GrafoP<tCoste>::vertice> P(G.numVert());
    std::vector<tCoste> D = Dijkstra(G, capital, P);

    std::vector<tCoste> Dinv = DijkstraInv(G, capital, P);

    tCoste KMtotales = 0;
    for( int i = 0; i < G.numVert(); ++i )
        KMtotales += suma<tCoste>(D[i], Dinv[i]) * cargas[i];

    return KMtotales;
}

/*
Nota Importante: 
 
A partir del problema 5 (el viajero alérgico), empiezan a aparecer 
en los enunciados el uso de diferentes medios de transporte a la hora 
de realizar un viaje. En nuestros problemas (tanto en prácticas como 
en exámenes) asumiremos que
 
a) Definición de trasbordo: En el contexto de los problemas de la
asignatura, consideraremos trasbordo el cambio de medio de transporte. 
 
b) Trasbordos libres y gratuitos por defecto: Si el enunciado del problema
no indica lo contrario los trasbordos en nuestros problemas son libres y gratuitos.  
 
5. Se dispone de tres grafos que representan la matriz de costes para
viajes en un determinado país pero por diferentes medios de transporte,
por supuesto todos los grafos tendrán el mismo número de nodos. El primer
grafo representa los costes de ir por carretera, el segundo en tren y el
tercero en avión. Dado un viajero que dispone de una determinada cantidad de
dinero, que es alérgico a uno de los tres medios de transporte, y que sale
de una ciudad determinada, implementar un subprograma que determine las
ciudades a las que podría llegar nuestro infatigable viajero.
*/

template <typename tCoste> std::vector<typename GrafoP<tCoste>::vertice> viajeroAlergico(const GrafoP<tCoste>& medio1, const GrafoP<tCoste>& medio2, const typename GrafoP<tCoste>::vertice& origen, size_t presupuesto)
{
    GrafoP<tCoste> costes(medio1.numVert());
    for( typename GrafoP<tCoste>::vertice i = 0; i < costes.numVert(); ++i )
        for( typename GrafoP<tCoste>::vertice j = 0; j < costes.numVert(); ++j )
            costes[i][j] = std::min(medio1[i][j], medio2[i][j]);

    std::vector<typename GrafoP<tCoste>::vertice> P(costes.numVert()), ciudadesAlcanzables;
    std::vector<tCoste> minimos = Dijkstra(costes, origen, P);

    for( typename GrafoP<tCoste>::vertice i = 0; i < costes.numVert(); ++i )
        if( minimos[i] <= presupuesto )
            ciudadesAlcanzables.push_back(i);

    return ciudadesAlcanzables;
}

/*
6. Al dueño de una agencia de transportes se le plantea la siguiente situación.
La agencia de viajes ofrece distintas trayectorias combinadas entre N ciudades
españolas utilizando tren y autobús. Se dispone de dos grafos que representan
los costes (matriz de costes) de viajar entre diferentes ciudades, por un lado
en tren, y por otro en autobús (por supuesto entre las ciudades que tengan
línea directa entre ellas). Además coincide que los taxis de toda España se
encuentran en estos momentos en huelga general, lo que implica que sólo se podrá
cambiar de transporte en una ciudad determinada en la que, por casualidad,
las estaciones de tren y autobús están unidas.

Implementa una función que calcule la tarifa mínima (matriz de costes mínimos)
de viajar entre cualesquiera de las N ciudades disponiendo del grafo de costes
en autobús, del grafo de costes en tren, y de la ciudad que tiene las estaciones unidas. 
*/

struct TarifaMinima
{
    matriz<tCoste> tren, autobus, unidas;
    TarifaMinima(matriz<tCoste> t, matriz<tCoste> a, matriz<tCoste> u) : tren(t), autobus(a), unidas(u) {}
};

template <typename tCoste> TarifaMinima agenciaTransportes(const GrafoP<tCoste>& tren, const GrafoP<tCoste>& autobus, size_t N)
{
    GrafoP<tCoste> unidas(N);

    for( typename GrafoP<tCoste>::vertice i = 0; i < N; ++i )
        for( typename GrafoP<tCoste>::vertice j = 0; j < N; ++j )
            if( tren[i][j] != GrafoP<tCoste>::INFINITO && autobus[i][j] != GrafoP<tCoste>::INFINITO)
                unidas[i][j] = std::min(tren[i][j], autobus[i][j]);
            else if( tren[i][j] != GrafoP<tCoste>::INFINITO )
                unidas[i][j] = tren[i][j];
            else
                unidas[i][j] = autobus[i][j];

    matriz<typename GrafoP<tCoste>::vertice> P;
    return TarifaMinima(Floyd(tren, P), Floyd(autobus, P), Floyd(unidas, P));
}

/*
7. Se dispone de dos grafos (matriz de costes) que representan los costes de
viajar entre N ciudades españolas utilizando el tren (primer grafo) y el
autobús (segundo grafo). Ambos grafos representan viajes entre las mismas N ciudades.

Nuestro objetivo es hallar el camino de coste mínimo para viajar entre dos
ciudades concretas del grafo, origen y destino, en las siguientes condiciones:
- La ciudad origen sólo dispone de transporte por tren.
- La ciudad destino sólo dispone de transporte por autobús.
- El sector del taxi, bastante conflictivo en nuestros problemas, sigue en huelga,
  por lo que únicamente es posible cambiar de transporte en dos ciudades del grafo,
  cambio1 y cambio2, donde las estaciones de tren y autobús están unidas.

Implementa un subprograma que calcule la ruta y el coste mínimo para viajar entre
las ciudades Origen y Destino en estas condiciones. 
*/

struct RutaCambio
{
    tCoste coste;
    typename GrafoP<tCoste>::vertice ruta;
    RutaCambio(tCoste c, typename GrafoP<tCoste>::vertice r) : coste(c), ruta(r) {}
};

template <typename tCoste> RutaCambio rutaCambio(const GrafoP<tCoste>& tren, const GrafoP<tCoste>& autobus, size_t N, const typename GrafoP<tCoste>::vertice& origen, const typename GrafoP<tCoste>::vertice& destino, const typename GrafoP<tCoste>::vertice& cambio1, const typename GrafoP<tCoste>::vertice& cambio2)
{
    std::vector<typename GrafoP<tCoste>::vertice> P(N);
    std::vector<tCoste> dTren, dBus;

    //Dijsktra de origen
    dTren = Dijkstra(tren, origen, P);
    //DijsktraInv de destino
    dBus = DijkstraInv(autobus, destino, P);

    //Coger menor entre, origen + cambio1 + destino y origen + cambio2 + destino
    tCoste coste1 = dTren[cambio1] + dBus[cambio1];
    typename GrafoP<tCoste>::vertice ruta = cambio1;

    tCoste coste2 = dTren[cambio2] + dBus[cambio2];
    if( coste1 > coste2 )
    {
        coste1 = coste2;
        ruta = cambio2;
    }

    return RutaCambio(coste1, ruta);
}

/*
8.
*/
tCoste unSoloTransbordo(const GrafoP<tCoste>& tren, const GrafoP<tCoste>& bus, const typename GrafoP<tCoste>::vertice& origen, const typename GrafoP<tCoste>::vertice& destino)
{
    std::vector<typename GrafoP<tCoste>::vertice> P(tren.numVert());

    std::vector<tCoste> dijkstraTren = Dijkstra(tren, origen, P), dijkstraBus = Dijkstra(bus, origen, P);
    std::vector<tCoste> dijkstraInvTren = DijkstraInv(tren, destino, P), dijkstraInvBus = DijkstraInv(bus, destino, P);

    tCoste minTren = dijkstraTren[destino], minBus = dijkstraBus[destino], minTrenBus = GrafoP<tCoste>::INFINITO, minBusTren = GrafoP<tCoste>::INFINITO, minAux;

    for( typename GrafoP<tCoste>::vertice i = 0; i < tren.numVert(); ++i )
    {
        minAux = dijkstraTren[i] + dijkstraInvBus[i];
        
        if( minAux < minTrenBus )
            minTrenBus = minAux;
    }

    for( typename GrafoP<tCoste>::vertice i = 0; i < tren.numVert(); ++i )
    {
        minAux = dijkstraBus[i] + dijkstraInvTren[i];
        
        if( minAux < minBusTren )
            minBusTren = minAux;
    }

    return std::min(minTren, std::min(minBus, std::min(minTrenBus, minBusTren)));
}

/*
9.
*/
//Nuevo grafo Gres que guarde min(tren[i], autobus[i])
//Dijsktra para origen en Gres
//Supongo que la ciudad origen y destino están comunicadas por al menos un camino (precondiciones)
//Supongo que empiezo en tren (PORQUE EL ENUNCIADO NO DICE NADA), así que la ciudad origen siempre debe tener tren (precondiciones)
//Llevo la cuenta si estoy en tren o en bus para saber si tengo que aplicar la tarifa del taxi o no
struct CaminoCoste
{
    CaminoCoste(const tCoste& co, const typename GrafoP<tCoste>::tCamino& ca) : coste(co), camino(ca) {}
    tCoste coste;
    typename GrafoP<tCoste>::tCamino camino;
};

CaminoCoste transbordoConTaxi(const GrafoP<tCoste>& tren, const GrafoP<tCoste>& bus, const typename GrafoP<tCoste>::vertice& origen, const typename GrafoP<tCoste>::vertice& destino, const size_t N, const tCoste& taxi)
{
    GrafoP<tCoste> Gres(N);

    bool esTren = true;

    tCoste minTren, minBus;

    for( typename GrafoP<tCoste>::vertice i = 0; i < N; ++i )
    {
        for( typename GrafoP<tCoste>::vertice j = 0; j < N; ++j )
        {
            if( esTren )
            {
                minTren = tren[i][j];
                minBus = bus[i][j] + taxi;
            }
            else
            {
                minTren = tren[i][j] + taxi;
                minBus = bus[i][j];
            }

            if( minTren < minBus )
            {
                Gres[i][j] = minTren;
                esTren = true;
            }
            else
            {
                Gres[i][j] = minBus;
                esTren = false;
            }
        }
    }

    std::vector<typename GrafoP<tCoste>::vertice> P(N);

    std::vector<tCoste> dijkstraRes = Dijkstra(Gres, origen, P);

    return CaminoCoste(dijkstraRes[destino], camino<tCoste>(origen, destino, P));
}

/*
10.
*/
//Igual que el 9 pero con 3 opciones
enum Vehiculo {TREN, BUS, AVION};

CaminoCoste transbordoConTaxi(const GrafoP<tCoste>& tren, const GrafoP<tCoste>& bus, const GrafoP<tCoste>& avion, const typename GrafoP<tCoste>::vertice& origen, const typename GrafoP<tCoste>::vertice& destino, const size_t N, const tCoste& taxi, const tCoste& taxiAvion)
{
    GrafoP<tCoste> Gres(N);

    Vehiculo actual = TREN;

    tCoste minTren, minBus, minAvion;

    for( typename GrafoP<tCoste>::vertice i = 0; i < N; ++i )
    {
        for( typename GrafoP<tCoste>::vertice j = 0; j < N; ++j )
        {
            switch(actual)
            {
                case TREN:
                    minTren = tren[i][j];
                    minBus = bus[i][j] + taxi;
                    minAvion = avion[i][j] + taxiAvion;
                    break;
                case BUS:
                    minTren = tren[i][j] + taxi;
                    minBus = bus[i][j];
                    minAvion = avion[i][j] + taxiAvion;
                    break;
                case AVION:
                    minTren = tren[i][j] + taxiAvion;
                    minBus = bus[i][j] + taxiAvion;
                    minAvion = avion[i][j];
                    break;
            }

            if( minTren < minBus )
                if( minTren < minAvion )
                {
                    Gres[i][j] = minTren;
                    actual = TREN;
                }
                else
                {
                    Gres[i][j] = minAvion;
                    actual = AVION;
                }
            else
                if( minBus < minAvion )
                {
                    Gres[i][j] = minBus;
                    actual = BUS;
                }
                else
                {
                    Gres[i][j] = minAvion;
                    actual = AVION;
                }
        }
    }

    std::vector<typename GrafoP<tCoste>::vertice> P(N);

    std::vector<tCoste> dijkstraRes = Dijkstra(Gres, origen, P);

    return CaminoCoste(dijkstraRes[destino], camino<tCoste>(origen, destino, P));
}

/*
11.
*/
//PRIMERA OPCION
//Matriz de costes 3x(N1 + N2 + N3)
//Para ciudades en la misma islas se coge los costes del grafo asociado a esa isla
//Para ciudades en otra isla se suma:
//  1. origen hasta puenteOrigen
//  2. puenteOrigen hasta puenteDestino (en este caso es 0)
//  3. puenteDestino hasta destino
//Para puenteOrigen y puenteDestino se necesita hacer Dijsktra y DijsktraInv respectivamente de forma que se pueda escoger el menor coste al viajar dentro de la propia isla



//OTRA OPCION
//Matriz de costes 3x(N1 + N2 + N3)
//Se unen las tres matrices de coste en una sola
//Se marcan los puentes con coste 0 entre ambas ciudades
//Se aplica floyd

struct Puente
{
    Puente(const typename GrafoP<tCoste>::vertice& c1, const typename GrafoP<tCoste>::vertice& c2) : ciudad1(c1), ciudad2(c2) {}
    typename GrafoP<tCoste>::vertice ciudad1, ciudad2;
};

matriz<tCoste> costesMinimosHuries(const GrafoP<tCoste>& isla1, const GrafoP<tCoste>& isla2, const GrafoP<tCoste>& isla3, const size_t N1, const size_t N2, const size_t N3, const std::vector<Puente>& puentes)
{
    size_t N = N1 + N2 + N3;

    GrafoP<tCoste> Gres(N);

    matriz<typename GrafoP<tCoste>::vertice> P;

    for( typename GrafoP<tCoste>::vertice i = 0; i < N1; ++i )
        for( typename GrafoP<tCoste>::vertice j = 0; j < N1; ++j )
            Gres[i][j] = isla1[i][j];

    for( typename GrafoP<tCoste>::vertice i = 0; i < N2; ++i )
        for( typename GrafoP<tCoste>::vertice j = 0; j < N2; ++j )
            Gres[N1 + i][N1 + j] = isla1[i][j];

    for( typename GrafoP<tCoste>::vertice i = 0; i < N3; ++i )
        for( typename GrafoP<tCoste>::vertice j = 0; j < N3; ++j )
            Gres[N1 + N2 + i][ N1 + N2 + j] = isla1[i][j];

    for( Puente p : puentes )
    {
        Gres[p.ciudad1][p.ciudad2] = 0;
        Gres[p.ciudad2][p.ciudad1] = 0;
    }

    return Floyd(Gres, P);
}

/*
12.
*/
//Dijsktra para todas las ciudades costeras de cada isla
//Coger las 2 ciudades costeras (una de cada isla, obviamente) cuya suma de todos los costes mínimos dado como resultado por Dijsktra sean menores
//Escoger esas 2 ciudades costeras para el puente

tCoste sumaCostes(std::vector<tCoste> v)
{
    tCoste total;

    for( tCoste c : v )
        if( c != GrafoP<tCoste>::INFINITO )
            total += c;

    return total;
}

Puente puenteGrecoland(const GrafoP<tCoste>& isla1, const GrafoP<tCoste>& isla2, const size_t N1, const size_t N2, const std::vector<typename GrafoP<tCoste>::vertice>& C1, const std::vector<typename GrafoP<tCoste>::vertice>& C2)
{
    tCoste min1 = GrafoP<tCoste>::INFINITO, min2 = GrafoP<tCoste>::INFINITO, minAux;

    typename GrafoP<tCoste>::vertice minV1, minV2;
    
    std::vector<typename GrafoP<tCoste>::vertice> P;
    
    std::vector<tCoste> resDijkstra;
    
    for( typename GrafoP<tCoste>::vertice v : C1 )
    {
        resDijkstra = Dijkstra(isla1, v, P);

        minAux = sumaCostes(resDijkstra);
        if( minAux < min1 )
        {
            min1 = minAux;
            minV1 = v;
        }
    }
    
    for( typename GrafoP<tCoste>::vertice v : C2 )
    {
        resDijkstra = Dijkstra(isla2, v, P);

        minAux = sumaCostes(resDijkstra);
        if( minAux < min2 )
        {
            min2 = minAux;
            minV2 = v;
        }
    }

    return Puente(minV1, minV2);
}

/*
13.
*/
//PRIMERA OPCION (creo que está mal)
//Dijsktra para todas las ciudades costeras de cada isla y se cogen las 3 con menor suma de costes mínimos
//Floyd al grafo recibido y con el resultado se suma fila y columna de costes de cada ciudad costeras y nos quedamos con la menor de cada isla
//Como el grafo es dirigido es más sencillo usar Floyd y tener los costes de ir desde cualquier ciudad a la ciudad costera y de la ciudad costera al resto de ciudades (siempre dentro de la misma isla).


//OTRA OPCION
//Igual que el ejercicio 12 pero con 3 xdxdxdxdxd
std::vector<Puente> puentesHuries(const GrafoP<tCoste>& isla1, const GrafoP<tCoste>& isla2, const GrafoP<tCoste>& isla3, const size_t N1, const size_t N2, const size_t N3, const std::vector<typename GrafoP<tCoste>::vertice>& C1, const std::vector<typename GrafoP<tCoste>::vertice>& C2, const std::vector<typename GrafoP<tCoste>::vertice>& C3)
{
    tCoste min1 = GrafoP<tCoste>::INFINITO, min2 = GrafoP<tCoste>::INFINITO, min3 = GrafoP<tCoste>::INFINITO, minAux;

    typename GrafoP<tCoste>::vertice minV1, minV2, minV3;
    
    std::vector<typename GrafoP<tCoste>::vertice> P;
    
    std::vector<tCoste> resDijkstra;
    
    for( typename GrafoP<tCoste>::vertice v : C1 )
    {
        resDijkstra = Dijkstra(isla1, v, P);

        minAux = sumaCostes(resDijkstra);
        if( minAux < min1 )
        {
            min1 = minAux;
            minV1 = v;
        }
    }
    
    for( typename GrafoP<tCoste>::vertice v : C2 )
    {
        resDijkstra = Dijkstra(isla2, v, P);

        minAux = sumaCostes(resDijkstra);
        if( minAux < min2 )
        {
            min2 = minAux;
            minV2 = v;
        }
    }
    
    for( typename GrafoP<tCoste>::vertice v : C3 )
    {
        resDijkstra = Dijkstra(isla3, v, P);

        minAux = sumaCostes(resDijkstra);
        if( minAux < min3 )
        {
            min3 = minAux;
            minV3 = v;
        }
    }

    std::vector<Puente> res = {Puente(minV1, minV2), Puente(minV1, minV3), Puente(minV3, minV2)};
    return res;
}


#endif   // OPERP7_HPP