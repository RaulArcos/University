//usuario.hpp Raúl Arcos Herrera

#ifndef USUARIO_HPP_
#define USUARIO_HPP_

#include <ostream>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include "cadena.hpp"
#include "articulo.hpp"
#include "tarjeta.hpp"

using namespace std;

//Clases que vamos a utilizar:
class Numero;
class Tarjeta;

class Clave
{
    public:
        
        //Método constructor a través de una cadena de bajo nivel:
        Clave(const char* clave);
        const Cadena& clave() const;

        //Creamos la clase Clave::Incorrecta:
        
        enum Razon{CORTA, ERROR_CRYPT};

        class Incorrecta
        {
            
            
            public:
                //Método constructor a partir de una razón.
                Incorrecta(const Razon e):e_(e){};
                Razon razon() const {return e_;}
            private:

                Razon e_;

        
        };
        
        //Verificación constraseña
        bool verifica(const char* clave) const;
        
     

    private:

        //Atributos de la clase Clave:
        Cadena clave_;
};

   inline const Cadena& Clave::clave() const {
            return clave_;
        }

class Usuario
{
    public:
        
        typedef unordered_set<Cadena> Usuarios;
        //Diccionario ordenado de numeros de tarjeta.
        typedef map<Numero,Tarjeta*> Tarjetas;
        //Diccionario desordenado de puntero a artículos.
        typedef unordered_map<Articulo*, size_t> Articulos;

        //Métodos constructores:
        Usuario(const Cadena& id,const Cadena& nom,const Cadena& ape,const Cadena& dir,const Clave& pass);

        //usuario::Id_duplicado
        class Id_duplicado
        {
            public:
                Id_duplicado(const Cadena& id):iden_(id){}
                const Cadena idd() const { return iden_;};
            private:
                Cadena iden_;
         };

        //Métodos observadores:
        Cadena id() const {return identificador_;};
        Cadena nombre() const {return nombre_;};
        Cadena apellidos() const {return apellidos_;};
        Cadena direccion() const {return direccion_;};
        
        const Tarjetas& tarjetas() const {return tarjetas_; };
        const Articulos& compra() const {return articulos_; };
        void compra(Articulo& a, unsigned cant = 1);
        size_t n_articulos() const {return articulos_.size();};

        //Métodos de asosiación de la clase tarjeta:
        void es_titular_de(Tarjeta& tar);
        void no_es_titular_de(Tarjeta& tar);

        //Método destructor:
        ~Usuario();

        //Sobrecarga del operador de inserccion de flujo:
        friend ostream& operator <<(ostream& salida, const Usuario& usuario);

        Usuario& operator =(const Usuario& u) = delete;
        Usuario(const Usuario& u) = delete;

    private:
        //Atributos clase Usuario:
        const Cadena identificador_,nombre_,apellidos_,direccion_;
        
        Clave password_;
        Tarjetas tarjetas_;
        Articulos articulos_;
        static Usuarios usuario_;
};
//Mostrar carro por pantalla.
ostream& mostrar_carro(ostream& salida, const Usuario& user);

#endif