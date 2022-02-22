/*3.- Diseñe una función recursiva que determine si en un vector A de n enteros existen dos parejas consecutivas de elementos
tales que sus sumas sean idénticas.*/

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
int parejasFinal (int *, int, int);

int main (){
    int i, a[N] = {0, 8, 2, 6, 4, 5, 6, 7, 8, 9};

    printf("\n\na = {0, 1, 2, 6, 4, 5, 5, 7, 8, 9}\n\n");

    if (parejas(a, N) == 1) printf("\n\nHay dos parejas consecutivas cuyas sumas son iguales\n");
    else printf("\n\nNo hay dos parejas consecutivas cuyas sumas son iguales\n");

    return 0;
}

int parejas (int *a, int n){
return parejasFinal(a, n, a[n-3]);
}

int parejasFinal (int *a, int n, int fin){

    if (a[0]+a[1] == a[2]+a[3]) {
        /*printf("a[0] = %i\na[n-3] = %i\n", *a, fin);
        printf("%i + %i = %i\n", a[0], a[1], a[0]+a[1]);
        printf("%i + %i = %i\n\n", a[2], a[3], a[2]+a[3]);*/
        return 1;
    }

    else {
        if (a[0] == fin) return 0;
        else {
        /*printf("a[0] = %i\na[n-3] = %i\n", a[0], fin);
        printf("%i + %i = %i\n", a[0], a[1], a[0]+a[1]);
        printf("%i + %i = %i\n\n", a[2], a[3], a[2]+a[3]);*/
        parejasFinal (a+1, n, fin);
        }
    }
}
