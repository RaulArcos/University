#include <stdio.h>

//Declaramos las funciones que vamos a utilizar
void introducir_vector(int v[],int);
void recursiva(int v[],int,int,int);


 int main(){
//Utilizare tamaño para el tamaño del vector, el vector, el contador para la recursividad y la mameoria para comprrobar si es o no pareja.
   int tam=0,vector[tam], cont = 0,mem=0;
//LLevo el vector y al tamaño a la funcion introducir vector para que el usuario elija el tamaño y los numeros de este
   introducir_vector(vector,tam);
//LLevo al vector, tamaño, contador para recursividad y memoria
   recursiva(vector,tam,cont,mem);

 }


// Cabecera: void introducir_vector(int v[],int t)
// {P} Vector declarado
// {Q} Se le asignan valores al vector y se sabe el tamaño de este
void introducir_vector(int v[],int t){



  int i;

  printf("Introduce el tamaño del vector:\t");
  scanf("%i",&t);
//Con este contador se introducen los datos al vector
  for(i=0;i<t;i++){
    printf("\nElemento %i:  ",i+1);
    scanf("%i",&v[i]);
  }
}


// Cabecera: void recursiva(int v[],int t,int c,int mem)
// {P} Introducir vector
// {Q} Devuelve Si tiene pareja o no
void recursiva(int v[],int t,int c,int mem){

  int i;
//hasta que el contador alcance el tamaño, la recursiva continua
  if(c == t){

  }

  else {
//De esta manera comparamos la suma de los elementos consecutivos
      if ((v[c]+v[c+1]) == (v[c+2] + v[c+3])){
//Si da pareja, le pondremos sumaremos 1 a la memoria para usarla mas tarde
        mem++;

      }
//si no, vuelve a repetirse
    recursiva(v,t,c+1,mem);

  }
  //Con esto, si se da el caso de la suma de parejas conscutiva, la memoria deberia ser
  //mas de uno, por lo que imprimiria el primer mensaje.
if ( mem >= 1){
  printf("\nSi hay suma de parejas");
} else printf("\nNo hay suma de parejas");
}
