/*
articulo.hpp By Raúl Arcos Herrera 2022
*/

#ifndef ARTICULO_HPP_
#define ARTICULO_HPP_

#include "../P1/fecha.hpp"  
#include "../P1/cadena.hpp"
#include <set>

//CLASE AUTOR

class Autor
{
    public:
        //Constructor
        Autor( const Cadena& nom ,  const Cadena& ape ,  const Cadena& dir) noexcept
        :nombre_(nom),apellidos_(ape),direccion_(dir){};

        //Métodos Observadores
        const Cadena& direccion() const noexcept {return direccion_;} ; 
        const Cadena& nombre() const noexcept{return nombre_;} ; 
        const Cadena& apellidos() const noexcept{return apellidos_;} ; 

    private:
        //Atributos
        Cadena nombre_;
        Cadena apellidos_;
        Cadena direccion_;
};

//CLASE ARTICULO
class Articulo{
    public:  

        //Coleccion de Autores
        typedef std::set<Autor*> Autores ; 

        //Método constructor
        Articulo(const Autores& autor, const Cadena &referencia, const Cadena& titulo, const Fecha& fecha, const double precio);

        //Métodos observadores
        Cadena titulo() const{ return titulo_; }  //Devuelve el titulo
        Cadena referencia() const{return referencia_; } //Devuelve la referencia
        Fecha f_publi() const{ return fecha_; } //Devuelve la fecha de subida
        double precio() const{ return precio_; } //Devuelve el precio del articulo
        unsigned stock() const{ return existencias_; } //Devuelve el numero de existencias en stock
        double& precio(){ return precio_; }
        unsigned& stock(){ return existencias_; }
        const Autores& autores() const {return autores_;}

        class Autores_vacios{};

        //Métodos virtuales
        virtual ~Articulo() {}
        virtual void impresion_especifica(std::ostream& salida) const noexcept = 0;

    private:
        
        //Declaramos las variables que contiene nuestra clase artículo.
        Cadena referencia_,titulo_;
        Autores autores_ ; 
        Fecha fecha_;
        double precio_;
        unsigned existencias_;

};


class ArticuloAlmacenable : public Articulo{
public:

    ArticuloAlmacenable(const Autores& autor, const Cadena& ref, const Cadena& tit, const Fecha& f, double p,unsigned stock)
        : Articulo(autor, ref, tit, f, p), stock_(stock) {}

    unsigned stock() const noexcept { return stock_; }
	unsigned& stock() noexcept { return stock_;}

protected:
    unsigned stock_;
};

class Libro : public ArticuloAlmacenable{
public:
   Libro(const Autores& autores, const Cadena& ref, const Cadena& tit,const Fecha& fp,
		   double price, unsigned npag, unsigned stock = 0):
			 ArticuloAlmacenable(autores,ref,tit,fp,price,stock),n_pag_(npag) {}

    unsigned n_pag() const noexcept { return n_pag_; }
    void impresion_especifica(std::ostream& os) const noexcept;

private:
    const unsigned n_pag_;
};

class Cederron : public ArticuloAlmacenable{
public:
  Cederron(const Autores& a, const Cadena& c, const Cadena& t, const Fecha& f, double p, unsigned MB, unsigned stock)
    : ArticuloAlmacenable(a, c, t, f, p, stock), tam_(MB) {}
  
  unsigned tam() const noexcept { return tam_; }
  void impresion_especifica(std::ostream& os) const noexcept;

private:
  const unsigned tam_;
  
  
};

class LibroDigital : public Articulo{
public:
    LibroDigital(const Autores& a, const Cadena& c, const Cadena& t, const Fecha& fComp, double p, const Fecha& fExp)
        : Articulo(a, c, t, fComp, p), f_expir_(fExp) {}

    const Fecha& f_expir() const noexcept { return f_expir_; }
    void impresion_especifica(std::ostream& os) const noexcept;

private:
    const Fecha f_expir_;
    
};

std::ostream& operator << (std::ostream &os, const Articulo &a) noexcept;

#endif