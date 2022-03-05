/*
Práctica 2 EDNL by Raúl Arcos Herrera
*/

#ifndef P2_H
#define P2_H

#include "../abin.h"
#include "../abin_E-S.h"
#include <stdlib.h>

/*
1. Dos árboles binarios son similares cuando tienen idéntica estructura de ramificación,
es decir, ambos son vacíos, o en caso contrario, tienen subárboles izquierdo y derecho
similares. Implementa un subprograma que determine si dos árboles binarios son
similares.
*/
template <typename T>
bool similaresAbin(Abin<T>& A,Abin<T>& B){
    return similaresAbinRec(A.raiz(),B.raiz(),A,B);
}
template <typename T>
bool similaresAbinRec(const typename Abin<T>::nodo na,const typename Abin<T>::nodo nb, Abin<T>& A, Abin<T>& B){

    if (na == Abin<T>::NODO_NULO && nb == Abin<T>::NODO_NULO)
        return true;
    else if (na != Abin<T>::NODO_NULO && nb != Abin<T>::NODO_NULO)
        return (similaresAbinRec(A.hijoIzqdo(na), B.hijoIzqdo(nb), A, B) && similaresAbinRec(A.hijoDrcho(na), B.hijoDrcho(nb), A, B));
    else
        return false;
}
/*
2. Para un árbol binario B, podemos construir el árbol binario reflejado BR cambiando los
subárboles izquierdo y derecho en cada nodo. Implementa un subprograma que devuelva
el árbol binario reflejado de uno dado.
*/
template <typename T>
Abin<T>& reflejado( Abin<T> &A)
{
    Abin<T> B;
    B.insertarRaiz(A.elemento(A.raiz()));
    reflejadoRec(A.raiz(),B.raiz(),A,B);

    return B;
}

template <typename T>
void reflejadoRec(typename Abin<T>::nodo na, typename Abin<T>::nodo nb, const Abin<T> &A, Abin<T> &B)
{
    if(A.hijoIzqdo(na) != Abin<T>::NODO_NULO){
        B.insertarHijoDrcho(nb,A.elemento(A.hijoIzqdo(na)));
        reflejadoRec(A.hijoIzqdo(na), B.hijoDrcho(nb), A, B);
    }
        
    if(A.hijoDrcho(na) != Abin<T>::NODO_NULO){
        B.insertarHijoIzqdo(nb,A.elemento(A.hijoDrcho(na)));
        reflejadoRec(A.hijoDrcho(na), B.hijoIzqdo(nb), A, B);
    }
}       

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

#endif 