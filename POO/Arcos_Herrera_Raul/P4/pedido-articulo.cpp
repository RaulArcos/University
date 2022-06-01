/*************************************************
* pedido-articulo.cpp By Raúl Arcos Herrera 2022 *
**************************************************/

#include <iomanip>
#include <ostream>
#include "pedido-articulo.hpp"

//Sobrecarga del flujo de salida
std::ostream& operator <<(std::ostream& salida, const LineaPedido& lp){   
    salida << std::fixed << std::setprecision(2) << lp.precio_venta() << " " << "€" << "\t" << lp.cantidad();
    return salida;
}


//CLASE PEDIDO ARTICULO

//No requiere metodo constructor.
//Método pedido (Ambas direcciones)
void Pedido_Articulo::pedir(Pedido& ped, Articulo& art,double precio, unsigned cant){
    A_P_[&art].insert(std::make_pair(&ped,LineaPedido(precio,cant))) ;
    P_A_[&ped].insert(std::make_pair(&art,LineaPedido(precio,cant))) ;
}

//Método detalle y ventas
Pedido_Articulo::ItemsPedido& Pedido_Articulo::detalle(Pedido& ped){
    return P_A_[&ped] ;
}
Pedido_Articulo::Pedidos Pedido_Articulo::ventas(Articulo& art){
    return A_P_[&art] ;
}

//Método MostarDetallePedidos y mostrarVentasArtículos
std::ostream& Pedido_Articulo::mostrarDetallePedidos(std::ostream& salida){   
    double total=0; //Suma del precio total del pedido
    
    for(auto i = P_A_.begin(); i != P_A_.end(); i++){
        salida << "Pedido núm." << (i->first)->numero() << "\t" << "\n" << "Cliente: "
        << i->first->tarjeta()->titular()->nombre() << "\t" << "\n" << "Fecha: " << 
        i->first->fecha() << i->second;

        total = i->first->total() + total;
    }

    salida << std::fixed << "TOTAL VENTAS: " << std::setprecision(2) << total << " €" << std::endl;
    return salida;
}

std::ostream& Pedido_Articulo::mostrarVentasArticulos(std::ostream& salida){
    for(auto i = A_P_.begin(); i != A_P_.end(); i++)
        salida << "Ventas" << "[" << (i->first)->referencia() << "]" <<
        "\n" << "\"" << i->first->titulo() << "\"" <<
        "\n" << i->second << std::endl ;

    return salida;
}

//Sobrecarga de los operadores de salida de flujo para Itemspedido y Articulo
std::ostream& operator <<(std::ostream& salida,const Pedido_Articulo::ItemsPedido& ip){
    double total = 0;

    salida << "\n" << "PVP \t Cant.\t Articulo\n" 
    << "=================================================================="<< std::endl ;

    for(auto i = ip.begin(); i != ip.end() ; i++){
        salida << (i->second).precio_venta() << "€\t" << "\n"
        << (i->second).cantidad() << "\t" << "\n"
        << "[ "<< (i->first)->referencia() << "]\t" << "\n"
        << "\"" << (i->first)->titulo() << "\"" << std::endl;

        total = total + (i->second).cantidad() * (i->second).precio_venta() ;
    }

    salida << "==================================================================" << std::endl;
    salida << std::fixed ;
    salida << std::setprecision(2) << total << " €" << std::endl ;

    return salida ;
}
std::ostream& operator <<(std::ostream& outputBuffer , const Pedido_Articulo::Pedidos& pedidosDado) {
    double contadorPrecioTotal = 0;
    unsigned cantidadAuxiliar = 0  ;

    outputBuffer << "\n" << std::setw(40) << std::setfill('=') << '\n' << std::setfill(' ') << std::endl 
    << "PVP \t Cant.\t Fecha venta\n" << std::setw(40) << std::setfill('=') << '\n' << std::setfill(' ') << std::endl ;

    for(auto i = pedidosDado.begin(); i != pedidosDado.end() ; i++){

        outputBuffer << " " << (i->second).precio_venta() << " €    "
        << (i->second).cantidad() << "\t" 
        << (i->first)->fecha() << std::endl ;
        contadorPrecioTotal = contadorPrecioTotal + (i->second).cantidad() * (i->second).precio_venta() ;
        cantidadAuxiliar += (i->second).cantidad() ;
    }

    outputBuffer << std::setw(40) << std::setfill('=') << '\n' << std::setfill(' ') << std::endl 
    << std::fixed << std::setprecision(2) << contadorPrecioTotal << " €\t" << cantidadAuxiliar << std::endl ;

    return outputBuffer ;
}

// Funciones de las clases de ordenacion
bool OrdenaPedidos::operator()(const Pedido* pedido1 , const Pedido* pedido2) const  {
    return pedido1->numero() < pedido2->numero() ;
}

bool OrdenaArticulos::operator()(const Articulo* articulo1 , const Articulo* articulo2) const {
    return articulo1->referencia() < articulo2->referencia() ;
}
