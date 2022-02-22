#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main(){
int x;
FILE *jugadores ;
FILE *aux;
char copia_usuario2[100];
char usuario[20] ;
char copia_usuario[100] ;
char copia[100];
char *token ;
const char separador[2] = "/" ;

//Abre el txt de jugadores, si no lo encuentra pone un mensaje para informar
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
//Puesto que la cadena copia_usuario se va a ver afectada, hacemos una "copia de seguridad"
   strcpy (copia_usuario2, copia_usuario);
   //Coge lo que haya antes del / de dicha cadena
   token = strtok (copia_usuario, separador) ;
  } while (!feof(jugadores) && strcmp(token, usuario) != 0) ;

fclose(jugadores);

//Volvemos a abrir jugadores.txt junto con el archivo auxiliar
jugadores = fopen("pruebadejugadores.txt", "r++") ;
if ( jugadores == NULL ) {

 printf("\nError de apertura en el fichero\n");

}
aux = fopen("auxiliar.txt","w");
if ( aux == NULL ) {

 printf("\nError de apertura en el fichero\n");

}
//coge una cadena, la compara con la cadena del usuario que queremos borrar y si no es la misma la copia al auxiliar
do{
  fgets (copia,100,jugadores);
if(strcmp(copia, copia_usuario2) != 0){
  fprintf(aux,"%s",copia);
}
}while(!feof(jugadores));
fclose(jugadores);
fclose(aux);
//Borramos el jugadores.txt
if(remove("pruebadejugadores.txt")==0){ // Eliminamos el archivo
     printf("El archivo fue eliminado satisfactoriamente\n");
}
//renombramos a auxiliar como el nuevo jugadores.txt
if(rename("auxiliar.txt","pruebadejugadores.txt")==0){
printf("NOmbre cambiado con exito");
}

}
