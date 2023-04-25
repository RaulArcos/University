/*
articulo.hpp By Raúl Arcos Herrera 2023
*/

#ifndef ARTICULO_HPP_
#define ARTICULO_HPP_

#include "../P1/fecha.hpp"  
#include "../P1/cadena.hpp"
#include <set>

//CLASE ARTICULO
class Articulo{
    public:  

        //Método constructor
        Articulo(const Cadena &referencia, const Cadena& titulo, const Fecha& fecha, const double precio, const unsigned existencia);

        //Métodos observadores
        Cadena titulo() const{ return titulo_; }  //Devuelve el titulo
        Cadena referencia() const{return referencia_; } //Devuelve la referencia
        Fecha f_publi() const{ return fecha_; } //Devuelve la fecha de subida
        double precio() const{ return precio_; } //Devuelve el precio del articulo
        unsigned stock() const{ return existencias_; } //Devuelve el numero de existencias en stock
        double& precio(){ return precio_; }
        unsigned& stock(){ return existencias_; }
        
        //Métodos virtuales
        virtual ~Articulo() {}

    private:
        
        //Declaramos las variables que contiene nuestra clase artículo.
        Cadena referencia_,titulo_;
        Fecha fecha_;
        double precio_;
        unsigned existencias_;

};

std::ostream& operator << (std::ostream &os, const Articulo &a) noexcept;

#endif