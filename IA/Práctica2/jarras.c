/*******************************************/
/* 		      JARRAS.C                      */
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


int estadoObjetivo(tEstado *estado)
{
   return (estado->J4 == 2);
}

int coste(unsigned op, tEstado *estado)
{
   return 1;
}

/* VISUALIZACI�N DE ESTADOS Y OPERADORES*/


void dispEstado(tEstado *estado)
{
   printf("Jarra 4:%i y Jarra 3: %i\n",estado->J4,estado->J3);
}


void dispOperador(unsigned op)
{
   switch(op)
   {
      case LLENAR4: printf("Llenar 4\n"); break;
      case LLENAR3: printf("Llenar 3\n"); break;
      case VACIAR4: printf("vaciar 4"); break;
      case VACIAR3: printf("vaicar 3\n"); break;
      case VACIAR3EN4: printf("vaciar 3 en 4\n"); break;
      case VACIAR4EN3: printf("vaciar 4 en 3\n"); break;
      case LLENAR3CON4: printf("llenar 3 con 4\n"); break;
      case LLENAR4CON3: printf("llenar 4 con 3\n"); break;
   }
}

int testObjetivo(tEstado *estado)
{
  return (estado->J4==2);

}


int esValido(unsigned op, tEstado *estado)
{
   int valido = 0;

    switch(op){
        case LLENAR4 : valido = estado->J4 < 4; break;
        case LLENAR3 : valido = estado->J3 < 3; break;
        case VACIAR4 : valido = estado->J4 > 0; break;
        case VACIAR3 : valido = estado->J3 > 0; break;
        case LLENAR4CON3 : if(estado->J4 < 4 && estado->J4 + estado->J3 >= 4 && estado->J3 > 0) valido = 1; break;
        case LLENAR3CON4 : if(estado->J3 < 3 && estado->J3 + estado->J4 >= 3 && estado->J4 > 0) valido = 1; break;
        case VACIAR3EN4 : if(estado->J3 + estado->J4 <= 4 && estado->J3 > 0) valido = 1; break;
        case VACIAR4EN3 : if(estado->J3 + estado->J4 <= 3 && estado->J4 > 0) valido = 1; break;
    }

    return valido;
}


tEstado *aplicaOperador(unsigned op, tEstado *estado)
{ 
      tEstado *nuevo= (tEstado *) malloc(sizeof(tEstado));
      memcpy(nuevo, estado,sizeof(tEstado));  // Hace una copia del estado
      
      switch(op){
      case LLENAR4: nuevo->J4=4  ;break;
      case LLENAR3: nuevo->J3=3  ;break;
      case VACIAR4: nuevo->J4=0  ;break;
      case VACIAR3: nuevo->J3=0  ;break;
      case VACIAR3EN4: nuevo->J4 = nuevo->J3 + nuevo->J4; nuevo->J3 = 0;break;
      case VACIAR4EN3: nuevo->J3 = nuevo->J4+nuevo->J3;nuevo->J4=0;break;
      case LLENAR3CON4: nuevo->J3 = nuevo->J4 - (nuevo->J3+1); nuevo->J4 = nuevo->J4 - nuevo->J3;break;
      case LLENAR4CON3: nuevo->J4 = 4; nuevo->J3 = nuevo->J3 + nuevo->J4 - 4;break;
      }
      
return nuevo;
}
