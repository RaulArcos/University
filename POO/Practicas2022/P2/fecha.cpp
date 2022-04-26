/*
Fecha.cpp By Raúl Arcos Herrera 2022
*/


#include "fecha.hpp"

//Constructor Fecha a partir de INTs
//Asignamos valores a dia_,mes_ y anno_
Fecha::Fecha(int d, int m, int a):dia_(d),mes_(m),anno_(a) {
    FechaCeros(); //En el caso de que alguno de los componentes sea 0.
    FechaValida(); //Validamos fecha.
}
//Constructor de Fecha a partir de cadena de bajo nivel.
Fecha::Fecha(const char* cadena){   
    int d,m,a;
    if(sscanf(cadena, "%d/%d/%d", &d, &m ,&a) !=3) //Captamos 3 enteros, si no son 3, no entra.
        throw(Fecha::Invalida("Fecha Introducida Invalida")); //Lanzamos la excepción.
    else{

        dia_ = d;
        mes_ = m;
        anno_ = a;
        FechaCeros(); //En el caso de que alguno de los componentes sea 0.
    }
    FechaValida(); //Validamos fecha.
}

void Fecha::FechaCeros(){
    std::time_t tiempo_calendario = std::time(nullptr); //Creamos una variable time_t
    std::tm* tiempo_descompuesto = std::localtime(&tiempo_calendario); //en al estructura introducimos la fecha actual

    if(dia_ == 0) //Si cualquiera de los componentes es 0, se le asigna la actual.
        dia_ = tiempo_descompuesto->tm_mday;
    if(mes_ == 0)
        mes_ = tiempo_descompuesto->tm_mon +1 ;
    if(anno_ == 0)
        anno_ = tiempo_descompuesto->tm_year +1900;
}


void Fecha::FechaValida(){
    static int dias_mes_[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    bool Bisiesto = (anno_ % 4 == 0 && (anno_ % 100 != 0 || anno_ % 400 == 0)); 

    if(mes_ == 2){
        if((Bisiesto != 1 && dia_ >= 29) || dia_ < 1)
            throw(Fecha::Invalida("Febrero, aunque sea bisiesto, no puede tener mas de 29 días."));
    }
    else
        if(dia_ > dias_mes_[mes_] || dia_ < 1)
            throw (Fecha::Invalida("El dia_ es mayor que los que hay en el mes_, o menor que 1."));
    if(mes_> 12 || mes_< 1)
        throw(Fecha::Invalida("El mes está fuera de los reales"));
    if( anno_ < Fecha::AnnoMinimo || anno_ > Fecha::AnnoMaximo)
        throw(Fecha::Invalida("La fecha no esta dentro de los años límites"));
}

//FUNCIONES OBSERVADORAS
int Fecha::dia() const noexcept{
    return dia_;
}
int Fecha::mes() const noexcept{
    return mes_;
}
int Fecha::anno() const noexcept{
    return anno_;
}
Fecha &Fecha::operator ++(){
    this->dia_++;
    actualiza();
    return *this;
}
Fecha &Fecha::operator --(){
    this->dia_--;
    actualiza();
    return *this;
}
Fecha &Fecha::operator +=(int d){
    dia_ = dia_ + d;
    actualiza();
    return *this;
}
Fecha &Fecha::operator -=(int d){
    dia_ += -d;
    actualiza();
    return *this;
}
Fecha Fecha::operator +(int d) const{
    Fecha t = *this;
    t += d;
    return t;
}
Fecha Fecha::operator -(int d) const{
    Fecha t = *this;
    t += -d;
    return t;
}
Fecha Fecha::operator ++(int d){
    Fecha t = *this;
    *this += 1;
    return t;
}
Fecha Fecha::operator --(int d){
    Fecha t = *this;
    *this += -1;
    return t;
}
void Fecha::actualiza(){ 
    tm FechaRecibida = {0,0,0,dia_,mes_-1,anno_-1900}; //creamos una estructura fecha de la libreria ctime
                                                       //asignamos el dia, mes y año recibidos a actualizar.
    mktime(&FechaRecibida);
    
    dia_ = FechaRecibida.tm_mday; 
    mes_ = FechaRecibida.tm_mon +1;
    anno_ = FechaRecibida.tm_year+ 1900;
    FechaValida();
}

//Impresion de la cadena fecha.
const char* Fecha::cadena() const noexcept{
    const char* dia_s[] = {"domingo","lunes","martes","miércoles","jueves","viernes","sábado"};
    const char* mes_es[] = {"enero","febero","marzo","abril","mayo","junio","julio","agosto","septiembre","octubre","noviembre","diciembre"};
    static char fechacadena[50];
    tm fecha = {0}; //creamos una fecha tm vacia.
    fecha.tm_mday = dia();
    fecha.tm_mon = mes() - 1 ;
    fecha.tm_year = anno() -1900; //Asignamos dia mes y año a la estructura.
    mktime(&fecha); //Normalizamos la fecha introducida.
    sprintf(fechacadena,"%s %d de %s de %d",dia_s[fecha.tm_wday],fecha.tm_mday,mes_es[fecha.tm_mon],fecha.tm_year+1900); //Imprimimos la fecha por pantalla.
    return fechacadena; //Devolvemos la cadena resultante.
}

//OPERADORES LÓGICOS
//Se comprueban si dia,mes y año son iguales.
bool operator == (const Fecha& Fecha1, const Fecha& Fecha2){
    return ((Fecha1.dia() == Fecha2.dia()) && (Fecha1.mes() == Fecha2.mes()) && (Fecha1.anno() == Fecha2.anno()));
}
//Devolvemos el resultado contrario a ==.
bool operator != (const Fecha& Fecha1, const Fecha& Fecha2){
    return !(Fecha1 == Fecha2);
}
//Comprobamos desde año hasta dia si Fecha1 es mayor que Fecha2
bool operator > (const Fecha& Fecha1, const Fecha& Fecha2) {
    if((Fecha1.anno() > Fecha2.anno()) || 
        (Fecha1.anno() == Fecha2.anno() && Fecha1.mes() > Fecha2.mes()) ||
        (Fecha1.anno() == Fecha2.anno() && Fecha1.mes() == Fecha2.mes() && Fecha1.anno() == Fecha2.anno() && Fecha1.dia() > Fecha2.dia()))
        return 1;
    else return 0;
}
//Comparamos las fechas del revés.
bool operator < (const Fecha& Fecha1, const Fecha& Fecha2){
    return(Fecha2 > Fecha1);
}
//Utilizamos los operadores > y == ya hechos.
bool operator >= (const Fecha& Fecha1, const Fecha& Fecha2){
    return( Fecha1 == Fecha2 || Fecha1 > Fecha2 );
}
//Utilizamos los operadores > y == ya hechos.
bool operator <= (const Fecha& Fecha1, const Fecha& Fecha2){
    return (Fecha1 == Fecha2 || Fecha2 > Fecha1 );
}

//OPERADORES DE ENTRADA/SALIDA

std::ostream& operator <<(std::ostream& outputbuffer, const Fecha& f){
    outputbuffer << f.cadena();
    return outputbuffer;
}
std::istream& operator >>(std::istream& inputbuffer, Fecha& f){
    size_t tam_cad = 12; // 2 de dia + 2 de mes + 4 de año + barras
    char* cad = new char[tam_cad];

    inputbuffer.getline(cad,tam_cad); //Introducimos una cadena de tam_cad caracteres, tambiém podríamos utilizar get(cad,tam_cad,char "\0") 

    try{
        f = Fecha(cad);
    }
    catch(Fecha::Invalida e){   
        inputbuffer.setstate(std::ios::failbit);
        delete[] cad;
        throw e;
        
    }
    delete [] cad;
    return inputbuffer;
}