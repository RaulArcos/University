//tarjeta.cpp Raúl Arcos Herrera

#include <algorithm>
#include <cctype>
#include <iomanip>
#include <iostream>
#include "tarjeta.hpp"

using namespace std;

bool luhn(const Cadena& num);



//CLASE NÚMERO

//Método constructor
Numero::Numero(const Cadena& num)
{   
    /*
    //Creamos una cadena auxiliar.
    Cadena aux = num;
    
    //Quitamos los espacios utilizando la funcion remove_if, no es necesario utilizar EsBlanco.
    remove_if(aux.begin(),aux.end()+1,[](char c)
    {
        return isspace(c);
    });

    numero_ = aux;

    //Pasamos la cadena sin espacios y comprobada al parametro numero_.
    

    //Comprobamos que la longitud es correcta
    if(numero_.length() > 19 || numero_.length() == 0 || numero_.length() < 13)
    {
        throw Numero::Incorrecto(LONGITUD);
    }

    if (find_if( numero_.begin() , numero_.end() , std::not1(EsDigito())) != numero_.end() ) 
    {
        puts(numero_.c_str());
        throw Numero::Incorrecto(razon::DIGITOS) ;
    }

    //Algoritmo luhn
    if(!luhn(numero_))
    {
      //  throw Incorrecto(razon::NO_VALIDO);
    }
    */

   Cadena n = num;
 //Suprimimos espacios
 auto it1 = std::remove_if(n.begin(),n.end(), [](char x){return std::isspace(x);}); 
 if(it1 !=n.end()){ 
    int cont = 0; 
 for(auto j = n.begin(); j != it1; j++, cont++);
 n = n.substr(0,cont);
 } 
 //Comprobamos que sean dígitos
 auto it2 = std::find_if(n.begin(),n.end(), std::not1(EsDigito()));
 if(it2 !=n.end())
 {
      throw Numero::Incorrecto(razon::DIGITOS) ;
 } 
    numero_ = n;
if(numero_.length() > 19 || numero_.length() == 0 || numero_.length() < 13)
    {
        throw Numero::Incorrecto(LONGITUD);
    }
if(!luhn(numero_))
    {
        throw Incorrecto(razon::NO_VALIDO);
    }
}

Numero::operator const char*() const
{
    return numero_.c_str();
}

bool operator <(const Numero& tar1, const Numero& tar2)
{
    return strcmp(tar1,tar2) < 0;
}

//CLASE TARJETA
Tarjeta::Tarjeta(const Numero& num, Usuario& u,const Fecha& caducidad):
num_(num),user_(&u),caducidad_(caducidad),activa_(true)
{
    if(caducidad_<Fecha()) //Comparamos la fecha de caducidad con la actual.
    {
        throw Caducada(caducidad_);
    }
    
    //Comprobamos de que tipo es la tarjeta.
    const char* aux = num;
    //Ponemos el valor por defecto:
    tipo_tarjeta_=Tipo::Otro;

    if(aux[0] == '3' && (aux[1] == '4' || aux[1] == '7')){ tipo_tarjeta_ = Tipo::AmericanExpress;}

    else if (aux[0] == '3'){tipo_tarjeta_ = Tipo::JCB;}

    if(aux[0] == '4') {tipo_tarjeta_ = Tipo::VISA;}

    if(aux[0] == '5') {tipo_tarjeta_ = Tipo::Mastercard;}

    if(aux[0] == '6') {tipo_tarjeta_ = Tipo::Maestro;}

    u.es_titular_de(*this);
}

bool Tarjeta::activa(bool valor)
{
	activa_ = valor;
	return activa_;
}

void Tarjeta::anular_titular()
{
    user_= nullptr;
}

Tarjeta::~Tarjeta()
{
    if(Usuario* usu = const_cast<Usuario*>(user_)){
        usu->no_es_titular_de(*this);
    }
}

bool operator <(const Tarjeta& t1, const Tarjeta& t2)
{
    return t1.numero() < t2.numero();
}

ostream& operator << (ostream& output ,const Tarjeta::Tipo& t)
{

    switch(t)
    {
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

std::ostream& operator << (std::ostream& output, const Tarjeta& t)
{
	Cadena aux1 = t.titular()->nombre();
	Cadena aux2 = t.titular()->apellidos();


	for(size_t i=0; i< aux1.length(); i++)
	{
		aux1[i] = toupper(aux1[i]);
	}

	for(size_t j=0; j< aux2.length(); j++)
	{
		aux2[j] = toupper(aux2[j]);
	}

    output << t.tipo() << "\n"
       << t.numero() << "\n"
       << aux1 << " " << aux2 << "\n"
       << "Caduca: "
       << std::setfill('0') << std::setw(2) << t.caducidad().mes()
       << "/"
       << std::setw(2) << (t.caducidad().anno() % 100 ) << "\n" << std::endl;

    return output ;

}