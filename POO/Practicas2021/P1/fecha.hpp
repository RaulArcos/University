//Fecha.hpp Raúl Arcos Herrera

#ifndef FECHA_HPP_
#define FECHA_HPP_

#include <ctime>
#include <vector>
#include <iostream>

using namespace std;

class Fecha
{

    public:
        //Declaración de año máximo y mínimo.
        static const int AnnoMinimo = 1902;
        static const int AnnoMaximo = 2037;

        //Métodos Constructores.
        explicit Fecha( int dia = 0, int mes = 0, int anno = 0);
        Fecha(const char* cadena);
        Fecha(const Fecha& f) = default;

        //Método Destructor.
        ~Fecha() = default;

        //Métodos observadores.
        int dia() const noexcept;
        int mes() const noexcept;
        int anno() const noexcept;
        
        //Conversioón de Fecha a cadena de bajo nivel.
        const char* cadena() const noexcept;
        
        //Operador de Asignación
        Fecha &operator =(const Fecha& f) = default;

        //Operadores Aritméticos.
        Fecha &operator +=(int); 
        Fecha &operator -=(int);
        Fecha operator +(int) const;
        Fecha operator -(int) const;
        Fecha operator ++(int);
        Fecha operator --(int);
        Fecha &operator ++();
        Fecha &operator --();
        
        //Clase Inválida para la expresión de errores.
        class Invalida
        {
            public:
            
            Invalida(const char* c):cadena_error(c){}
            const char* por_que() const{
                return cadena_error;
            }
            private:
            
            const char* cadena_error;
        };

    private:
        
        void FechaCeros();  //Comprueba si dia,mes o anno es 0, en caso afirmativo lo sustituye por la fecha actual.
        void FechaValida(); //Comprueba que la Fecha es válida.
        void actualiza(); //Normaliza la Fecha obtenida.
        int dia_,mes_,anno_;
        
        
};

//Operadores lógicos
bool operator == (const Fecha& Fecha1, const Fecha& Fecha2);
bool operator != (const Fecha& Fecha1, const Fecha& Fecha2);
bool operator > (const Fecha& Fecha1, const Fecha& Fecha2);
bool operator >= (const Fecha& Fecha1, const Fecha& Fecha2);
bool operator < (const Fecha& Fecha1, const Fecha& Fecha2);
bool operator <= (const Fecha& Fecha1, const Fecha& Fecha2);

//Operadores de Entrada y Salida
ostream& operator <<(ostream& outputbuffer, const Fecha& f);
istream& operator >>(istream& inputbuffer, Fecha& f);





#endif