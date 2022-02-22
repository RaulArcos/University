//pedido.cpp Raúl Arcos Herrera

#include "pedido.hpp"
#include "tarjeta.hpp"
#include "usuario-pedido.hpp"
#include "pedido-articulo.hpp"
#include <iostream>
#include <iomanip>
#include "../P1/cadena.hpp"
#include "../P1/fecha.hpp"

//Comenzamos con numero de pedidos a 0
int Pedido::num_pedidos_ = 0;

Pedido::Pedido(Usuario_Pedido& uspe, Pedido_Articulo& pear, Usuario& us, const Tarjeta& tar, const Fecha& f):
num_(num_pedidos_+ 1),tarjeta_(&tar),fecha_pedido_(f),importe_total_(0)
{
    //Excepciones:
    //La caducidad de la tarjeta es menor a la fecha actual,el usuario es dueño de la tarjeta
    //y la tarjeta está activa.
    if(tar.caducidad() < f ){ throw Tarjeta::Caducada(tar.caducidad());}
    if(tar.titular() != &us){ throw  Impostor(us);}
    if(tar.activa() != true){ throw Tarjeta::Desactivada();} 
    //El usuario no tiene articulos en el pedido.
    if(us.n_articulos() == 0){ throw Vacio(us);}

auto aux = us.compra();
    
    for(auto i : aux)
    {
        if(ArticuloAlmacenable* aa = dynamic_cast<ArticuloAlmacenable*>(i.first))
        {
            if(aa->stock() < i.second)
            {
                const_cast<Usuario::Articulos&>(us.compra()).clear();
                throw Pedido::SinStock(i.first);
            }
        } else if(LibroDigital* ld = dynamic_cast<LibroDigital*>(i.first))
        {
            if(ld->f_expir() < Fecha()){
                us.compra(*i.first, 0);
                if(us.n_articulos() == 0)
                {
                    throw Vacio(us);
                }
            }
        }
    }
    uspe.asocia(us, *this);
    aux = us.compra();

    for(auto j : aux)
        {
            pear.pedir(*this, *j.first, (j.first)->precio(), j.second);
            us.compra(*j.first, 0);
            importe_total_ +=  (j.first)->precio() * j.second;

            if(ArticuloAlmacenable *aa = dynamic_cast<ArticuloAlmacenable*>(j.first))
                aa->stock() -= j.second;
        }

    ++num_pedidos_;
}
ostream& operator <<(std::ostream& salida, const Pedido& ped)
{
    salida << "Núm. pedido: " << ped.numero() << "\n" << "Fecha:       " << ped.fecha() << 
    "\n" << "Pagado con:  " << ped.tarjeta()->tipo() << " n.º: " << ped.tarjeta()->numero() <<
    "\n" << "Importe: " << fixed << setprecision(2) << ped.total() << " €" << endl;
    salida << "Tipo indeterminado" << endl ;

    return salida;
}