// Incluimos las librerías necesarias para la ejecución del código
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef TITULOTIENDA_H
#define TITULOTIENDA_H

void title_tienda ( ) ; // Declaramos los prototipos



// void title ( )
// {P} Ninguna
// {Q} Muestra el Titulo (Arte ASCII) por pantalla
void title_tienda ( ) {

	FILE *titulo2 ;

	titulo2 = fopen("titulo_tienda.txt", "r") ; // Abrimos el archivo

	if ( titulo2 == NULL) {

		puts("Error de apertura"); // Si no se abre nos da error de apertura

	}

	else {

		while ( !feof(titulo2) ) { // Hasta fin de fichero

			printf("%c", getc(titulo2) ); // Leemos todos los carácteres y mostramos por pantalla

		}

	}

	fclose  (titulo2) ; // Cerramos el fichero

}
#endif
