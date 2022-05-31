/*
usuario.hpp By Raúl Arcos Herrera 2022
*/
#ifndef USUARIO_HPP_
#define USUARIO_HPP_

#include "../P1/cadena.hpp"
#include "tarjeta.hpp"
#include "articulo.hpp"

#include <map>
#include <unordered_map>
#include <unordered_set>

class Numero;
class Tarjeta;

//CLASE CLAVE
class Clave{
    
    public:

        //Método contructor
        Clave(const char*);
        //Método observador
        const Cadena& clave()const{return claveCifrada_;}
        
        //Métodos de la clase
        enum Razon{CORTA,ERROR_CRYPT};
        bool verifica(const char*)const;

        class Incorrecta{       
            
            public:
                Incorrecta(const Razon r_):r(r_){};
                Razon razon()const{return r;}  

            private:
                Razon r; 
        };

    private:

        Cadena claveCifrada_;
};

//CLASE USUARIO
class Usuario{
    
    public:
        
        //relaciones de la clase
        typedef std::map<Numero,Tarjeta*>Tarjetas;
        typedef std::unordered_map<Articulo*,unsigned int>art;

        //Métodos contructores
        Usuario(const Cadena& id,const Cadena& nombre, const Cadena& apellidos, const Cadena& direccion, const Clave& clave);
        Usuario(const Usuario& )=delete;
        Usuario& operator=(const Usuario)=delete;
        
        //Método destructor
        ~Usuario();

        //Metodos de la clase
        const Cadena id() const{return identificador_;}
        const Cadena nombre()const{return nombre_;}
        const Cadena apellidos()const{return apellidos_;}
        const Cadena direccion() const{return direccion_;}
        const Tarjetas& tarjetas() const{return tarjetas_;}
            
        
        void es_titular_de(Tarjeta&);
        void no_es_titular_de(Tarjeta& t);
        void compra( Articulo& , unsigned int cantidad=1);
        
        const art& compra()const noexcept{return articulos_;}
        const size_t n_articulos()const {return articulos_.size();}
        friend std::ostream& operator <<(std::ostream& salida, const Usuario& u) noexcept;

        //Manejo de excepciones
        class Id_duplicado{
            public:
                Id_duplicado(const Cadena&a):id(a){}
                const Cadena idd()const{return id;}
            private:
                Cadena id;
        };
        
    private:
        Cadena identificador_, nombre_, apellidos_, direccion_;
        Clave pass_;
        size_t n_articulos_;
        Tarjetas tarjetas_;
        art articulos_;
        static std::unordered_set<Cadena> registrados;
    
};
std::ostream& operator << (std::ostream &os, const Usuario &u) noexcept;
std::ostream& mostrar_carro(std::ostream &os, const Usuario &u) noexcept;


#endif