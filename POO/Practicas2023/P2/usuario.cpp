/*
usuario.cpp By Raúl Arcos Herrera 2023
*/

#include "usuario.hpp"
#include <random>
#include <unistd.h>
#include <iomanip>
#include <cstring>
#include <assert.h>

std::unordered_set<Cadena> Usuario::registrados;

//CLASE CLAVE
Clave::Clave(const char* clave){

    //Excepción Clave::Incorrecta si clave < 5 caracteres.
    if(strlen(clave) < 5)
        throw Incorrecta(Razon::CORTA);
    
    //Tal y como indican en las pistas, para cifrar utilizaremos el algoritmo DES
    
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, 64);

    const char* salr= "zyxwvutsrqponmlkjihgfedcbaZYXWVUTSRQPONMLKJIHGFEDCBA9876543210/.";

    char salt[3] = {salr[dist(gen)], salr[dist(gen)],  '\0'};
    //Escogemos dos caracteres random para el cifrado.
    char sal[2] = {salr[rand() % 64], salr[rand() % 64]};
    //Encriptamos la clave recibida.
    char* cla = crypt(clave, sal);
    //Comprobamos si se ha encriptado de forma correcta.
    if(cla == nullptr)
        throw Incorrecta(Razon::ERROR_CRYPT);

    claveCifrada_ = cla;
}

bool Clave::verifica(const char* clave) const{
    //Comparamos la clave recibida en cadena de bajo nivel con la actual en la clase Clave.
    return strcmp(crypt(clave,(const char*)claveCifrada_), (const char*)claveCifrada_) == 0;
}

//CLASE USUARIO
//Constructor a partir de 5 parámetros.
Usuario::Usuario (const Cadena &id, const Cadena &n, const Cadena &a, const Cadena &dir, const Clave &p) :
    identificador_(id), nombre_(n), apellidos_(a), direccion_(dir), pass_(p), n_articulos_(articulos_.size()){
        if(!registrados.insert(identificador_).second) throw Id_duplicado(identificador_);
}

//Procedimiento compra
void Usuario::compra(Articulo &a, unsigned cant){
    if(cant == 0)   
        articulos_.erase(&a);   
    else
        articulos_[&a] = cant;
}

//Métodos de asosiación de tarjeta:
void Usuario::es_titular_de(Tarjeta& tar){
    if(this == tar.titular())
        tarjetas_.insert(std::make_pair(tar.numero(), &tar));
}

void Usuario::no_es_titular_de(Tarjeta& tar){
    tar.anular_titular();
    tarjetas_.erase(tar.numero());
}

//Mostrar carro:
std::ostream& mostrar_carro(std::ostream& salida, const Usuario& usuario) noexcept{

    //Imprimimos la información inicial
    salida << "Carrito de compra de " << usuario.id() << " [Artículos: " << usuario.n_articulos()<<
    "]\nCant. Artículo\n===========================================================\n";
    
        for(auto i = usuario.compra().begin(); i != usuario.compra().end(); i++) 
            salida << "    " << i->second << "    " << " [" << (*i->first).referencia() << "] "  << "\""
            << (*i->first).titulo() << "\", " << (*i->first).f_publi().anno() << ". " << std::fixed 
            << std::setprecision(2) << (*i->first).precio() << " €" << std::endl;
        
    return salida;
}

//Sobrecarga del operador de inserccion de flujo:
std::ostream& operator <<(std::ostream& output, const Usuario& u) noexcept{

    output << u.identificador_ << "[" << (const char*)u.pass_.clave() << "]" << u.nombre_ << u.apellidos_ << "\n"
       << u.direccion_ << std::endl;
    output <<"Tarjetas:" ;
    for(auto i = u.tarjetas().begin(); i != u.tarjetas().end(); i++)
        output << *i->second << std::endl ;

    return output ;
}
//Método destructor
Usuario::~Usuario(){

    for(auto i = tarjetas_.begin(); i != tarjetas_.end(); i++)
        i->second->anular_titular();

    registrados.erase(identificador_);
}