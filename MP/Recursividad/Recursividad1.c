/*1.- Escribe una función recursiva cifras que reciba un número en base 10 y devuelva cuántas cifras tiene ese número.*/

#include <stdio.h>
#include <stdlib.h>

//Cabecera: int cifras (int numero)
//Precondiciones: numero debe ser en base 10 y mayor que 0
//Postcondiciones: devuelve el número de cifras del entero pasado como argumento
int cifras (int);

//Cabecera: int cifrasFinal (int numero, int i)
//Precondiciones: numero debe ser en base 10 y mayor que 0, además hay que pasar 0 en el segundo argumento
//Postcondiciones: caso base devuelve i, caso general devuelve cifrasFinal(numero, i+1)
int cifrasFinal (int, int);

int main (){
    int numero;

    printf("\n\nIntroduce un numero decimal\n");
    scanf("%d", &numero);

    printf("\n\nEl numero %d tiene %d cifras\n", numero, cifras(numero));

    return 0;
}



int cifras (int numero){     //Función llamadora de cifrasFinal
return cifrasFinal (numero, 0);     //Inicializa el parámetro i de la recursiva final
}

int cifrasFinal (int numero, int i){

    if (numero < 1) return i;   //Si el número es 0 ha terminado de leer cifras y devuelve el total

    else {  //printf("Numero de cifras: %i\n", i);
            //printf("Numero introducido: %d\n", numero);
            cifrasFinal (numero/10, i+1);}      //Si no divide el número entre 10 y aumenta el numero de cifras en 1
}
