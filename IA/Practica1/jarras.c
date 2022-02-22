/*******************************************/
/* 		      PUZLE.C                      */
/*						                   */
/* Asignatura: Inteligencia Artificial     */
/* Grado en Ingenieria Informatica - UCA   */
/*******************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "jarras.h"






tEstado *estadoInicial()
{
tEstado *estado = (tEstado *) malloc(sizeof(tEstado));
estado->J4=0;
estado->J3=0;
return estado;
}


tEstado *estadoObjetivo()
{
   return tEstado->J4 == 2;
}

int coste(unsigned op, tEstado *estado)
{
   return 1;
}

/* VISUALIZACI�N DE ESTADOS Y OPERADORES*/


void dispEstado(tEstado *estado)
{
   printf("(%i,%i)",estado->J4,estado->J3);
}


void dispOperador(unsigned op)
{
   switch(op)
   {
      case LLENAR4: printf("Llenar 4:\n"); break;
      case LLENAR3: printf("Llenar 3:\n"); break;
      case VACIAR4: printf("vaciar 4"); break;
      case VACIAR3: printf("vaicar 3:\n"); break;
      case VACIAR3EN4: printf("vaciar 3 en 4:\n"); break;
      case VACIAR4EN3: printf("vaciar 4 en 3:\n"); break;
      case LLENAR3CON4: printf("llenar 3 con 4:\n"); break;
      case LLENAR4CON3: printf("llenar 4 con 3:\n"); break;
   }
}

int testObjetivo(tEstado *estado)
{
  return (estado->J4==2);

}


int esValido(unsigned op, tEstado *estado)
{
    int valido;
 
     switch(op){

      case LLENAR4: valido = estado->J4==0  ;break;
      case LLENAR3: valido = estado->J3==0  ;break;
      case VACIAR4: valido = estado->J4>0  ;break;
      case VACIAR3: valido = estado->J3>0  ;break;
      case VACIAR3EN4: if((estado->J4+estado->J3 <= 4) && estado->J3>0){valido=1;}  ;break;
      case VACIAR4EN3: if((estado->J4+estado->J3 <= 3) && estado->J4>0){valido=1;}  ;break;
      case LLENAR3CON4: valido = estado->J4==0  ;break;
      case LLENAR4CON3: valido = estado->J4==0  ;break;
      default: valido = 0;
    }
return valido;
}


tEstado *aplicaOperador(unsigned op, tEstado *estado)
{ 
      int i, j, auxiliar, filaN, columnaN;
      tEstado *nuevo= (tEstado *) malloc(sizeof(tEstado));
      memcpy(nuevo, estado,sizeof(tEstado));  // Hace una copia del estado
     
      switch(op){
      case LLENAR4: estado->J4=4  ;break;
      case LLENAR3: estado->J3=3  ;break;
      case VACIAR4: estado->J4=0  ;break;
      case VACIAR3: estado->J3=0  ;break;
      case VACIAR3EN4: estado->J4 = estado->J4+estado->J3;break;
      case VACIAR4EN3: estado->J3 = estado->J4+estado->J3;break;
      case LLENAR3CON4: estado->J4==0  ;break;
      case LLENAR4CON3:  estado->J4==0  ;break;
      }
    
   
   
return nuevo;
}
