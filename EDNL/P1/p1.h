/*
Práctica 1 EDNL by Raúl Arcos Herrera
*/

#ifndef P1_H
#define P1_H

#include "../abin.h"
#include "../abin_E-S.h"
#include <stdlib.h>

/*
1. Implementa un subprograma que calcule el número de nodos de un árbol binario.
*/
template <typename T>
int numNodos(const Abin<T>& A){
    return numNodosRec(A,A.raiz());
}

template <typename T>
int numNodosRec(const Abin<T>& A, const typename Abin<T>::nodo n){
    
    if(n == Abin<T>::NODO_NULO)
        return 0;  
    else 
        return 1 + numNodosRec(A,A.hijoIzqdo(n)) + numNodosRec(A,A.hijoDrcho(n));  
}

/*
2. Implementa un subprograma que calcule la altura de un árbol binario. 
*/
template <typename T>
int alturaAbin(const Abin<T>& A){
    return alturaAbinRec(A,A.raiz());
}
template <typename T>
int alturaAbinRec(const Abin<T>&A, const typename Abin<T>::nodo n){
    if(n == Abin<T>::NODO_NULO)
        return -1;
    else 
        return 1 + std::max( alturaAbinRec(A,A.hijoIzqdo(n)), alturaAbinRec(A,A.hijoDrcho(n)));
}

/*
3. Implementa un subprograma que, dados un árbol binario y un nodo del mismo, determine
la profundidad de este nodo en dicho árbol. 
*/
template <typename T>
int profundidadNodoRec(const Abin<T>&A, const typename Abin<T>::nodo n){
    if(n == Abin<T>::NODO_NULO)
        return -1;
    else
        return 1 + profundidadNodoRec(A, A.padre(n));
}
/*
6. Implementa un subprograma que determine el nivel de desequilibrio de un árbol binario,
definido como el máximo desequilibrio de todos sus nodos. El desequilibrio de un nodo se
define como la diferencia entre las alturas de los subárboles del mismo. 
*/
template <typename T>
int desequilibrioNodo(Abin<T>& A, const typename Abin<T>::nodo n){
    return std::abs(A.alturaNodoRec(A.hijoIzqdo(n)) - A.alturaNodoRec(A.hijoDrcho(n)));
}

template <typename T>
int desequilibrioAbin(Abin<T>&A){
    return desequilibrioAbinRec(A,A.raiz());
}

template <typename T>
int desequilibrioAbinRec(Abin<T>&A, const typename Abin<T>::nodo n){
    if(n == Abin<T>::NODO_NULO)
        return 0;
    else 
        return std::max(desequilibrioNodo(A,n), std::max(desequilibrioAbinRec(A,A.hijoIzqdo(n)),desequilibrioAbinRec(A,A.hijoDrcho(n))));
}

/*
7.Implementa un subprograma que determine si un árbol binario es o no pseudocompleto.
En este problema entenderemos que un árbol es pseudocompleto, si en el penúltimo nivel
del mismo cada uno de los nodos tiene dos hijos o ninguno
*/
template <typename T>
bool pseudocompleto( Abin<T>& A){
    return pseudocompletoRec(A,A.raiz());
}
template <typename T>
bool pseudocompletoRec( Abin<T>&A, const typename Abin<T>::nodo n){
    if(n == Abin<T>::NODO_NULO)
        return false;
    else{
        if(A.alturaNodoRec(n) == alturaAbin(A) - 1)
            if(A.hijoIzqdo(n) == Abin<T>::NODO_NULO && A.hijoDrcho(n) == Abin<T>::NODO_NULO || A.hijoIzqdo(n) != Abin<T>::NODO_NULO && A.hijoDrcho(n) != Abin<T>::NODO_NULO)
                return true;
            else 
                return false;
        else 
            return pseudocompletoRec(A,A.hijoIzqdo(n)) && pseudocompletoRec(A,A.hijoDrcho(n));
    }
}
#endif 