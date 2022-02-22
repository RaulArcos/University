// Incluimos las librerías necesarias para la ejecución del código
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void title ( ) ; // Declaramos los prototipos



// void title ( )
// {P} Ninguna
// {Q} Muestra el Titulo (Arte ASCII) por pantalla
void title ( ) {

	FILE *titulo ;

	titulo = fopen("titulo.txt", "r") ; // Abrimos el archivo

	if ( titulo == NULL) {

		puts("Error de apertura"); // Si no se abre nos da error de apertura

	}

	else {

		while ( !feof(titulo) ) { // Hasta fin de fichero

			printf("%c", getc(titulo) ); // Leemos todos los carácteres y mostramos por pantalla

		}

	}

	fclose  (titulo) ; // Cerramos el fichero

}
