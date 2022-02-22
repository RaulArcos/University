//Raúl Arcos Herrera

#include <random>
#include <ctime>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <unistd.h>

#include "usuario.hpp"

//CLASE CLAVE
Clave::Clave(const char* clave)
{
    //Excepción Clave::Incorrecta si clave < 5 caracteres.
    if(strlen(clave) < 5)
    {
        throw Incorrecta(Razon::CORTA);
    }

    //Tal y como indican en las pistas, para cifrar utilizaremos el algoritmo DES
    
    const char* salr = "zyxwvutsrqponmlkjihgfedcbaZYXWVUTSRQPONMLKJIHGFEDCBA9876543210/.";
    //Escogemos dos caracteres random para el cifrado.
    char sal[2] = {salr[rand() % 64], salr[rand() % 64]};
    //Encriptamos la clave recibida.
    char* cla = crypt(clave, sal);
    //Comprobamos si se ha encriptado de forma correcta.
    if(cla == nullptr)
    {
        throw Incorrecta(Razon::ERROR_CRYPT);
    }

    clave_ = cla;
}

bool Clave::verifica(const char* clave) const
{
    //Comparamos la clave recibida en cadena de bajo nivel con la actual en la clase Clave.
    return strcmp(crypt(clave,clave_.c_str()), clave_.c_str()) == 0;

}

//CLASE USUARIO
Usuario::Usuarios Usuario::usuario_;

//Constructor a partir de 5 parámetros.
Usuario::Usuario(const Cadena &id, const Cadena &nom, const Cadena &ape, const Cadena &dir, const Clave &pass):
identificador_(id),nombre_(nom),apellidos_(ape),direccion_(dir),password_(pass)
{
    if(!Usuario::usuario_.insert(id).second)
    {
        throw Usuario::Id_duplicado(id);
    }
}

//Procedimiento compra
void Usuario::compra(Articulo &a, unsigned cant)
{
    if(cant == 0)
    {
        articulos_.erase(&a);   
    }else{
        articulos_[&a] = cant;
    }
}

//Métodos de asosiación de tarjeta:
void Usuario::es_titular_de(Tarjeta& tar)
{
    if(this == tar.titular())
    {   
        tarjetas_.insert(make_pair(tar.numero(), &tar));
    }
}

void Usuario::no_es_titular_de(Tarjeta& tar)
{
    tar.anular_titular();
    tarjetas_.erase(tar.numero());
}

//Mostrar carro:
ostream& mostrar_carro(ostream& salida, const Usuario& usuario)
{

    //Imprimimos la información inicial
    salida << "Carrito de compra de " << usuario.id() << " [Artículos: " << usuario.n_articulos()<<
    "]\nCant. Artículo\n===========================================================\n";
    
        for(auto i = usuario.compra().begin(); i != usuario.compra().end(); i++)
        {   
            salida << "    " << i->second << "    " << " [" << (*i->first).referencia() << "] "  << "\""
            << (*i->first).titulo() << "\", " << (*i->first).f_publi().anno() << ". " << std::fixed 
            << std::setprecision(2) << (*i->first).precio() << " €" << std::endl;
        }

    return salida;
}

//Sobrecarga del operador de inserccion de flujo:
std::ostream& operator <<(std::ostream& output, const Usuario& u)
{
    output << u.identificador_ << "[" << u.password_.clave().c_str() << "]" << u.nombre_ << u.apellidos_ << "\n"
       << u.direccion_ << std::endl;
    output <<"Tarjetas:" ;
    for(auto i = u.tarjetas().begin(); i != u.tarjetas().end(); i++)
    {
        output << *i->second << std::endl ;
    }

    return output ;
}
//Método destructor
Usuario::~Usuario()
{
    for(auto i = tarjetas_.begin(); i != tarjetas_.end(); i++)
    {
        i->second->anular_titular();
    }

    usuario_.erase(identificador_);
}