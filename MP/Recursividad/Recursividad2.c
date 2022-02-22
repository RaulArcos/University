/*2.- Escribe una función recursiva elevar que reciba un argumento real a y otro entero b, con b > 0, y calcule a^b.*/

#include <stdio.h>
#include <stdlib.h>

//Cabecera: int elevar (int base, int potencia)
//Precondiciones: primer argumento real y segundo debe ser entero mayor que 0
//Postcondiciones: devuelve base ^ potencia
int elevar (int, int);

//Cabecera: int elevarFinal (int base, int potencia, int resultado)
//Precondiciones: primer argumento real, segundo debe ser entero mayor que 0 y tercer argumento inicializa valor auxiliar a base
//Postcondiciones: devuelve base ^ potencia
int elevarFinal (int, int, int);

int main (){
    int a, b;

    printf("\n\nIntroduce un numero real\n");
    scanf("%i", &a);

    fflush(stdin);
    printf("\n\nIntroduce un numero entero mayor que 0\n");
    scanf("%i", &b);

    printf("\n\n%i ^ %i = %i\n", a, b, elevar(a, b));

    return 0;
}



int elevar (int base, int potencia){            //Función llamadora de elevarFinal
return elevarFinal (base, potencia, base);         //Inicializa el parámetro i de la recursiva final
}

int elevarFinal (int base, int potencia, int resultado){

    if (potencia <= 1) return resultado;                   //Si potencia llega a 1 se devuelve el resultado total

    else {printf("potencia = %i\n", potencia);
            printf("base = %i\n", base);
            elevarFinal (base, potencia-1, resultado * base);}      //Si no, pasa resultado * base y decrementa el número de veces que falta por multiplicar
}
