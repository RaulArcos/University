/*
Fecha.hpp By Raúl Arcos Herrera 2022
*/

#ifndef FECHA_HPP_
#define FECHA_HPP_

#include <ctime>
#include <vector>
#include <iostream>

//IMPLEMENTACIÓN DE LA CLASE FECHA
class Fecha{

    public:
        
        //Métodos constructores
        explicit Fecha(int dia = 0, int mes = 0, int anno = 0);
        Fecha(const char* cad);
        Fecha(const Fecha& f)= default;

        //Método Destructor
        ~Fecha() = default;

        //Métodos observadores
        int dia() const noexcept;
        int mes() const noexcept;
        int anno() const noexcept;

        //Conversión de Fecha a cadena de bajo nivel
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
        class Invalida{
            public:
            //Método constructor de la clase Inválida
            Invalida(const char* c):cadena_error(c){}
            const char* por_que() const{
                return cadena_error;
            }
            private:
            
            const char* cadena_error;
        };
        //Declaración de las variables año máximo y mínimo
        static const int AnnoMinimo = 1902;
        static const int AnnoMaximo = 2037;

    private:
        int dia_,mes_,anno_;
        void FechaCeros();  //Comprueba si dia,mes o anno es 0, en caso afirmativo lo sustituye por la fecha actual.
        void FechaValida(); //Comprueba que la Fecha es válida.
        void actualiza(); //Normaliza la Fecha obtenida.

};

//Operadores lógicos
bool operator == (const Fecha& Fecha1, const Fecha& Fecha2);
bool operator != (const Fecha& Fecha1, const Fecha& Fecha2);
bool operator > (const Fecha& Fecha1, const Fecha& Fecha2);
bool operator >= (const Fecha& Fecha1, const Fecha& Fecha2);
bool operator < (const Fecha& Fecha1, const Fecha& Fecha2);
bool operator <= (const Fecha& Fecha1, const Fecha& Fecha2);

//Operadores de Entrada y Salida
std::ostream& operator <<(std::ostream& outputbuffer, const Fecha& f);
std::istream& operator >>(std::istream& inputbuffer, Fecha& f);


#endif