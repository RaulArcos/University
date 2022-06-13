#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <typeinfo>


//EJERCICIO 3 FEBRERO 2021
//Consideramos el siguiente programa

class Instrumento{
    public: 
        Instrumento(std::string n): nom(n){}
        void tocar() const {
            std::cout << "Soy un " << nombre() << " y pertenezco a " << tipo() << std::endl;
        }
        std::string nombre() const { return nom;}
        virtual std::string tipo() const { return "Instrumento";}

        private:
            std::string nom;
};     

/*Como nos dicen que creamos una clase cuerda tal que blabla, PERO dice que sea en 
tiempo de ejecución, vamos a utilizar el método virtual
*/

class Cuerda: public Instrumento{
    public:
        Cuerda(std::string n): Instrumento(n){}
        std::string tipo() const{return "Cuerda";}

    private:
};


//Junio 2020 (No se qué ejericio exácto)
/* 
En este caso vamos a utilizar 
*/
template <typename T>
class ColaPrioridad{
    public:
        ColaPrioridad();
        bool vacia();
        const T& primero() const;
        void encolar();
        void desencolar(T& e);
    private:
        std::list<T> colaPrioridad;
};

//Junio 2020 (Otro Ejercicio)
class Vehiculo{

    public:
        Vehiculo(std::string fechaFabricacion):fechaFabricacion_(fechaFabricacion){}
        const std::string getFechaFabricacion() const {return fechaFabricacion_;}
        virtual const void datosVehiculo() = 0;
        
    private:
        std::string fechaFabricacion_;
};

class Turismo: public Vehiculo{
    public:
        Turismo(std::string fechaFabricacion, unsigned numeroPuertas): Vehiculo(fechaFabricacion),numeroPuertas_(numeroPuertas){}
        const unsigned getNumeroPuertas() const {return numeroPuertas_;}
        const void datosVehiculo() {
            std::cout << "Es un turimo fabricado en " << this->getFechaFabricacion() << " y tiene " << this->getNumeroPuertas() << " puertas.";
        }
    private:
        unsigned numeroPuertas_;
};

class Camion: public Vehiculo{
    public:
        Camion(std::string fechaFabricacion, unsigned pesoMaximo): Vehiculo(fechaFabricacion), pesoMaximo_(pesoMaximo){}
        const unsigned getPesoMaximo() const {return pesoMaximo_;}
        const void datosVehiculo() {
            std::cout << "Es un camion fabricado en " << this->getFechaFabricacion() << " y tiene " << this->getPesoMaximo() << " como peso máximo.";
        }
    private:
        unsigned pesoMaximo_;
};

void clasificadorVectorVehiculo(std::vector<Vehiculo*> vectorVehiculo){
    
    size_t cont = 0;
    Turismo *taux;
    Camion *caux;
    std::vector<Turismo*> vectorTurismo;
    std::vector<Camion*> vectorCamion;
    auto iturismo = vectorTurismo.begin();
    auto icamion = vectorCamion.begin();
    auto ivehiculo = vectorVehiculo.begin();

    while(ivehiculo != vectorVehiculo.end()){
        if(taux = dynamic_cast<Turismo*>(vectorVehiculo[cont])){
           // vectorTurismo.insert(iturismo, vectorVehiculo[cont]);
            vectorVehiculo.erase(ivehiculo);
            iturismo++;
        }
        else{
            // vectorCamion.insert(icamion, vectorVehiculo[cont]);
            vectorVehiculo.erase(ivehiculo);
            icamion++;
        }
        cont++;
        ivehiculo++;
    }
}


//JUNIO 2020 NO SE QUE EJERCICIO ES
/*
void tocar(Instrumento& i){
    if(typeid(i) == typeid(Cuerda))
        std::cout << "tocar Cuerda" << std::endl;
    if(typeid(i) == typeid(Guitarra))
    std::cout << "tocar Guitarra" << std::endl;
    if(typeid(i) == typeid(Clarinete))
    std::cout << "tocar clarinete" << std::endl;
}

int main(){

    Guitarra g;
    Clarinete c;
    Bombo b;

    tocar(g) // tocar guitarra
    tocar(c) // tocar clarinete
    tocar(b) // tocar bombo
}
*/
/* No, esta no es la mejor idea, puesto que al tratarse de un typeid tendríamos que hacer un if
por cada uno de los subtipos y editar el método "tocar" para incluirlo.

La mejor manera, sería hacer que tocar fuese un método virtual dentro de la superclase y sobrecargar el método
para cada una de las subclases
*/

//DICIEMBRE DE 2020 ES EL MISMO EJERCICIO

//"EXAMEN 2015"
//Nos dan lo siguiente:

int main(){
    Circulo cir(1.0);
    Cuadrado cua(2.0);
    //Forma* forma ={&cir,&cua};

    //for(int i = 0; i < 2; i++)
        //std::cout << "El area de la figura " << (i+1) << " es " << forma-> area();
}

//Tenemos que implementar las clases Forma, Circulo y Cuadrado.

class Forma{
    public:
        Forma(double tamano): tamano_(tamano){}
        virtual const double area() const = 0;
    private:
        double tamano_;
};

class Cuadrado: public Forma{
    public:
        Cuadrado(double lado):Forma(lado){}
        const double area() const { return 4; }
    private:

};

class Circulo: public Forma{
    public:
        Circulo(double radio):Forma(radio){}
        const double area() const { return 3.14; }
    private:

};

/*En el apartado B nos dicen que añados una clase excepcion a circulo de manera que lance una excepcion cuando
Cuando el radio adminsitrado sea negativo*/

class Circulo: public Forma{
    public:
        Circulo(double radio):Forma(radio){
            if(radio < 0)
                throw Radio_negativo(radio);
        }
        const double area() const { return 3.14; }

        class Radio_negativo{
            public:
                Radio_negativo(double radio_negativo): rd(radio_negativo){}
                const double valor() const {return rd;}
            private:
                double rd;
        };

    private:
};

//ELIPSE Y CIRCUNFERENCIA (NO SE EL AÑO)
/* A.
Vamos ha implementar a circunferencia como una clase derivada de elipse, a que se debe esto?
¿Es la clase derivada una clase base? No
¿Es un subtipo de elipse? si 
¿Es posible utilizar la clase derivada en todas las situaciones donde se usa la base? si
*/

class Elipse{

    public:
        Elipse(double radio_x, double radio_y): rx_(radio_x),ry_(radio_y){}
        const double radio_x() const {return rx_;}
        const double radio_y() const {return ry_;}

        void escala(double radio);
        void escala(double radio_x,double radio_y);

    private:
        double rx_;
        double ry_;
};

class Circunferencia: public Elipse{

    public:
        Circunferencia(double radio):Elipse(radio,radio){}
        const double radio() const {return this->radio_x();}
        

    private:

};