#include "seminario1ia.h"

int testObjetivo(tEstado *estado){
    return();
}

void encontrarHueco(int*i, int*j){
for (i = 0;i < N; i++){
    for(j=0;j < N; i++){
        if(tablero[i][j] == 0){
        break;
        } 
    }
}    
}

int esValido(unsigned op, tEstado *s){
    int i,j;
    encontrarHueco(i,j);
    int valido;
    switch(op)
    {
        case ARRIBA: valido = s-> tablero[i][j-1] != 0;
        break;
        case ABAJO: valido = s-> tablero[i][j+1] != 0;
        break;
        case IZQUIERDA: valido = s-> tablero[i-1][j] != 0;
        break;
        case DERECHA: valido = s-> tablero[i-1][j] != 0;
        break;
        default: valido = 0;
    }
    return valido;
}




