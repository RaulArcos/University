/*
Cadena.hpp By Raúl Arcos Herrera 2022
*/

#ifndef _CADENA_HPP_
#define _CADENA_HPP_

#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <iterator>

class Cadena{
    public:
    // Constructores
    explicit Cadena(size_t tam = 0, char c = ' '); //Constructor a partir de tamaño y letra de relleno.
    Cadena(const Cadena& cad); //Constructor a partir de otra Cadena.
    Cadena(const char* cad); //Constructor a partir de una cadena de bajo nivel.
    //Cadena(const Cadena& cad,size_t indice,size_t tamano); //Constructor de substr

    //Constructor semántica en movimiento
    Cadena(Cadena&& cad);

    //Destructor
    ~Cadena();

    // Operadores de Asignación
    Cadena& operator =(const Cadena& cad);
    
    //Operador de Asignación con semántica de movimiento
    Cadena& operator =(Cadena&& cad);

    // Operadores Aritmeticos
    Cadena& operator +=(const Cadena& cad) noexcept;
    
    //Sobrecarga del operador indice
    char& operator [](const size_t indice) noexcept;
    const char& operator [](const size_t indice) const noexcept;

    //Observadores
    size_t length() const noexcept;
    Cadena substr(unsigned indice, unsigned tam) const;
    char &at(size_t indice);
    const char &at(size_t indice) const;

    //Conversiones
    const char* c_str() const noexcept;

    //Definimos los iteradores
    typedef char* iterator;
    typedef const char* const_iterator;
    typedef std::reverse_iterator<iterator> reverse_iterator ;
    typedef std::reverse_iterator<const_iterator> const_reverse_iterator ;

    //Funciones iterador
    iterator begin() noexcept;
    iterator end() noexcept;
    const_iterator begin() const noexcept;
    const_iterator end() const noexcept;
    const_iterator cbegin() const noexcept;
    const_iterator cend() const noexcept;
    reverse_iterator rbegin() noexcept;
    reverse_iterator rend() noexcept;
    const_reverse_iterator crbegin() const noexcept;
    const_reverse_iterator crend() const noexcept;
    const_reverse_iterator rbegin() const noexcept;
    const_reverse_iterator rend() const noexcept;
    
    
    private:

    size_t tam_;
    char *s_;
};

//OPERADORES LÓGICOS
bool operator ==(const Cadena& c1,const Cadena& c2) noexcept;
bool operator >(const Cadena& c1,const Cadena& c2)  noexcept;
bool operator <(const Cadena& c1,const Cadena& c2)  noexcept;
bool operator >=(const Cadena& c1,const Cadena& c2) noexcept;
bool operator <=(const Cadena& c1,const Cadena& c2) noexcept;
bool operator !=(const Cadena& c1,const Cadena& c2) noexcept;

//OPERADORES ARITMETICOS
Cadena operator +(const Cadena& cad1,const Cadena& cad2) noexcept;

//Operadores de insercción y extracción.
std::ostream& operator <<(std::ostream& outputbuffer, const Cadena& cad);
std::istream& operator >>(std::istream& inputbuffer, Cadena& f);



namespace std{	
	template<>	
	struct hash<Cadena>{	
		size_t operator() (const Cadena& cad) const	
		{
			hash<string> hs;				
			const char* p = cad.c_str();	
			string s(p);					
			size_t res = hs(s);				
			return res;						
		}
	};
}
#endif