//Determina y define los operadores que se van a usar

#ifndef _SEMINARIO01_H_
#define _SEMINARIO01_H_

#define N 3
#define ARRIBA 1
#define ABAJO 2
#define IZQUIERDA 3
#define DERECHA 4
#define NUM_OPERADORES 4
//Definimos el contenido de la estructura tEstado
typedef struct 
{
    int tablero[N][N];
    int  fila[N*N], columna[N*N]; 

} tEstado ;

tEstado *estadoInicial();                           //Estas 3 funciones tendrán siempre el mismo
int testObjetivo(tEstado *estado);                  //prototipo, pero su implementación concreta 
int esValido(unsigned op, tEstado *s);              //dependerá del problema particular planteado.
tEstado *aplicaOperador( unsigned op, tEstado *s);  //De esta manera se podrá reutilizar el código de 
                                                    //búsqueda con independencia del problema