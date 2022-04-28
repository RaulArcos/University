/*
articulo.cpp By Raúl Arcos Herrera 2022
*/

#include "articulo.hpp"
#include <ostream>
#include <iomanip>

// Constructor
Articulo::Articulo(const Cadena& ref , const Cadena& titulo , const Fecha& f , const double precio, const unsigned existencias):
referencia_(ref),titulo_(titulo),fecha_(f), precio_(precio), existencias_(existencias){} 

//Sobrecarga del operador de flujo
std::ostream& operator <<(std::ostream& salida , const Articulo& a) noexcept{

    salida << "[" << a.referencia() << "] \"" << a.titulo() << "\", de ";

    return salida ;
}