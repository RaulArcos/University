/******************************************
* articulo.cpp By Raúl Arcos Herrera 2022 *
*******************************************/

#include "articulo.hpp"
#include <ostream>
#include <iomanip>

// Constructor
Articulo::Articulo(const Autores& autores, const Cadena& ref , const Cadena& titulo , const Fecha& f , const double precio):
referencia_(ref),titulo_(titulo),autores_(autores),fecha_(f),precio_(precio){} 

//Sobrecarga del operador de flujo
std::ostream& operator <<(std::ostream& salida , const Articulo& a) noexcept{
    salida << "[" << a.referencia() << "] \"" << a.titulo() << "\", de ";

    auto aux = a.autores().begin() ; 
    salida << (*aux)->apellidos();

    for(++aux; aux != a.autores().end(); ++aux)
        salida << ", " << (*aux)->apellidos();

    salida << ". ";
    unsigned anno = a.f_publi().anno() ; 
    salida << anno << ". " << std::fixed << std::setprecision(2) << a.precio() << " €" << std::endl ; 
    salida << "\t" ; 
    a.impresion_especifica(salida) ; 
    return salida ;
}

//Método impresion_especifica
void Libro::impresion_especifica(std::ostream& salida) const noexcept{
    salida << n_pag_ << " págs., " << stock_ << " unidades.";
} 
void Cederron::impresion_especifica(std::ostream& salida) const noexcept{
    salida << tam_ << " MB, " << stock_ << " unidades.";
} 
void LibroDigital::impresion_especifica(std::ostream& salida) const noexcept{
    salida << "A la venta hasta el " << f_expir_ << '.';
} 
