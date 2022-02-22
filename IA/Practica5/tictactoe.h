/*******************************************/
/* 		    tictactoe.h                    */
/*       Estrategia MiniMax                */
/*						                   */
/* Asignatura: Inteligencia Artificial     */
/* Grado en Ingenieria Informatica - UCA   */
/*******************************************/

#define N 9

typedef struct tNodo {
        int celdas[N];
        int vacias;
} tNodo;

static int tablero_inicial[N] ={0,0,0, 0,0,0, 0,0,0};

// las posiciones ser�n numeradas de 0 a 8 de la siguiente forma:
//0 1 2
//3 4 5
//6 7 8

/*tNodo *crearNodo(int celdas[N])
 celdas: son las celdas del tablero,
 devuelve:Un nodo nuevo a partir de las celdas recibidas.
*/
tNodo *crearNodo(int celdas[N]);

/*tNodo *NodoInicial()
 devuelve: Devuelve el nodo Inicial.
*/
tNodo *NodoInicial();


/*tNodo *aplicaJugada(tNodo *actual, int jugador, int jugada)
 actual: es el tablero actual,
 jugador: la marca del jugador que tiene el turno
 jugada: indica en qu� posici�n del tablero pondr� la marca
 devuelve: el nuevo Nodo tras aplicar la jugada */
tNodo *aplicaJugada(tNodo *actual, int jugador, int jugada);

/*int esValida(tNodo *actual, int jugada)
 actual: tablero actual-
 jugada: Indica en que posicion del tablero pondrá la marca.
*/
int esValida(tNodo *actual, int jugada);

//int terminal(tNodo *actual, int jugador)
// funcion que determina si un nodo es terminal, ha ganado MAX o MIN
// actual: tablero actual
// jugador: 1 si es Max -1 si es Min
//devuelve:  si ha gando MAX 100, si ha ganado MIN -100, empate 0
// si no es terminal tambi�n devuelve 0
int terminal(tNodo *actual);

/*void dispNodo(tNodo *s);
 s:Nodo que queremos imprimir en pantalla
 Imprime el nodo s en pantalla.
*/
void dispNodo(tNodo *s);
/*int opuesto( int jugador);
 jugador: recibe 1 si es max o -1 si es min.
*/
int opuesto( int jugador);
/*int lleno(tNodo *s);
*/
int lleno(tNodo *s);




