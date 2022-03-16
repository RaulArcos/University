/*
Práctica 2 EDNL by Raúl Arcos Herrera
*/

#ifndef P2EJ3_H
#define P2EJ3_H

#include <string>
#include "../abin.h"
#include "../abin_E-S.h"
#include <stdlib.h>

double operacionesAbin(const Abin<string>& A);
double operacionesAbinRec(typename Abin<string>::nodo n,const Abin<string>& A);

/*
El TAD árbol binario puede albergar expresiones matemáticas mediante un árbol de
expresión. Dentro del árbol binario los nodos hojas contendrán los operandos, y el resto
de los nodos los operadores.
a) Define el tipo de los elementos del árbol para que los nodos puedan almacenar
operadores y operandos.
    
    Los nodos del árbol almacenarán caracteres, depende de si es hoja o no, el nodo almacenará un operando u operador respectivamente.



b) Implementa una función que tome un árbol binario de expresión (aritmética) y
devuelva el resultado de la misma. Por simplificar el problema se puede asumir que el
árbol representa una expresión correcta. Los operadores binarios posibles en la expresión
aritmética serán suma, resta, multiplicación y división.
*/


//HABIA QUE HACERLO CON UNA STRUCTURA QUE TUBIESE UN CAMPO DOUBLE Y OTRO CAMPO ENUM

double operacionesAbin(const Abin<string>& A){
    if(A.arbolVacio())
        return 0;
    else 
        return operacionesAbinRec(A.raiz(),A);
}

double operacionesAbinRec(typename Abin<string>::nodo n,const Abin<string>& A){
    
    double res;
    if(n == Abin<string>::NODO_NULO)
        return 0;
    else{
        if(A.hijoIzqdo(n) == Abin<string>::NODO_NULO && A.hijoDrcho(n) == Abin<string>::NODO_NULO)
            res = stod(A.elemento(n));
        else{
            double numizq = operacionesAbinRec(A.hijoIzqdo(n),A);
            double numdrch = operacionesAbinRec(A.hijoDrcho(n),A);
            switch(A.elemento(n)[0]){
                case '+':   res = (numizq + numdrch); break;
                case '-':   res = (numizq - numdrch); break;
                case '*':   res = (numizq * numdrch); break;
                case '/':   res = (numizq / numdrch); break;
            }
        }
        return res;
    }
}


#endif 