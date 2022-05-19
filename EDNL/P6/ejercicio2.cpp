#include <iostream>
#include <vector>

#include "../Material_Grafos/alg_grafoPMC.h"
#include "../Material_Grafos/grafoPMC.h"
#include "../Material_Grafos/matriz.h"
#include "ejercicio2.hpp"


int main(){
    typedef unsigned int tCoste;
    std::cout << "Valor coste infinito: " << GrafoP<tCoste>::INFINITO << std::endl << std::endl;
    std::cout << std::endl << "EJERCICIO 2 PRACTICA 6" << std::endl << std::endl;

    GrafoP<tCoste> G("grafoPMC.dat");
    std::cout << G << std::endl;

    std::cout << "EJERCICIO 2 PRACTICA 6" << std::endl;
   
    std::cout <<"El vertice pseudocentro es: " << pseudocentro(G) << std::endl;
    


}