/*
tarjeta.hpp By Raúl Arcos Herrera 2022
*/

#ifndef TARJETA_HPP_
#define TARJETA_HPP_
#include "../P1/cadena.hpp"
#include "../P1/fecha.hpp"
#include "usuario.hpp"

class Usuario;

//CLASE NÚMERO
class Numero{

    public:
        //Método constructor
        Numero(const Cadena& numero);
        
        //Declaración de Tipo Razon y clase Incorrecto.
        enum razon{LONGITUD, DIGITOS,NO_VALIDO};
        
        //Clase Numero Incorrecto
        class Incorrecto{
            public:
                Incorrecto(razon r):error_(r){}
                const razon& razon() const {return error_;}
            private:
                enum razon error_;
        };

        //Operador de conversión a cadena de bajo nivel:
        operator const char* () const {return numero_.c_str();}

        //Definimos el operador <<menor-que>>
        friend bool operator <(const Numero& a, const Numero& b);

    private:
        //Atributos de la clase numeros
        Cadena numero_;
};

//CLASE TARJETA
class Tarjeta{
    
    public:
        //Definimos enumeración pública de nombre Tipo:
        enum Tipo{Otro, VISA, Mastercard, Maestro, JCB, AmericanExpress};

        //Métodos constructores:
        Tarjeta(const Numero &num, Usuario &usuario,const Fecha &caducidad);
    
        //Anulamos la copia
        Tarjeta(const Tarjeta& t) = delete;
        Tarjeta& operator =(const Tarjeta& t) = delete;

        //Método destructor
        ~Tarjeta();

        //Clase exepción fecha caducada
        class Caducada{
            public:
                Caducada(const Fecha& fecha):fechacaducidad_(fecha){}
                Fecha cuando() const {return fechacaducidad_;}
            private:
                Fecha fechacaducidad_;
        };

        //Métodos observadores:
        Numero numero() const {return num_;}
        const Usuario* titular() const{ return user_;}
        Fecha caducidad() const {return caducidad_;}
        bool activa() const{return activa_;}
        
        Tipo tipo() const {return tipo_tarjeta_;}
        
        //Método modificador de tarjeta activa
        bool& activa(bool a = true) {activa_ = a; return activa_;}
        void anular_titular();

        //Clase exepción para tarjeta duplicada.
        class Num_duplicado{
            public:
                Num_duplicado(const Numero& num): num_(num){}
                const Numero que() const {return num_;}
            private:
                Numero num_;
        };

        //Clase para desactivar tarjeta.
        class Desactivada {
            public:
                //Constructor
                Desactivada(){}           
        };

    private:
        
        //Atributos de la clase Tarjeta:
        const Numero num_;
        const Usuario *user_;
        const Fecha caducidad_;
        bool activa_;
        Tipo tipo_tarjeta_;
};

std::ostream& operator << (std::ostream& output, const Tarjeta::Tipo& t) ;
std::ostream& operator << (std::ostream& output, const Tarjeta& t) ;
bool operator <(const Tarjeta& a, const Tarjeta& b);


#endif