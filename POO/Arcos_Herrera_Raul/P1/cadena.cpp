/****************************************
* cadena.cpp By Raúl Arcos Herrera 2022 *
*****************************************/
#include "cadena.hpp"

//Creacion de la cadena con dos parametros, tamaño inicial y caracter de relleno.
Cadena::Cadena(size_t tam, char s):tam_(tam),s_ (new char[tam+1]){                                                  
    for(size_t i = 0; i<tam ;i++)
        s_[i] = s;
    s_[tam_] = '\0';
}
//Copiar a partir de otra cadena.
Cadena::Cadena(const Cadena& cad):tam_(cad.tam_),s_(new char[cad.tam_+1]){
    strcpy(s_,cad.s_);
}
//A partir de una cadena de caracteres de bajo nivel.
Cadena::Cadena(const char* cad){
    tam_ = strlen(cad);
    s_ = new char[tam_+1];
    strcpy(s_,cad);
}

//Constructor de copia con semántica de movimiento.
Cadena::Cadena(Cadena&& cad){
    tam_ = cad.tam_;
    s_ = cad.s_;
    
    cad.s_ =nullptr;
    cad.tam_ = 0;
}

//Operador de asignación.
Cadena &Cadena::operator =(const Cadena& cad){
    this->tam_ = cad.tam_;
    delete[] this->s_;
    this->s_ = new char[this->tam_+1];
    strcpy(this->s_,cad.s_);
    return *this;
}

//Operador de Asignación con semántica de movimiento.
Cadena &Cadena::operator =(Cadena&& cad){
    delete[] s_;
    this->tam_ = cad.tam_;
    this->s_ = cad.s_;

    cad.tam_= 0;
    cad.s_= nullptr;

    return *this;
}

//Función observadora para la longitud de una cadena.
size_t Cadena::length() const noexcept{
    return this->tam_;
}

Cadena Cadena::substr(unsigned indice, unsigned tam) const{
    if(tam > this->tam_ - indice|| indice >= this->tam_)
        throw std::out_of_range("substr -> Fuera de rango");

    char* cadaux = new char[tam+1]; //tam = 12 cadaux =13
    for(size_t i = 0; i < tam ; i++){
       cadaux[i] = this->s_[indice];     
       indice++;                         
    }                                       
    
    cadaux[tam] = '\0';
    Cadena cadenareturn(cadaux);
    delete[] cadaux;
    return cadenareturn;
}

char& Cadena::at(size_t indice){
    if(indice < tam_) 
        return s_[indice];
    throw std::out_of_range("at -> Error, indice > tamaño o indice < 0");
}
const char& Cadena::at(size_t indice) const{
    if(indice < tam_) 
        return s_[indice];
    throw std::out_of_range("at -> Error, indice > tamaño o indice < 0");
}


//Operador de conversion a cadena de bajo nivel
const char* Cadena::c_str() const noexcept{
    return s_;
}

// Operador de índice
// Consultora
const char& Cadena::operator[](const size_t indice) const noexcept {
    return this->s_[indice] ;
}
// Modificadora
char& Cadena::operator[] (const size_t indice) noexcept {
    return this->s_[indice] ;
}

//Operadores aritmeticos  REHACER
Cadena &Cadena::operator +=(const Cadena &cad) noexcept{
    Cadena aux(*this);
    this->tam_ += cad.tam_;
    delete[] this->s_;
    this->s_ = new char [this->tam_ + 1] ;
    strcpy(this->s_,aux.s_) ;
    strcat(this->s_,cad.s_) ;
    return *this;
}
//Operadores aritmeticos
Cadena operator +(const Cadena& cad1,const Cadena& cad2) noexcept{
    return Cadena(cad1) += cad2;
}
//Operadores lógicos
bool operator ==(const Cadena& cad1, const Cadena& cad2) noexcept{
    return (!strcmp(cad1.c_str(),cad2.c_str()));
}

bool operator !=(const Cadena& cad1, const Cadena& cad2) noexcept{
    return (strcmp(cad1.c_str(),cad2.c_str()));
}

bool operator >(const Cadena& cad1, const Cadena& cad2) noexcept{   
    return (cad1[0] > cad2[0]);
}
bool operator <(const Cadena& cad1, const Cadena& cad2) noexcept{   
    return ( strcmp(cad1.c_str() , cad2.c_str()) < 0 );
}
bool operator >=(const Cadena& cad1, const Cadena& cad2) noexcept{   
    return (cad1[0] >= cad2[0]);
}
bool operator <=(const Cadena& cad1, const Cadena& cad2) noexcept{   
    return (cad1[0] <= cad2[0]);
}

//Destructor.
Cadena::~Cadena(){
    tam_ = 0;
    delete[] s_;
}

//Operadores de insercción y extracción.
std::istream& operator >>(std::istream& inputbuffer, Cadena& cad){
    char s[33]="";
    inputbuffer.width(33);
    inputbuffer >> s;
    cad = s;
    return inputbuffer;
}
std::ostream& operator <<(std::ostream& outputbuffer, const Cadena& cad){
    outputbuffer << cad.c_str();
    return outputbuffer;  
}

//Funciones iteradores
Cadena::iterator Cadena::begin() noexcept{
    return s_;
}
Cadena::iterator Cadena::end() noexcept{
    return s_ + tam_;
}
Cadena::const_iterator Cadena::cbegin() const  noexcept{
    return s_;
}
Cadena::const_iterator Cadena::cend()const  noexcept{
    return s_ + tam_;
}

Cadena::const_iterator Cadena::begin() const noexcept{
    return cbegin();
}
Cadena::const_iterator Cadena::end() const noexcept{
    return cend();
}

Cadena::reverse_iterator Cadena::rbegin() noexcept{
    return reverse_iterator(end());
}
Cadena::reverse_iterator Cadena::rend() noexcept{
    return reverse_iterator(begin());
}
Cadena::const_reverse_iterator Cadena::crbegin() const noexcept{
    return const_reverse_iterator(end());
}
Cadena::const_reverse_iterator Cadena::crend() const noexcept{
    return const_reverse_iterator(begin());
}
Cadena::const_reverse_iterator Cadena::rbegin() const noexcept{
    return crbegin() ; 
}
Cadena::const_reverse_iterator Cadena::rend() const noexcept{
    return crend();
}