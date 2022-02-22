#include "main.h"
#include <stdio.h>

void login () ;
void menu_logueo () ;
int contador_tamano (char *cadena) ;

int main () {

	title() ;

	menu_logueo () ;

	return 0 ;
}

// void menu_logueo ()
// {P} Ninguna
// {Q} Crea y pide valor para la utilizacion del menu para entrar o salir
void menu_logueo ()  {

	int opcion_logueo ;

	do {

		printf("\n\t%c%cPreparado para la guerra?%c\n\n[1] Iniciar Sesion\n[2] Salir del Sistema\n", 254, 168, 254);

		scanf("%i", &opcion_logueo);

	} while ( opcion_logueo != 1 && opcion_logueo != 2 ) ;

		switch (opcion_logueo) {

			case 1:

				login () ;
				break ;

			case 2:

				printf("\nGracias por probar ESINITE\n");
				break ;
		}

}
// void login ()
// {P}
// {Q}
void login () {
   int x;
	 FILE *jugadores ;
	 char usuario[20] ;
	 char contrasena[20] ;
	 char copia_usuario[100] ;
	 char lectura;
	 char *token ;
	 char *tokenc;
	 const char separador[2] = "/" ;
	 int opcion , cont = 0 ;

	 jugadores = fopen("jugadores.txt", "r++") ;

	 if ( jugadores == NULL ) {

	 	printf("\nError de apertura en el fichero\n");

	 }

	 else {

	 	//Pide el nombre de usuario
	 	printf("\nNombre de Usuario:\t");
	 	scanf("%s", usuario) ;

	 	//Comprueba que el nombre de usuario está en el fichero
		 do {

		 	//Asigna a la cadena auxiliar una linea de 100 caracteres del fichero
	 		fgets (copia_usuario, 100 , jugadores) ;
	 		//Coge lo que haya antes del / de dicha cadena
	 		token = strtok (copia_usuario, separador) ;

	 		//Si el fichero termina o no encuentra comparativa sale
	 	 } while (!feof(jugadores) && strcmp(token, usuario) != 0) ;
 
	 	//Si ha encontrado usuario pide contraseña
	 	if ( strcmp(token, usuario ) == 0 ) {

	 		printf("\nContrase%ca:\t", 164);
	 		scanf("%s", contrasena) ;

for (x=10;x>0;x--){  //Recorre la linea del fichero en la que se enuentre el nombre de Usuario
	(tokenc = strtok( NULL, separador )); //Coge el token numero 11, que es la contraseña
}


		if ( strcmp(contrasena,tokenc) == 0 ){  //Si la contraseña coincide con el token, tienes acceso

   printf("Te has logeado con exito");

		} else printf("Contrasena incorrecta");



	 	}

	 	//Sino ha encontrado usuario pide registro
	 	else {

	 		printf("\nUsuario no encontrado\n");

	 		do {

	 			printf("\n[1] Volver a introducir usuario\n[2] Registrarme\n");
	 			scanf("%i", &opcion);

	 		} while ( opcion != 1 && opcion != 2 ) ;

	 		switch (opcion) {

	 			case 1:

	 				login () ;
	 				break ;

	 			case 2:

	 				printf("Esa Opción no esta disponible aún, Lo introduciremos en el futuro");
	 				break;

	 		}
	 		}

	 	}

/* Codigo que funcionaba sobre la repetiicon de coger el token y compararlo

	 	else {

	 		do {

	 			fgets (copia_usuario, 100 , jugadores) ;
	 			token = strtok (copia_usuario, separador) ;

	 			if ( strcmp(token, usuario ) == 0 ) {

	 				printf("\nContrase%ca:\t", 164);
	 				scanf("%s", contrasena) ;

	 			}
	 		} while (!feof(jugadores)) ;
	 	}

*/
	 fclose(jugadores) ;

	 }

// int contador_tamano (char *cadena)
// {P} Cadena de caracteres para contar inicializada
// {Q} Devuelve el tamaño de la cadena introducida por el usuario
int contador_tamano (char *cadena) {

	int tamano_cadena = 0;

	 	for ( int i = 0 ; cadena[i] != '\0' ; i++) {

	 		tamano_cadena++ ;

	 	}

	return tamano_cadena ;
}
