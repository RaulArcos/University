//pedido-articulo hpp Raúl Arcos Herrera

#ifndef PEDIDO_ARTICULO_HPP_
#define PEDIDO_ARTICULO_HPP_

#include "articulo.hpp"
#include "pedido.hpp"
#include <utility>
#include <map>


class Pedido;
// Clases de Objeto Funcion 
class OrdenaPedidos: public std::binary_function <Pedido* , Pedido* , bool> {
    public : 
        bool operator()(const Pedido* pedido1 , const Pedido* pedido2) const  ; 
};
class OrdenaArticulos: public std::binary_function <Articulo* , Articulo* , bool>{
    public : 
        bool operator()(const Articulo* articulo1 , const Articulo* articulo2) const ;
};


//CLASE LINEA-PEDIDO
class LineaPedido{
    public:
        //Metodo constructor
        explicit LineaPedido(double precio, int cant = 1):cantidad_(cant),precio_venta_(precio){}
        
        //Metodo observador
        unsigned cantidad() const {return cantidad_;};
        double precio_venta() const {return precio_venta_;};

    private:
        //Parámetros
        unsigned cantidad_;
        double precio_venta_;
};

//Operador de inserción
std::ostream& operator << (std::ostream& salida, const LineaPedido& lineapedido);

//CLASE PEDIDO-ARTÍCULO
class Pedido_Articulo{
    public:
        //Asociación en sentido Inverso bidireccional
        typedef std::map <Articulo*, LineaPedido, OrdenaArticulos> ItemsPedido ;
        typedef std::map <Pedido*, LineaPedido, OrdenaPedidos > Pedidos ;

        //Método pedir
        void pedir(Pedido& ped,Articulo& art,double precio, int cant);
        //Sobrecarga del método pedir
        void pedir(Articulo& art,Pedido& ped,double precio, int cant);

        //Método detalle
        ItemsPedido& detalle(Pedido& ped);

        //Método ventas
        Pedidos ventas(Articulo& a);

        //Métodos para imprimir en el flujo de salida
        std::ostream& mostrarDetallePedidos(std::ostream& salida);
        std::ostream& mostrarVentasArticulos(std::ostream& salida);
    private:
        //Asociación bidireccional
        std::map<Articulo*, Pedidos, OrdenaArticulos> A_P_;
        std::map<Pedido*, ItemsPedido, OrdenaPedidos> P_A_;
        

};
//Sobrecargamos los operadores de flujo de salida
std::ostream& operator <<(std::ostream& salida, const Pedido_Articulo::ItemsPedido& ip) ;
std::ostream& operator <<(std::ostream& salida, const Pedido_Articulo::Pedidos& p) ;




#endif

