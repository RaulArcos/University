/*
Fecha.hpp By Raúl Arcos Herrera 2022
*/

#ifndef FECHA_HPP_
#define FECHA_HPP_

#include <ctime>
#include <vector>
#include <iostream>

//IMPLEMENTACIÓN DE LA CLASE FECHA
class Fecha{

    public:
        
        //Métodos constructores
        Fecha(int dia = 0, int mes = 0, int anno = 0);
        Fecha(const char* cad);
        Fecha(const Fecha& f);

        //Método Destructor
        ~Fecha();

        //Métodos observadores
        int dia();
        int mes();
        int anno();

    private:
        int dia_,mes_,anno_;

};


#endif