/*
Práctica 3 EDNL Arboles Generales - Raúl Arcos Herrera 2022.
*/

#ifndef P3_H 
#define P3_H 

#include <iostream>
#include <fstream>
#include "../agen.h"

/*
1. Implementa un subprograma que dado un árbol general nos calcule su grado. 
*/

//Función Auxiliar para contar el numero de hijos de un nodo.
template <typename T>
int numHijosAgen(const typename Agen<T>::nodo n, const Agen<T>& A){
    return numHijosAgenRec(A.hijoIzqdo(n), A);
}
template <typename T>
int numHijosAgenRec(const typename Agen<T>::nodo n, const Agen<T>& A){
    if(n == Agen<T>::NODO_NULO)
        return 0;
    else 
        return 1 + numHijosAgenRec(A.hermDrcho(n),A);
}

template <typename T>
int gradoAgen(const Agen<T>& A){
    return gradoAgenRec(A.raiz(), A);
}
template <typename T>
int gradoAgenRec(const typename Agen<T>::nodo& n, const Agen<T>& A){
    if(n == Agen<T>::NODO_NULO)
        return 0;
    else 
        return std::max(numHijosAgen(n,A), std::max(gradoAgenRec(A.hijoIzqdo(n),A), gradoAgenRec(A.hermDrcho(n),A)));
}

/*
2. Implementa un subprograma que dados un árbol y un nodo dentro de dicho árbol determine
la profundidad de éste nodo en el árbol.
*/
template<typename T> 
int profundidadNodoAgen(const typename Agen<T>::nodo& n, const Agen<T>& A)
{
    if( n == Agen<T>::NODO_NULO )
        return -1;
    else
        return 1 + profundidadNodoAgen(A.padre(n),A);
}

/*
3. Se define el desequilibrio de un árbol general como la máxima diferencia entre las alturas
de los subárboles más bajo y más alto de cada nivel. Implementa un subprograma que calcule
el grado de desequilibrio de un árbol general. 
*/



#endif