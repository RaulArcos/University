#include <iostream>
#include <vector>
#include <algorithm>

#include "../Material_Grafos/alg_grafoPMC.h"
#include "../Material_Grafos/grafoPMC.h"
#include "../Material_Grafos/matriz.h"


/*
2. Definiremos el pseudocentro de un grafo conexo como el nodo del mismo que minimiza 
la suma de las distancias mínimas a sus dos nodos más alejados. Definiremos el diámetro 
del grafo como la suma de las distancias mínimas a los dos nodos más alejados del 
pseudocentro del grafo.  Dado un grafo conexo representado mediante matriz de costes, 
implementa un subprograma que devuelva la longitud de su diámetro. 
*/

template <typename tCoste>
tCoste suma2MasAlejados(std::vector<tCoste> C){
    
    tCoste sumaCostes = 0;

    typename std::vector<tCoste>::iterator iMax = max_element(C.begin(), C.end());
    if( iMax != C.end() )
        sumaCostes += *iMax;

    C.erase(iMax);

    iMax = max_element(C.begin(), C.end());
    if( iMax != C.end() )
        sumaCostes += *iMax;
    
    return sumaCostes;
}

template <typename tCoste>
typename GrafoP<tCoste>::vertice pseudocentro(const GrafoP<tCoste>& G){
    typename GrafoP<tCoste>::vertice verticeMin = 0;
    tCoste costeMin = GrafoP<tCoste>::INFINITO;
    
    tCoste sumaCostes;
    
    std::vector<tCoste> costes(G.numVert());
    std::vector<typename GrafoP<tCoste>::vertice> P(G.numVert());
    for( size_t i = 0; i < G.numVert(); ++i )
    {
        sumaCostes = 0;
        costes = Dijkstra(G, i, P);
        
        sumaCostes = suma2MasAlejados(costes);
        
        if( costeMin > sumaCostes )
        {
            verticeMin = i;
            costeMin = sumaCostes;
        }
    }

    return verticeMin;
}


template <typename tCoste>
typename GrafoP<tCoste>::vertice pseudocentro(const GrafoP<tCoste>& G){

    typedef typename GrafoP<tCoste>::vertice vertice;
    vertice pseudocentroRetorno;
    vector<tCoste> vectorCosteMin;
    tCoste costeMin;
    tCoste suma;
    vector<typename GrafoP<tCoste>::vertice> P(G.numVert());

    for(size_t i = 0; i < G.numVert(); ++i){
        vectorCosteMin = Dijkstra(G,i,P);
        suma = suma2MasAlejados2(vectorCosteMin);
        if(suma < costeMin)
            costeMin = suma;
            pseudocentroRetorno = i;
    }
    return pseudocentroRetorno;
}


template <typename tCoste>
tCoste suma2MasAlejados2(const vector<tCoste> costes){
    
     tCoste sumaCostes = 0;

    typename std::vector<tCoste>::iterator iMax = max_element(C.begin(), C.end());
    if( iMax != C.end() )
        sumaCostes += iMax;

    C.erase(iMax);

    iMax = max_element(C.begin(), C.end());
    if( iMax != C.end() )
        sumaCostes += iMax;
    
    return sumaCostes;
}