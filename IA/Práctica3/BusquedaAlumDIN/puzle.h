/*******************************************/
/* 		      PUZLE.H                      */
/*						                   */
/* Asignatura: Inteligencia Artificial     */
/* Grado en Ingenieria Informatica - UCA   */
/*******************************************/
#ifndef _PUZLE_H_
#define  _PUZLE_H_

#define ARRIBA 1
#define ABAJO 2
#define IZQUIERDA 3
#define DERECHA 4
#define NUM_OPERADORES 4
#define N 3


#ifndef _tEstado_
#define _tEstado_
   typedef struct {
        int celdas[N][N];
        int fila[N*N], col[N*N];
   } tEstado;
#endif

/*
static int puzle_inicial[N][N]=
{
  {0,1},
  {3,2}
};

static int puzle_final[N][N]=
{
  {1,2},
  {0,3}
};
*/
static int puzle_inicial[N][N]=
{
  {2,1,3},
  {4,5,7},
  {0,8,6}
}; 


static int puzle_final[N][N]=
{
  {1,2,3},
  {4,5,6},
  {7,8,0}
};

/* A partir de una configuraci�n de fichas construye un estado v�lido para el problema
  de acuerdo al tipo de datos tEstado. */
tEstado *crearEstado(int celdas[N][N]);

/* Genera el estado inicial a partir de crearEstado y puzle_inicial. */
tEstado *estadoInicial();


/* Devuelve el coste de aplicar el operador. */
int coste(unsigned op, tEstado *estado);

/* Muestra el contenido del puzle. */
void dispEstado(tEstado *estado);

/* Muestra el nombre de cada operador: Arriba, Abajo, Izquierda, Derecha. */
void dispOperador(unsigned op);

/* Genera el estado final a partir de crearEstado y puzle_final. */
tEstado *estadoObjetivo();


/* Comprueba si es posible aplicar un operador a una configuraci�n determinada para el puzle.
  Devuelve 1 si el movimiento es v�lido y 0 en otro caso. */
int esValido(unsigned op, tEstado* estado);

/* Aplica un operador a una configuraci�n concreta del puzle.
  Devuelve la nueva configuraci�n del tablero tras el movimiento. */
tEstado *aplicaOperador(unsigned op, tEstado *estado);

/* Devuelve 1 si dos estados son iguales y 0 en caso contrario. */
int iguales(tEstado *s, tEstado *t);

/* Devuelve 1 si un estado es igual al estado objetivo. */
int testObjetivo(tEstado *estado);

/*Saca la posicion de la ficha con valor 0*/
void esBlanco(int *fil0, int *col0, tEstado *estado);
#endif