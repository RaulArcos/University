
#include <stdio.h>

int main(){

int v[4] = {1,2,3,4}, cont = 0;

int max = v[0], min = v[0];

funcion_recursiva ( v , cont  );


  return 0;
}



void funcion_recursiva (int contador , int v[4] , int max, int min ){

    if ( cont == 4 ){




    }

    else {

      if ( max <= v[contador]){

        max = v[contador];

      }

      if ( min >= v[contador]){

        min = v[contador];

      }

      funcion_recursiva(contador+1,v[4], max, min )

    }

prinf("\nValor maximo = %i y minimo = %i",max,min);
}
