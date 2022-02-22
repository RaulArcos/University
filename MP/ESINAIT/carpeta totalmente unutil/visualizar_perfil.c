#include <stdio.h>
#include <stdlib.h>
#include <string.h>




void main(){
  int x;
  FILE *jugadores ;
  FILE *aux;
  char copia_usuario2[100];
  char usuario[20] ;
  char contrasena[20] ;
  char copia_usuario[100] ;
  char copia[100];
  char *token ;
  const char separador[2] = "/" ;

  jugadores = fopen("jugadores.txt", "r++") ;
  if ( jugadores == NULL ) {

   printf("\nError de apertura en el fichero\n");

  }



   //Pide el nombre de usuario
   printf("\nNombre de Usuario Que Quieras Eliminar:\t");
   scanf("%s", usuario) ;


   //Comprueba que el nombre de usuario está en el fichero
    do {

     //Asigna a la cadena auxiliar una linea de 100 caracteres del fichero
     fgets (copia_usuario, 100 , jugadores) ;
     strcpy (copia_usuario2, copia_usuario);
     //Coge lo que haya antes del / de dicha cadena
     token = strtok (copia_usuario, separador) ;
    } while (!feof(jugadores) && strcmp(token, usuario) != 0) ;




    for ( int x = 10 ; x > 0 ; x-- ){
      (token = strtok( NULL, separador ));
      printf("\ nombre de usuario : %s",token);
        if (x==9) printf("%s",token);
          if (x==1) printf("%s",token);
    }
  fclose(jugadores);

}
