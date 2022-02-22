#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void title ( ) ;



//void title ( )
//{P} Ninguna
//{Q} Muestra el Titulo (Arte ASCII) por pantalla
void title ( ) {

FILE *titulo ;

	titulo = fopen("titulo.txt", "r") ;

	if ( titulo == NULL) {
		puts("Error de apertura");
	}

	else {

		while ( !feof(titulo) ) {

			printf("%c", getc(titulo) );

		}

	}
	
	fclose  (titulo) ;

}