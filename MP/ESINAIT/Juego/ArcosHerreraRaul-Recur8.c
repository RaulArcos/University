/*EJERCICIO 8, En un vector de enteros se genera un «cambio de tendencia» cuando dada una
secuencia creciente o decreciente de números que ocupan posiciones consecutivas
del vector, el elemento que le sucede es inferior o superior respectivamente. Dado
un vector de N enteros, diseñe una función recursiva que calcule el número de
«cambios de tendencia» que contiene dicho vector.
*/

#include <stdio.h>

//Para este Ejercicio utilizare 3 funciones, nombradas de la siguiente manera:

int tamano_vector();
void introducir_vector(int v[],int);
int recursiva(int v[],int,int,int,int);


int main(){
//Las variables a utilizar son las siguientes:
  int tam=0, vec[tam],cont = 0, mem = 0,result,tendencia=0;
//Para conseguir el tamaño del vector he necesitado meterlo en una funcion separada
  tam = tamano_vector();
//LLevo los valores a introducir vector para que me devuelva el vector lleno.
  introducir_vector(vec,tam);
//Ahora llamamos a la funcion recursiva, que empezara con los siguientes valores:
// vec, tam = tamaño dado, mem = 0, cont = 0, tendencia = 0
  result = recursiva(vec,tam,mem,cont,tendencia);
//Aqui esta el printf para mostrar el resultado
  printf("\n\nHay %i Cambios de tendencia",result);

  return 0;
}

//
//
//
int tamano_vector(){

int i;
//Pide el tamaño vector, lo he realizado de esta manera para facilitar el proceso y ahorrar el uso de punteros inncecesarios
printf("Introduce el tamano del vector = ");
scanf("%i",&i);
return i;
}


//
//
//
void introducir_vector(int v[],int t){

  int i;
//LLamamos a el relleno del vector
  for(i=0;i<t;i++){
    printf("\nElemento %i:  ",i+1);
    scanf("%i",&v[i]);
  }
}

int recursiva(int v[],int t,int m,int c,int ten){

  int i;

//hasta que el contador alcance el tamaño, la recursiva continua
  if(c == t-1){
//La razon de t-1, es debido a que va comparando de dos en dos, por lo que si el vectro
// es de tamaño 4 y va por el contador 3, coge al elemento 3 y 4 directamente.
  }

  else {
//He utilizado el sistema de tendencias, no ha salido como esperaba y no logro dar con la solucion
      if (v[c] < v[c+1]){

      if (ten == 0){
        ten = 1;
      }
      if(ten == 2){
        ten = 1;
        m++;
      }

      if (v[c] > v[c+1]){

        if (ten == 0){
          ten = 2;
        }
        if(ten == 1){
          ten = 2;
          m++;
        }
      }
      if(v[c] == v[c+1]){

        if (ten == 1 || ten == 2){
          ten = 0;
        }
//De esta manera, cuando detecte cambios de tendencia deberia sumar a la memoria,
//pero la memoria al final da numeros que no tienen sentido


      }
//La funcion vuelve a repetirse hasta tener contador a 0
    return recursiva(v,t,c+1,m,ten);

  }
}
//Tras pasar por todo el contador, la funcion devuelve a m, de tal manera que se printea en el int main.
return m;
}
