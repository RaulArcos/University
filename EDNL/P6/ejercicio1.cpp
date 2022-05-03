#include <iostream>
#include <vector>

#include "../Material_Grafos/alg_grafoPMC.h"
#include "../Material_Grafos/grafoPMC.h"
#include "../Material_Grafos/matriz.h"

int main(){
    typedef unsigned int tCoste;
    std::cout << "Valor coste infinito: " << GrafoP<tCoste>::INFINITO << std::endl << std::endl;
    std::cout << std::endl << "EJERCICIO 1 PRACTICA 6" << std::endl << std::endl;

    GrafoP<tCoste> G("grafoPMC.dat");
    std::cout << G << std::endl;

    GrafoP<tCoste>::vertice destino = 0;
    std::vector<GrafoP<tCoste>::vertice> PInv(G.numVert(), 0);

    std::vector<tCoste> costesInv = DijkstraInv(G, destino, PInv);
        std::cout << std::endl << "El resultado de Dijkstra inverso es:" << std::endl;
        std::cout << "Coste\t|\tVertice" << std::endl;

    for( int i = 0; i < G.numVert(); ++i )
        if( costesInv[i] != GrafoP<tCoste>::INFINITO )
            std::cout << costesInv[i] << "\t|\t" << i << std::endl;
        else
            std::cout << "INF\t|\t" << i << std::endl;
}