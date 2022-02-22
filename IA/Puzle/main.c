#include "puzle.h"
#include <stdio.h>
#include <stdlib.h>

// Para compilar gcc -o main main.c puzle.h puzleAlum.c
// El movimiento incorrecto, no dice nada, pero tampoco realiza la acción
// La matriz se muestra en todo momento actualizada

int main(){

    tEstado *puzzle = estadoInicial();
    int op, coste = 0;

    printf("ESTADO INICIAL\n");
    dispEstado(puzzle);
    printf("Iguales = %i",iguales(estadoObjetivo(),puzzle));
    while(testObjetivo(puzzle) == 0){
        
        printf("EL ESI PUZZLE.\n1) ARRIBA\n2) ABAJO\n3) IZQUIERDA\n4) DERECHA\nELIJA MOVIMIENTO: ");
        scanf("%d", &op);

        dispOperador(op);
        if (esValido(op, puzzle) != 0){
            puzzle = aplicaOperador(op, puzzle);
        }
        else printf("\nMovimiento no valido");


        system("cls");
        printf("ESTADO ACTUALIZADO\n");
        dispEstado(puzzle);
        
    }

    printf("FELICIDADES, HAS TERMINADO EL PUZZLE :D\n");

    return 0;


}

/*int main() {
 //pruebas del código generado
    int op;
    tEstado *n,*a;
    a=estadoInicial();

    for (op=1; op<=NUM_OPERADORES; op++) {
        dispOperador(op);
        if (esValido(op, a)){
            n=aplicaOperador(op,a);
            dispEstado(n);
        }//if
        else
            printf(“\n Operador no válido\n”);
    } //for
}//main
*/