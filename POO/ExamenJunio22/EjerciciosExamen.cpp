#include "EjerciciosExamen.hpp"


int main(){
    //EJERCICIO 3 FEBRERO 2021
    std::cout << "\n\nEjercicio 3 Febrero 2021\n-------------------------------" << std::endl;
    Instrumento *pi = new Cuerda("Violin");
    pi->tocar();
    delete pi;

    std::cout << "\n\nVehiculos Junio 2020\n-------------------------------" << std::endl;
    Turismo *pt = new Turismo("29/03/2021", 5);
    pt->datosVehiculo();
    delete pt;
}