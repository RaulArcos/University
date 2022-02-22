#include "puzle.h"

int main() {
 //pruebas del código generado
 int op;
 tEstado n,a;
 a=estadoInicial();

 for (op=1; op<=NUM_OPERADORES; op++) {
 dispOperador(op);
 if (esValido(op, a)){
n=aplicaOperador(op,estado);
dispEstado(n);
}//if
else
printf("\n Operador no válido\n");
 } //for
}//main