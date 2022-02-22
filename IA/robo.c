/*******************************************/
/* 		      JARRAS.C                      */
/*						                   */
/* Asignatura: Inteligencia Artificial     */
/* Grado en Ingenieria Informatica - UCA   */
/*******************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "robo.h"


tEstado *crearEstado(int vector[N])
{
   tEstado *estado = (tEstado *) malloc(sizeof(tEstado));
   int i;

   for (i=0;i<N;i++)
      {
         estado->fila[i] = vector[i];
      }
   return estado;
}



tEstado *estadoInicial()
{
return crearEstado(vector_inicial);
}

int coste(unsigned op, tEstado *estado)
{
   return 1;
}

/* VISUALIZACI�N DE ESTADOS Y OPERADORES*/


void dispEstado(tEstado *estado)
{
   printf("Ladrón = %i y Banco = %i\n",estado->DL,estado->DB);
}


void dispOperador(unsigned op)
{
   switch(op)
   {
      case IZQ: printf("Has cogido saco izq\n"); break;
      case DRCH: printf("Has cogido saco drch 3\n"); break;
   }
}

int testObjetivo(tEstado *estado)
{
  return (estado->DL > estado ->DB);

}


int esValido(unsigned op, tEstado *estado)
{
   int valido = 0;

    for(int i=0;i<N;i++)
    {

        if(estado->fila[i] == 0){
            valido++;
        }
    
    }
    if (valido == 8){
        return 0;
    }else{
    return 1;
    }
    
}



tEstado *aplicaOperador(unsigned op, tEstado *estado)
{ 
      tEstado *nuevo= (tEstado *) malloc(sizeof(tEstado));
      memcpy(nuevo, estado,sizeof(tEstado));  // Hace una copia del estado
      
      switch(op){
      case IZQ :
          for(int i=0;i<N;i++)
          {
              if(estado->fila[i] !=0){
                 estado->DL = estado->fila[i] + estado->DL;
                 estado->fila[i] = 0;
              }
          }
          for(int i=7; i>=0;i--)
          {
              if(estado->fila[i] !=0){
                 estado->DB = estado->fila[i] + estado->DB;
                 estado->fila[i] = 0;
              }

          }
          
      ;break;
      case DRCH: nuevo->J3=3  ;break;
      }
      
return nuevo;
}
