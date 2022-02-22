/*3.- Diseñe una función recursiva que determine si en un vector A de n enteros
existen dos parejas consecutivas de elementos tales que sus sumas sean idénticas.*/

#include <stdio.h>
#include <stdlib.h>
#define N 10

//Cabecera:
//Precondiciones:
//Postcondiciones:
int parejas (int *, int);

//Cabecera:
//Precondiciones:
//Postcondiciones:
int parejasFinal (int *, int, int, int, int);

int main (){
    int a[N]={0,4,2,3,4,5,2,7,8,9};

    printf("\n\na={0,1,2,3,4,5,6,7,8,9}\n");
    system("PAUSE");

    if (parejas(a, N) == 0) printf("No hay dos parejas consecutivas cuyas sumas sean identicas");
    else printf("Hay dos parejas consecutivas cuyas sumas sean identicas");

    return 0;
}



int parejas (int *a, int n){     //Función llamadora de
return parejasFinal (a, n, 0, a[0]+a[1], a[2]+a[3]);     //Inicializa los parámetros de inmersión de la recursiva final
}

int parejasFinal (int *a, int n, int i, int suma1, int suma2){

    if (i >= n) return 0;
    else {if (suma1 == suma2) return 1;
        else parejasFinal(a, n, i+1, a[i+1]+a[i+2], a[i+3]+a[i+4]);
        }
}
