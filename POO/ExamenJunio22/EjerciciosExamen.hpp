#include <iostream>
#include <string>
#include <list>
#include <vector>


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
    std::vector<Turismo*> vectorTurismo;
    auto iturismo = vectorTurismo.begin();

    std::vector<Camion*> vectorCamion;
    auto icamion = vectorCamion.begin();

    for( auto it = vectorVehiculo.begin(); it != vectorVehiculo.end(); it++){

        
    }
}