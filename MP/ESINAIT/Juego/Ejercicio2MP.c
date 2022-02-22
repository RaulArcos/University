#include <stdio.h>

void introducir(int);


int main(){

  int num;

  introducir(num);


}


void introducir (int n){

int aux,menor=10;

puts("Introduce un numero para saber su iesimo");

scanf("%i",&n);

  while (n>0){

    aux = n%10;
    n = n/10;

    if ( aux < menor ) {
      menor = aux;
    }

  }
printf("%i",menor);
}
