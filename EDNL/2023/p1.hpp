#include "Material_Arboles/abin.h"
#include "Material_Arboles/abin_E-S.h"

//Ejercicio 1
// Implementa un subprograma que calcule el número de nodos de un árbol binario. 
template<typename T>
int num_nodos(const Abin<T>& A){
    return num_nodos_rec(A,A.raiz());
}

template<typename T>
int num_nodos_rec(const Abin<T>& A, const typename Abin<T>::nodo n){
    if(n == Abin<T>::NODO_NULO){
        return 0;
    }else{
        return 1 + num_nodos_rec(A,A.hijoIzqdo(n)) + num_nodos_rec(A,A.hijoDrcho(n));
    }
}

template<typename T>
int altura_abin(const Abin<T>& A){
    return altura_abin_rec(A, A.raiz());
}

template<typename T>
int altura_abin_rec(const Abin<T>& A, const typename Abin<T>::nodo n){
    if(n == Abin<T>::NODO_NULO){
        return -1;
    }else{
        return 1 + std::max(altura_abin_rec(A,A.hijoIzqdo(n)), altura_abin_rec(A,A.hijoDrcho(n)));
    }
}