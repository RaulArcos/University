#include "funciones.h" // Incluimos las librerías necesarias
#include "estructuras.h"
#include "time.h"


int main(){
    srand (time(NULL));
	
	iniciar_estructuras(); // Inicializamos la función que cargará todas las estructuras

	menu_logueo(); // Inicializamos la función del menu - login

}
