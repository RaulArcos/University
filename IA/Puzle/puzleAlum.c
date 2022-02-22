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

// Funci�n auxiliar para comprobar si dos puzles tienen las fichas colocadas en el mismo orden en el tablero
int iguales(tEstado *s, tEstado *t)  //
{
   int i, j, ficha1, ficha2, boolean = 1;
   for(i=0; i<N; i++){
      for(j=0; j<N; j++){
         ficha1 = s->celdas[i][j];
         ficha2 = t->celdas[i][j];

         if(ficha1!=ficha2) boolean = 0;
          
       }

    }
   
   return boolean;
}


int testObjetivo(tEstado *estado)
{
    return iguales(estado, estadoObjetivo());
return 0;
}


int esValido(unsigned op, tEstado *estado)
{
   int fil0, col0, boolean = 1;
   esBlanco(&fil0, &col0, estado);
   
   switch(op){
      case ARRIBA: if(fil0 == 0) boolean = 0; break;
      case ABAJO: if(fil0 == N-1) boolean = 0; break;
      case DERECHA: if(col0 == N-1) boolean = 0; break;
      case IZQUIERDA: if(col0 == 0) boolean = 0; break;
   
   }

   return boolean;
}


tEstado *aplicaOperador(unsigned op, tEstado *estado)
{
   tEstado *nuevo= (tEstado *) malloc(sizeof(tEstado));
   memcpy(nuevo, estado,sizeof(tEstado));  // Hace una copia del estado
   
   int fil0, col0;

   switch(op){
      case ARRIBA: 
         if(esValido(ARRIBA, nuevo) == 1){
            esBlanco(&fil0, &col0, nuevo);
            nuevo->celdas[fil0][col0] = nuevo->celdas[fil0-1][col0];
            nuevo->celdas[fil0-1][col0] = 0;
            nuevo->fila[0] = fil0 - 1;
            nuevo->fila[nuevo->celdas[fil0][col0]] = fil0;
         } break;

      case ABAJO:
         if(esValido(ABAJO, nuevo) == 1){
            esBlanco(&fil0, &col0, nuevo);
            nuevo->celdas[fil0][col0] = nuevo->celdas[fil0+1][col0];
            nuevo->celdas[fil0+1][col0] = 0;
            nuevo->fila[0] = fil0 + 1;
            nuevo->fila[nuevo->celdas[fil0][col0]] = fil0;
         } break;
      
      case DERECHA:
         if(esValido(DERECHA, nuevo) == 1){
            esBlanco(&fil0, &col0, nuevo);
            nuevo->celdas[fil0][col0] = nuevo->celdas[fil0][col0+1];
            nuevo->celdas[fil0][col0+1] = 0;
            nuevo->col[0] = col0 + 1;
            nuevo->col[nuevo->celdas[fil0][col0]] = col0;
         } break;
      
      case IZQUIERDA:
          if(esValido(IZQUIERDA, nuevo) == 1){
            esBlanco(&fil0, &col0, nuevo);
            nuevo->celdas[fil0][col0] = nuevo->celdas[fil0][col0-1];
            nuevo->celdas[fil0][col0-1] = 0;
            nuevo->col[0] = col0 - 1;
            nuevo->col[nuevo->celdas[fil0][col0]] = col0;
         } break;

   }
   
   return nuevo;
}

void esBlanco(int *fil0, int *col0, tEstado *estado){

   int i, j;

   for(i=0; i<N; i++){
      for(j=0; j<N; j++){
         if(estado->celdas[i][j] == 0){
            *fil0 = i;
            *col0 = j;
         }
      }
   }
}


