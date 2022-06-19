#include <iostream>
#include <vector>
#include <algorithm>

#include "../Material_Grafos/alg_grafoPMC.h"
#include "../Material_Grafos/grafoPMC.h"
#include "../Material_Grafos/matriz.h"


template <typename tCoste>
matriz <tCoste> viajeZue(const GrafoP<tCoste>& G, const std::vector<bool>& tomadas, 
const matriz<bool>& cortada,const typename GrafoP<tCoste>::vertice& capital){

    std::vector<tCoste> resdis;
    std::vector<tCoste> resdisinv;
    std::vector<typename GrafoP<tCoste>::vertice> P;

    for(size_t i = 0; i < G.numVert(); ++i){
        for(size_t j = 0; j < G.numVert(); ++i){
            if(cortada[i][j])
                G[i][j] = GrafoP<tCoste>::INFINITO;
            if(tomadas[i])
                G[i][j]= G[j][i] = GrafoP<tCoste>::INFINITO
        }
    }

    resdis = Dijkstra(G,capital,P);
    resdisinv = DijkstraInv(G,capital,P);

    for(size_t i = 0; i < G.numVert(); ++i)
        for(size_t j = 0; j < G.numVert; ++j)
            G[i][j] = suma(resdis[i],resdisinv[j]);
 
    return G;
}
