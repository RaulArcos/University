//pedido-articulo.cpp Raúl Arcos Herrera.

#include <iomanip>
#include <ostream>
#include "pedido-articulo.hpp"

//CLASE LINEA PEDIDO
//Constructor
LineaPedido::LineaPedido(double precio, int cant):cantidad_(cant),precio_venta_(precio)
{

};

//Sobrecarga del flujo de salida
ostream& operator <<(ostream& salida, const LineaPedido& lp)
{   
    salida << fixed << setprecision(2) << lp.precio_venta() << " " << "€" << "\t" << lp.cantidad();
    return salida;
}


//CLASE PEDIDO ARTICULO

//No requiere metodo constructor.
//Método pedido (Ambas direcciones)
void Pedido_Articulo::pedir(Pedido& ped, Articulo& art,double precio, int cant)
{
    A_P_[&art].insert(make_pair(&ped,LineaPedido(precio,cant))) ;
    P_A_[&ped].insert(make_pair(&art,LineaPedido(precio,cant))) ;
}


void Pedido_Articulo::pedir(Articulo& art,Pedido& ped,double precio, int cant)
{
    pedir(ped,art,precio,cant) ;
}

//Método detalle y ventas
Pedido_Articulo::ItemsPedido& Pedido_Articulo::detalle(Pedido& ped)
{
    return P_A_[&ped] ;
}
Pedido_Articulo::Pedidos Pedido_Articulo::ventas(Articulo& art)
{
    return A_P_[&art] ;
}

//Método MostarDetallePedidos y mostrarVentasArtículos
ostream& Pedido_Articulo::mostrarDetallePedidos(std::ostream& salida)
{   
    double total; //Suma del precio total del pedido
    
    for(auto i = P_A_.begin(); i != P_A_.end(); i++)
    {
        salida << "Pedido núm." << (i->first)->numero() << "\t" << "\n" << "Cliente: "
        << i->first->tarjeta()->titular()->nombre() << "\t" << "\n" << "Fecha: " << 
        i->first->fecha() << i->second;

        total = i->first->total() + total;
    }

    salida << fixed << "TOTAL VENTAS: " << setprecision(2) << total << " €" << endl;
    return salida;

}

ostream& Pedido_Articulo::mostrarVentasArticulos(std::ostream& salida)
{
    for(auto i = A_P_.begin(); i != A_P_.end(); i++)
    {
        salida << "Ventas" << "[" << (i->first)->referencia() << "]" <<
        "\n" << "\"" << i->first->titulo() << "\"" <<
        "\n" << i->second << std::endl ;
    }

    return salida;
}

//Sobrecarga de los operadores de salida de flujo para Itemspedido y Articulo
ostream& operator <<(ostream& salida,const Pedido_Articulo::ItemsPedido& ip)
{

    double total = 0;

    salida << "\n" << "PVP \t Cant.\t Articulo\n" 
    << "=================================================================="<< endl ;

    for(auto i = ip.begin(); i != ip.end() ; i++)
    {

        salida << (i->second).precio_venta() << "€\t" << "\n"
        << (i->second).cantidad() << "\t" << "\n"
        << "[ "<< (i->first)->referencia() << "]\t" << "\n"
        << "\"" << (i->first)->titulo() << "\"" << endl;

        total = total + (i->second).cantidad() * (i->second).precio_venta() ;
    }

    salida << "==================================================================" << endl;
    salida << std::fixed ;
    salida << std::setprecision(2) << total << " €" << std::endl ;

    return salida ;
}
/*
ostream& operator <<(ostream& salida, const Pedido_Articulo::Pedidos& pa)
{

    double total = 0;
    unsigned t = 0  ;

    salida << "\n" << "[Pedidos: " << pa.size() << "]"
    << "\n" << "==================================================================" << endl
    << "\n" << "PVP \t Cant.\t Fecha venta\n" 
    << "\n" << "=================================================================="<< endl; 

    for(auto i = pa.begin(); i != pa.end() ; i++)
    {

        salida << " " << (i->second).precio_venta() << " €\t" <<
        "\n" << (i->second).cantidad() << "\t"  <<
        "\n" << (i->first)->fecha() << endl ;

        total = total + (i->second).cantidad() * (i->second).precio_venta() ;
        t += (i->second).cantidad() ;
    }


    salida  << "=================================================================="<< endl; 
    salida << fixed ;
    salida << setprecision(2) << total << " €\t" << t << endl ;

    return salida;

}
*/
std::ostream& operator <<(std::ostream& outputBuffer , const Pedido_Articulo::Pedidos& pedidosDado) 
{

    double contadorPrecioTotal = 0;
    unsigned cantidadAuxiliar = 0  ;

    outputBuffer << "\n" ;
    outputBuffer << std::setw(40) << std::setfill('=') << '\n' << std::setfill(' ') << std::endl ;
    outputBuffer << "PVP \t Cant.\t Fecha venta\n" ;
    outputBuffer << std::setw(40) << std::setfill('=') << '\n' << std::setfill(' ') << std::endl ;

    for(auto i = pedidosDado.begin(); i != pedidosDado.end() ; i++)
    {

        outputBuffer << " " << (i->second).precio_venta() << " €    ";
        outputBuffer << (i->second).cantidad() << "\t" ;
        outputBuffer << (i->first)->fecha() << std::endl ;
        contadorPrecioTotal = contadorPrecioTotal + (i->second).cantidad() * (i->second).precio_venta() ;
        cantidadAuxiliar += (i->second).cantidad() ;
    }

    outputBuffer << std::setw(40) << std::setfill('=') << '\n' << std::setfill(' ') << std::endl ;
    outputBuffer << std::fixed << std::setprecision(2) << contadorPrecioTotal << " €\t" << cantidadAuxiliar << std::endl ;

    return outputBuffer ;

}

// Funciones de las clases de ordenacion
bool OrdenaPedidos::operator()(const Pedido* pedido1 , const Pedido* pedido2) const  
{

    return pedido1->numero() < pedido2->numero() ;

}

bool OrdenaArticulos::operator()(const Articulo* articulo1 , const Articulo* articulo2) const 
{

    return articulo1->referencia() < articulo2->referencia() ;

}
