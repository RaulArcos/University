#include <stdio.h>
#include <stdlib.h>

int main () {

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

	return 0 ;
}