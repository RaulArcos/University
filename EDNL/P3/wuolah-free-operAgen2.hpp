
#include <iostream>
#include <fstream>

#include "agen.hpp"
#include "agen_E-S.h"

//
template <typename T> int gradoAgen2Rec(Agen<T> A, typename Agen<T>::nodo a)
{
    if( a == Agen<T>::NODO_NULO )
        return 0;
    else
        return std::max(gradoAgen2Rec(A, A.hijoIzqdo(a)), 1 + gradoAgen2Rec(A, A.hermDrcho(a)));
}

template <typename T> int gradoAgen2(Agen<T> A)
{
    return gradoAgen2Rec(A, A.raiz());
}





//
template <typename T> int alturaAgen2Rec(Agen<T> A, typename Agen<T>::nodo a)
{
    if( a == Agen<T>::NODO_NULO )
        return -1;
    else
        return std::max(1 + alturaAgen2Rec(A, A.hijoIzqdo(a)), alturaAgen2Rec(A, A.hermDrcho(a)));
}

template <typename T> int alturaAgen2(Agen<T> A)
{
    if( A.raiz() == Agen<T>::NODO_NULO )
        return 0;
    else
        return alturaAgen2Rec(A, A.raiz());
}

template <typename T> int alturaNodoAgen2(Agen<T> A, typename Agen<T>::nodo a)
{
    return alturaAgen2Rec(A, a);
}





//
template <typename T> int profundidadAgen2Rec(Agen<T> A, typename Agen<T>::nodo a)
{
    if( a == Agen<T>::NODO_NULO )
        return 0;
    else
        return 1 + profundidadAgen2Rec(A, A.padre(a));
}

template <typename T> int profundidadAgen2(Agen<T> A)
{
    return profundidadAgen2Rec(A, A.raiz());
}

template <typename T> int profundidadNodoAgen2(Agen<T> A, typename Agen<T>::nodo a)
{
    return profundidadAgen2Rec(A, a);
}






//
template <typename T> int desequilibrioAgen2Rec(const Agen<T>& A, typename Agen<T>::nodo& a)
{
    return alturaAgen2(A) - std::min(alturaNodoAgen2(A, A.hijoIzqdo()) - alturaNodoAgen2(A, A.hermDrcho(a)));
}

template <typename T> int desequilibrioAgen2(const Agen<T>& A)
{
    return desequilibrioAgen2Rec(A, A.raiz());
}






//
template <typename T> void podaAgen2Rec2(Agen<T>& A, typename Agen<T>::nodo& a)
{
    if( a != Agen<T>::NODO_NULO )
    {
        if( A.hijoIzqdo(a) != Agen<T>::NODO_NULO )
        {
            podaAgen2Rec2(A, A.hijoIzqdo(a), e);
            A.eliminarHijoIzqdo(a);
        }
        if( A.hermDrcho(a) != Agen<T>::NODO_NULO )
        {
            podaAgen2Rec2(A, A.hermDrcho(a), e);
            A.eliminarHermDrcho(a);
        }
    }
}

template <typename T> void buscarAgen2Rec(Agen<T>& A, typename Agen<T>::nodo& a, const T& e)
{
    if( a != Agen<T>::NODO_NULO )
        if( A.elemento(a) != e )
        {
            buscarAgen2Rec(A, A.hijoIzqdo(a), e);
            buscarAgen2Rec(A, A.hermDrcho(a), e);
        }
        else
            podaAgen2Rec2(A, a, e);
}

template <typename T> void podaAgen2(Agen<T>& A, const T& e)
{
    buscarAgen2Rec(A, A.raiz());
}
