/*******************************************/
/* 		      robo.H                      */
/*						                   */
/* Asignatura: Inteligencia Artificial     */
/* Grado en Ingenieria Informatica - UCA   */
/*******************************************/
#include <string.h>
#include <stdlib.h>


#define IZQ 1
#define DRCH 2

#define NUM_OPERADORES 2
#define N 8

#ifndef _tEstado_
#define _tEstado_
   typedef struct {
        int fila[N],DL,DB;
   } tEstado;
#endif


static int vector_inicial[N]=
{
    4,3,2,5,7,1,8,6
};

tEstado *estadoInicial();

/* Devuelve el coste de aplicar el operador. */
int coste(unsigned op, tEstado *estado);

/* Muestra el contenido del puzle. */
void dispEstado(tEstado *estado);

/* Muestra el nombre de cada operador: Arriba, Abajo, Izquierda, Derecha. */
void dispOperador(unsigned op);

/* Comprueba si es posible aplicar un operador a una configuraci�n determinada para el puzle.
  Devuelve 1 si el movimiento es v�lido y 0 en otro caso. */
int esValido(unsigned op, tEstado* estado);

/* Aplica un operador a una configuraci�n concreta del puzle.
  Devuelve la nueva configuraci�n del tablero tras el movimiento. */
tEstado *aplicaOperador(unsigned op, tEstado *estado);

/* Devuelve 1 si un estado es igual al estado objetivo. */
int testObjetivo(tEstado *estado);