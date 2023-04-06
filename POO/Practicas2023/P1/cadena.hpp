/****************************************
* cadena.hpp By Raúl Arcos Herrera 2023 *
*****************************************/

#ifndef _CADENA_HPP_
#define _CADENA_HPP_

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <iterator>

class Cadena{
    public:
    // Constructores
    explicit Cadena(unsigned int tam = 0, char c = ' '); //Constructor a partir de tamaño y letra de relleno.
    Cadena(const Cadena& cad); //Constructor a partir de otra Cadena.
    Cadena(const char* cad); //Constructor a partir de una cadena de bajo nivel.

    //Constructor semántica en movimiento
    Cadena(Cadena&& cad) noexcept;

    //Destructor
    ~Cadena();

    // Operadores de Asignación
    Cadena& operator =(const Cadena& cad);
    
    //Operador de Asignación con semántica de movimiento
    Cadena& operator =(Cadena&& cad) noexcept;

    // Operadores Aritmeticos
    Cadena& operator +=(const Cadena& cad) noexcept;
    
    //Sobrecarga del operador indice
    char& operator [](const unsigned int indice) noexcept;
    const char& operator [](const unsigned int indice) const noexcept;

    //Observadores
    unsigned int length() const noexcept;
    Cadena substr(unsigned indice, unsigned tam) const;
    char &at(unsigned int indice);
    const char &at(unsigned int indice) const;

    //Conversiones
    explicit operator const char*() const {return s_;}

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

    unsigned int tam_;
    char *s_;
};

//OPERADORES LÓGICOS

//operador ==
inline bool operator ==(const Cadena& cad1, const Cadena& cad2) noexcept{
    return (!strcmp(cad1.operator const char*(), cad2.operator const char*()));
}

// Operador >
inline bool operator>(const Cadena& cad1, const Cadena& cad2) noexcept {
    return strcmp(cad1.operator const char*(), cad2.operator const char*()) > 0;
}
// Operador <
inline bool operator<(const Cadena& cad1, const Cadena& cad2) noexcept {
    return strcmp(cad1.operator const char*(), cad2.operator const char*()) < 0;
}
// Operador >=
inline bool operator>=(const Cadena& cad1, const Cadena& cad2) noexcept {
    return strcmp(cad1.operator const char*(), cad2.operator const char*()) >= 0;
}

// Operador <=
inline bool operator<=(const Cadena& cad1, const Cadena& cad2) noexcept {
    return strcmp(cad1.operator const char*(), cad2.operator const char*()) <= 0;
}

// Operador !=
inline bool operator!=(const Cadena& cad1, const Cadena& cad2) noexcept {
    return strcmp(cad1.operator const char*(), cad2.operator const char*()) != 0;
}

//OPERADORES ARITMETICOS
Cadena operator +(const Cadena& cad1,const Cadena& cad2) noexcept;

//Operadores de insercción y extracción.
std::ostream& operator <<(std::ostream& outputbuffer, const Cadena& cad);
std::istream& operator >>(std::istream& inputbuffer, Cadena& f);

namespace std{	
	template<>	
	struct hash<Cadena>{	
		unsigned int operator() (const Cadena& cad) const	
		{
			hash<string> hs;				
			const char* p = cad.operator const char*();	
			string s(p);					
			unsigned int res = hs(s);				
			return res;						
		}
	};
}

#endif