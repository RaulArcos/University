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
    return pseudocompletoRec(A,B,A.raiz(),B.raiz);
}
template <typename T>
bool similaresAbinRec(Abin<T>& A, Abin<T>& B,const typename Abin<T>::nodo na,const typename Abin<T>::nodo nb){
    if(na == nb == Abin<T>::NODO_NULO)
        return true;
    else 
        
}


#endif 