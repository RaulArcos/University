/************************************************
* usuario-pedido.cpp By Raúl Arcos Herrera 2022 *
*************************************************/

#include <iomanip>
#include <ostream>
#include "usuario-pedido.hpp"

//CLASE USUARIO-PEDIDO
//Metodo asocia
void Usuario_Pedido::asocia(Pedido &p, Usuario &user){
    up_[&user].insert(&p);
    pu_[&p] = &user;
}

void Usuario_Pedido::asocia(Usuario &user, Pedido &p){
    return asocia(p,user);
}
