//pedido-articulo hpp Raúl Arcos Herrera

#ifndef PEDIDO_ARTICULO_HPP_
#define PEDIDO_ARTICULO_HPP_

#include "articulo.hpp"
#include "pedido.hpp"
#include <utility>
#include <map>

using namespace std;
class Pedido;
class OrdenaPedidos: public std::binary_function <Pedido* , Pedido* , bool> 
{

    public : 

        bool operator()(const Pedido* pedido1 , const Pedido* pedido2) const  ; 

} ;

// Clases de Objeto Funcion 
class OrdenaArticulos: public std::binary_function <Articulo* , Articulo* , bool>
{

    public : 

        bool operator()(const Articulo* articulo1 , const Articulo* articulo2) const ;

} ;
//CLASE LINEA-PEDIDO
class LineaPedido
{
    public:
        //Metodo constructor
        explicit LineaPedido(double precio, int cant = 1);
        
        //Metodo observador
        unsigned cantidad() const {return cantidad_;};
        double precio_venta() const {return precio_venta_;};

    private:
        //Parámetros
        unsigned cantidad_;
        double precio_venta_;
};

//Operador de inserción
ostream& operator << (ostream& salida, const LineaPedido& lineapedido);

//CLASE PEDIDO-ARTÍCULO
class Pedido_Articulo
{

    public:
        //Asociación en sentido Inverso bidireccional
        typedef map <Articulo*, LineaPedido, OrdenaArticulos> ItemsPedido ;
        typedef map <Pedido*, LineaPedido, OrdenaPedidos > Pedidos ;

        //Método pedir
        void pedir(Pedido& ped,Articulo& art,double precio, int cant);
        //Sobrecarga del método pedir
        void pedir(Articulo& art,Pedido& ped,double precio, int cant);

        //Método detalle
        ItemsPedido& detalle(Pedido& ped);

        //Método ventas
        Pedidos ventas(Articulo& a);

        //;étodos para imprimir en el flujo de salida
        ostream& mostrarDetallePedidos(std::ostream& salida);
        ostream& mostrarVentasArticulos(std::ostream& salida);


    private:
        //Asociación bidireccional
        map<Articulo*, Pedidos, OrdenaArticulos> A_P_;
        map<Pedido*, ItemsPedido, OrdenaPedidos> P_A_;
        

};
//Sobrecargamos los operadores de flujo de salida
ostream& operator <<(std::ostream& salida, const Pedido_Articulo::ItemsPedido& ip) ;
ostream& operator <<(std::ostream& salida, const Pedido_Articulo::Pedidos& p) ;




#endif

