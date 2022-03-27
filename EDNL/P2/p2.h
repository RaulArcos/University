/*
Práctica 2 EDNL by Raúl Arcos Herrera
*/

#ifndef P2_H
#define P2_H

#include "../abin.h"
#include "../abin_E-S.h"
#include <stdlib.h>
#include <string>

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
Abin<T> reflejado( Abin<T> &A)
{
    Abin<T> B; //CORRECCIÓN: Puedes hacer dos returns, siendo uno el caso normal y otro el caso de árbol vacio pa que
                //no tenga que entrar en la función de reflejadoRec
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


//EJERCICIO 4


#endif 