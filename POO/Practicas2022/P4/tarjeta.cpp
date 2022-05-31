/*
tarjeta.cpp By Raúl Arcos Herrera 2022
*/

#include "tarjeta.hpp"
#include <algorithm>
#include <cctype>
#include <iomanip>
#include <iostream>

bool luhn(const Cadena& num);
std::set<Numero> Tarjeta::numeros_;


//CLASE NÚMERO
//Método constructor
Numero::Numero(const Cadena& num){

 char cad[] = "./ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    size_t it = strcspn (num.c_str(), cad);

    if (it < num.length()) throw Incorrecto(razon::DIGITOS);

    char *pch, *aux = new char[30];
    pch = strpbrk (const_cast<char*> (num.c_str()), "1234567890");
    int i = 0;

    while (pch != NULL){
        aux[i++] = *pch;
        pch = strpbrk(pch + 1, "1234567890");
    }

    aux[i] = '\0';
    Cadena numero(aux);
    delete[] aux;

    if (numero.length() > 19 || numero.length() < 13) 
        throw Incorrecto(razon::LONGITUD);
    if (!luhn(numero)) 
        throw Incorrecto(razon::NO_VALIDO);

    numero_ = numero;
}

bool operator <(const Numero& tar1, const Numero& tar2){
    return strcmp(tar1,tar2) < 0;
}

//CLASE TARJETA
Tarjeta::Tarjeta(const Numero& num, Usuario& u,const Fecha& caducidad):
num_(num),user_(&u),caducidad_(caducidad),activa_(true){

    
    if(caducidad_<Fecha()) //Comparamos la fecha de caducidad con la actual.
        throw Caducada(caducidad_);
    if (numeros_.insert(num).second==false)
        throw Num_duplicado(num);
        
    //Comprobamos de que tipo es la tarjeta.
    const char* aux = num;
    //Ponemos el valor por defecto:
    tipo_tarjeta_=Tipo::Otro;

    if(aux[0] == '3' && (aux[1] == '4' || aux[1] == '7'))
        tipo_tarjeta_ = Tipo::AmericanExpress;
    else if (aux[0] == '3'){tipo_tarjeta_ = Tipo::JCB;}
    if(aux[0] == '4') 
        tipo_tarjeta_ = Tipo::VISA;
    if(aux[0] == '5')
        tipo_tarjeta_ = Tipo::Mastercard;
    if(aux[0] == '6') 
        tipo_tarjeta_ = Tipo::Maestro;

    u.es_titular_de(*this);
}

Tarjeta::~Tarjeta(){
    if(Usuario* usu = const_cast<Usuario*>(user_))
        usu->no_es_titular_de(*this);
    numeros_.erase(num_);
}

bool operator <(const Tarjeta& t1, const Tarjeta& t2){
    return t1.numero() < t2.numero();
}

std::ostream& operator << (std::ostream& output ,const Tarjeta::Tipo& t){

    switch(t){
        case 0: output << "Otro" ; break;
        case 1: output << "VISA" ; break ;
        case 2: output << "Mastercard"; break ;
        case 3: output << "Maestro"; break ;
        case 4: output << "JCB" ; break ;
        case 5: output << "AmericanExpress" ; break ;

        default: output << "Otra"; break ;
    }

    return output ;
}

bool Tarjeta::activa(bool f){
    activa_=f;
    return activa_;
}

std::ostream& operator << (std::ostream& output, const Tarjeta& t){

	Cadena aux1 = t.titular()->nombre();
	Cadena aux2 = t.titular()->apellidos();
    
	for(size_t i=0; i< aux1.length(); i++)
	    aux1[i] = toupper(aux1[i]);
	
	for(size_t j=0; j< aux2.length(); j++)
	    aux2[j] = toupper(aux2[j]);
	
    output << t.tipo() << "\n"
       << t.numero() << "\n"
       << aux1 << " " << aux2 << "\n"
       << "Caduca: "
       << std::setfill('0') << std::setw(2) << t.caducidad().mes()
       << "/"
       << std::setw(2) << (t.caducidad().anno() % 100 ) << "\n" << std::endl;

    return output ;
}