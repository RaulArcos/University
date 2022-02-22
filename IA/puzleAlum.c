/*******************************************/
/* 		      PUZLE.C                      */
/*						                   */
/* Asignatura: Inteligencia Artificial     */
/* Grado en Ingenieria Informatica - UCA   */
/*******************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "puzle.h"



tEstado *crearEstado(int puzle[N][N])
{
   tEstado *estado = (tEstado *) malloc(sizeof(tEstado));
   int i, j, ficha;

   for (i=0;i<N;i++)
      for (j=0;j<N;j++)
      {
         ficha=puzle[i][j];
         estado->celdas[i][j]=ficha;
         estado->fila[ficha]=i;
         estado->col[ficha]=j;
      }
   return estado;
}


tEstado *estadoInicial()
{
   return crearEstado(puzle_inicial);
}


tEstado *estadoObjetivo()
{
   return crearEstado(puzle_final);
}

int coste(unsigned op, tEstado *estado)
{
   return 1;
}

/* VISUALIZACI�N DE ESTADOS Y OPERADORES*/


void dispEstado(tEstado *estado)
{
   int i,j;

   for (i=0; i<N; i++)
   {
      for (j=0; j<N; j++)
         printf("%d",estado->celdas[i][j]);
      printf("\n");
   }
   printf("\n");
}


void dispOperador(unsigned op)
{
   switch(op)
   {
      case ARRIBA:    printf("Movimiento ARRIBA:\n"); break;
      case ABAJO:     printf("Movimiento ABAJO:\n"); break;
      case IZQUIERDA: printf("Movimiento IZQUIERDA:\n"); break;
      case DERECHA:   printf("Movimiento DERECHA:\n"); break;
   }
}

// FUNCIONES QUE SE HAN DE IMPLEMENTAR EN LA PRACTICA 1

// Función auxiliar para comprobar si dos puzles tienen las fichas colocadas en el mismo orden en el tablero
int iguales(tEstado *s, tEstado *t)  //
{
  int i,j,mem=0;  
   for (i=0; i<N; i++)
   {
      for (j=0; j<N; j++)
      {
      if (s->celdas[i][j] == t->celdas[i][j]){mem = 1;}
      }
   }
   
return mem;
}


int testObjetivo(tEstado *estado)
{
  tEstado estadoFinal;
  estadoFinal = *crearEstado(puzle_final[N][N]);
  return iguales(estado, &estadoFinal);

return 0;
}


int esValido(unsigned op, tEstado *estado)
{
    int valido;
    int i,j;
    
      i = estado->fila[0];
      j = estado->col[0];

    switch(op){

      case ARRIBA: valido = estado->celdas[i][j-1] != 0; break;
      case ABAJO: valido = estado->celdas[i][j+1] != 0; break;
      case IZQUIERDA: valido = estado->celdas[i-1][j] != 0; break;
      case DERECHA: valido = estado->celdas[i+1][j] != 0; break;
      default: valido = 0;
    }
return valido;
}


tEstado *aplicaOperador(unsigned op, tEstado *estado)
{ 
      int i, j, auxiliar, filaN, columnaN;
      i = estado->fila[0];
      j = estado->col[0];
      tEstado *nuevo= (tEstado *) malloc(sizeof(tEstado));
      memcpy(nuevo, estado,sizeof(tEstado));  // Hace una copia del estado
     
      switch(op){
      case ARRIBA:     nuevo->fila[0] = i-1; break;
      case ABAJO:      nuevo->fila[0] = i+1; break;
      case IZQUIERDA:   nuevo->columna[0] = j-1; break;
      case DERECHA:     nuevo->columna[0] = j+1; break;
      }
    
     filaN = nuevo->fila[0];
     columnaN = nuevo->col[0];
     auxiliar = nuevo->celdas[filaN][columnaN];
     nuevo->celdas[filaN][columnaN] = nuevo->celdas[i][j];
     nuevo->celdas[i][j] = auxiliar;
   
return nuevo;
}




