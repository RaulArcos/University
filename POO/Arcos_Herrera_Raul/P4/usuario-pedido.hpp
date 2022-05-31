//usuario-pedido.hpp Raúl Arcos Herrera.

#ifndef USUARIO_PEDIDO_H_
#define USUARIO_PEDIDO_H_

#include <map>
#include <set>
#include <utility>
#include "pedido.hpp"
#include "usuario.hpp"

class Pedido ; 

class Usuario_Pedido
{
    public:
        typedef std::set<Pedido*> Pedidos;

        //Sobrecargamos el metodo asocia
        void asocia(Pedido& ped, Usuario& usuario);
        void asocia(Usuario& usuario, Pedido& ped);

        //metodo pedidos
        Pedidos pedidos(Usuario& usuario){return up_[&usuario];}
        Usuario* cliente(Pedido& ped){return pu_[&ped];}

    private:
        std::map<Usuario*, Pedidos> up_;
        std::map<Pedido*, Usuario*> pu_;
};
#endif