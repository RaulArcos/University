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

    if((na == Abin<T>::NODO_NULO && nb != Abin<T>::NODO_NULO) || (na != Abin<T>::NODO_NULO && nb == Abin<T>::NODO_NULO) || )
        return false;
    else
        return true && similaresAbinRec(A.hijoIzqdo(na),B.hijoIzqdo(nb),A,B) && similaresAbinRec(A.hijoDrcho(na),B.hijoDrcho(nb),A,B);
}


#endif 