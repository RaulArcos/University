//Pedido hpp Raúl Arcos Herrera

#ifndef PEDIDO_HPP_
#define PEDIDO_HPP_

#include <iostream>
#include <utility>
#include <iomanip>

#include <iomanip>
#include <iostream>
#include <ostream>

#include "usuario-pedido.hpp"
#include "pedido-articulo.hpp"
#include "usuario.hpp"
#include "tarjeta.hpp"

class Usuario_Pedido;
class Pedido_Articulo;

//CLASE PEDIDO
class Pedido
{

public:
    
    //Metodo constructor
    Pedido(Usuario_Pedido& uspe, Pedido_Articulo& pear, Usuario& us, const Tarjeta& tar, const Fecha& f = Fecha());

    //Metodos observadores
    int numero() const {return num_;};
    double total() const {return importe_total_;};
    static int n_total_pedidos() {return num_pedidos_;}; 
    Fecha fecha() const {return fecha_pedido_;};
    const Tarjeta* tarjeta() const {return tarjeta_;};

    //Clase Impostor
    class Impostor{
    public:
        Impostor(Usuario& u): usu_(&u) {}
        Usuario& usuario() const {return *usu_;};
    private:
        Usuario* usu_;
    };

    //Clase Pedido::SinStock
    class SinStock{
    public:
        SinStock(Articulo* a):articulo_(a) {}
        Articulo& articulo() const { return *articulo_ ;} ;
    private:
        Articulo* articulo_ ;
    };

    class Vacio{
    public:
        Vacio(Usuario& u): usu_(&u) {}
        Usuario& usuario() const {return *usu_;};
    private:
        Usuario* usu_;
    };


private:
    int num_;
    const Tarjeta* tarjeta_;
    Fecha fecha_pedido_;
    double importe_total_;
    static int num_pedidos_;
};

ostream& operator <<(ostream& salida, const Pedido& p);

#endif