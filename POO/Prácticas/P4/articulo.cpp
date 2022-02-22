//Articulo cpp Raúl Arcos Herrera
#include "articulo.hpp"
#include <ostream>
#include <iomanip>

// Constructor
Articulo::Articulo( const Autores& autores , const Cadena& ref , const Cadena& titulo , const Fecha& f , const double precio):
autores_(autores), referencia_(ref),titulo_(titulo),fecha_(f), precio_(precio)
{
    if ( autores_.empty() )
    {
        throw Autores_vacios() ;
    }
} ; 

//Sobrecarga del operador de flujo
std::ostream& operator <<(std::ostream& salida , const Articulo& a) noexcept
{

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
void Libro::impresion_especifica(std::ostream& salida) const noexcept
{

    salida << n_pag() << " págs., " << stock() << " unidades.";

} 

void Cederron::impresion_especifica(std::ostream& salida) const noexcept
{

    salida << tam() << " MB, " << stock() << " unidades.";

} 

void LibroDigital::impresion_especifica(std::ostream& salida) const noexcept
{

    salida << "A la venta hasta el " << f_expir() << '.';

} 