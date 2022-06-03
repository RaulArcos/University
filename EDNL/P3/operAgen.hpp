#ifndef OPERAGEN_H 
#define OPERAGEN_H 

#include <iostream>
#include <fstream>

#include "agen.hpp"
#include "agen_E-S.h"

///////////////////////////////////FUNCIONES AUXILIARES///////////////////////////////////

//Devuelve el hermano izquierdo del nodo n, si no devuelve NODO_NULO
template<typename T> typename Agen<T>::nodo hermIzqdo(const Agen<T>& A, const typename Agen<T>::nodo& n)
{
    typename Agen<T>::nodo hermIzqdo;

    if( A.raiz() == n )
    {
        hermIzqdo = Agen<T>::NODO_NULO;
    }
    else
    {
        hermIzqdo = A.hijoIzqdo(A.padre(n));

        if( hermIzqdo == n )
            hermIzqdo = Agen<T>::NODO_NULO;
        else
        {
            while( A.hermDrcho(hermIzqdo) != Agen<T>::NODO_NULO && A.hermDrcho(hermIzqdo) != n )
            {
                hermIzqdo = A.hermDrcho(hermIzqdo);
            }
            /*
            if( A.hermDrcho(hermIzqdo) != n )   //No debería ocurrir, ya que busco desde el padre directamente
                hermIzqdo = Agen<T>::NODO_NULO;
            */
        }
    }
    
    return hermIzqdo;
}

template<typename T> int contarHijosRec(const Agen<T>& A, const typename Agen<T>::nodo& n)
{
    if( n == Agen<T>::NODO_NULO )
        return 0;
    else
        return 1 + contarHijosRec(A, A.hermDrcho(n));
}

template<typename T> int contarHijos(const Agen<T>& A, const typename Agen<T>::nodo& n)
{
/*
    //Versión iterativa
    Agen<T>::nodo actual = A.hijoIzqdo(n);
    int cont = 0;

    while( actual != Agen<T>::NODO_NULO )
    {
        ++cont;
        actual = A.hermDrcho(actual);
    }

    return cont;
*/
    //Versión recursiva
    return contarHijosRec(A, A.hijoIzqdo(n));
}

template<typename T> int numNodosAgenRec(const Agen<T>& A, const typename Agen<T>::nodo& n)
{
    if( n == Agen<T>::NODO_NULO )
        return 0;
    else
        return 1 + numNodosAgenRec(A, A.hijoIzqdo(n)) + numNodosAgenRec(A, A.hermDrcho(n));
}

template<typename T> int numNodosAgen(const Agen<T>& A)
{
    return numNodosAgenRec(A, A.raiz());
}

template<typename T> 
typename Agen<T>::nodo buscarEltoAgenRec(const Agen<T>& A, const T& x, const typename Agen<T>::nodo& n)
{
    if( n == Agen<T>::NODO_NULO )
        return Agen<T>::NODO_NULO;
    else
        if( A.elemento(n) == x )
            return n;
        else
        {
            typename Agen<T>::nodo aux = buscarEltoAgenRec(A, x, A.hijoIzqdo(n));
            if( aux != Agen<T>::NODO_NULO && A.elemento(aux) == x ) return aux;
            else return buscarEltoAgenRec(A, x, A.hermDrcho(n));
        }
}

template<typename T> 
typename Agen<T>::nodo buscarEltoAgen(const Agen<T>& A, const T& x)
{
    return buscarEltoAgenRec(A, x, A.raiz());
}

template<typename T> 
int alturaNodoAgen(const Agen<T>& A, const typename Agen<T>::nodo& n)
{
    int max = 0;
    typename Agen<T>::nodo aux = Agen<T>::NODO_NULO;
    
    if( n != Agen<T>::NODO_NULO )
        aux = A.hijoIzqdo(n);
    
    while( aux != Agen<T>::NODO_NULO )
    {
        max = std::max(max, 1 + alturaNodoAgen(A, aux));
        aux = A.hermDrcho(aux);
    }

    return max;
}

template<typename T> int alturaAgen(const Agen<T>& A)
{
    return alturaNodoAgen(A, A.raiz());
}


















/////////////////////////////*PRÁCTICA 3*/////////////////////////////

//1. Implementa un subprograma que dado un árbol general nos calcule su grado.

template<typename T> int gradoAgenRec(const Agen<T>& A, const typename Agen<T>::nodo& n)
{
    if( n == Agen<T>::NODO_NULO )
        return 0;
    else
        return std::max(contarHijos(A, n), std::max(gradoAgenRec(A, A.hijoIzqdo(n)), gradoAgenRec(A, A.hermDrcho(n))));
}

template<typename T> int gradoAgen(const Agen<T>& A)
{
    return gradoAgenRec(A, A.raiz());
}

//2. Implementa un subprograma que dados un árbol y un nodo dentro de dicho árbol determine la profundidad de éste nodo en el árbol. 

template<typename T> int profundidadNodoAgen(const Agen<T>& A, const typename Agen<T>::nodo& n)
{
    if( n == Agen<T>::NODO_NULO )
        return -1;
    else
        return 1 + profundidadNodoAgen(A, A.padre(n));
}

//3. Se define el desequilibrio de un árbol general como la máxima diferencia entre las alturas de los subárboles más bajo y más alto de cada nivel. Implementa un subprograma que calcule el grado de desequilibrio de un árbol general. 

template<typename T> int desequilibrioAgenRec(const Agen<T>& A, const typename Agen<T>::nodo& n)
{
    if( n == Agen<T>::NODO_NULO || A.hijoIzqdo(A.raiz()) == Agen<T>::NODO_NULO )
        return 0;
    else
    {
        int min = alturaAgen(A);
        typename Agen<T>::nodo aux = A.hijoIzqdo(n);

        while( A.hermDrcho(aux) != Agen<T>::NODO_NULO )
        {
            min = std::min(min, alturaNodoAgen(A, aux));
            aux = A.hermDrcho(aux);
        }
        return std::abs(alturaAgen(A) - min);
    }
}

template<typename T> int desequilibrioAgen(const Agen<T>& A)
{
    return desequilibrioAgenRec(A, A.raiz());
}

//4. Dado un árbol general de enteros A y un entero x, implementa un subprograma que realice la poda de A a partir de x. Se asume que no hay elementos repetidos en A. 

template<typename T> void podaAgenRec(Agen<T>& A, const typename Agen<T>::nodo& n)
{
    if( n != Agen<T>::NODO_NULO )
    {
        //Elimina todos los descendientes de un nodo
        while(A.hijoIzqdo(n) != Agen<T>::NODO_NULO )
        {
            podaAgenRec(A, A.hijoIzqdo(n));
            A.eliminarHijoIzqdo(n);
        }
    }
}

template<typename T> void podaAgen(Agen<T>& A, const T& x)
{
    const typename Agen<T>::nodo& n = buscarEltoAgen(A, x);
    
    podaAgenRec(A, n);
    
    if( n != A.raiz() )
    {
        //Eliminar el nodo n
        //Si no tiene hermano izquierdo, entonces es el hijo izquierdo del padre
        if( hermIzqdo(A, n) != Agen<T>::NODO_NULO )
            A.eliminarHermDrcho(hermIzqdo(A, n));
        else
            A.eliminarHijoIzqdo(A.padre(n));
    }
    else A.eliminarRaiz();
}

////////////////////////////////////////////////////////////////////////////////////////////
//Contar nodos verdes

template<typename T> int contarVerdesAgenRec(const Agen<T>& A, bool esVerde(const Agen<T>&, const typename Agen<T>::nodo&), const typename Agen<T>::nodo& n)
{
    if( n == Agen<T>::NODO_NULO )
        return 0;
    else
        if( esVerde(A, n) )
            return 1 + contarVerdesAgenRec(A, esVerde, A.hijoIzqdo(n)) + contarVerdesAgenRec(A, esVerde, A.hermDrcho(n));
        else
            return contarVerdesAgenRec(A, esVerde, A.hijoIzqdo(n)) + contarVerdesAgenRec(A, esVerde, A.hermDrcho(n));
}

template<typename T> int contarVerdesAgen(const Agen<T>& A, bool esVerde(const Agen<T>&, const typename Agen<T>::nodo&))
{
    return contarVerdesAgenRec(A, esVerde, A.raiz());
}

template<typename T> bool dobleNietos(const Agen<T>& A, const typename Agen<T>::nodo& n)
{
    if( n == Agen<T>::NODO_NULO )
        return false;
    else
    {
        typename Agen<T>::nodo aux;

        if( A.hijoIzqdo(n) != Agen<T>::NODO_NULO ) 
            aux = A.hijoIzqdo(n);
        else
            aux = Agen<T>::NODO_NULO;

        int numHijos = 0;
        int numNietos = 0;

        while( aux != Agen<T>::NODO_NULO )
        {
            ++numHijos;
            numNietos += contarHijos(A, aux);
            aux = A.hermDrcho(aux);
        }

        if( numHijos * 2 == numNietos )
            return true;
        else 
            return false;
    }
}

















/*
Calcular densidad de un arbol. La densidad se define como el Grado 
maximo de un Arbol partido del numero de nodos hojas.
*/
template <typename T> bool esHojaAgen(const Agen<T>& A, const typename Agen<T>::nodo& n)
{
    return (A.hijoIzqdo(n) == Agen<T>::NODO_NULO ? true : false);
}

template <typename T> double densidadAgen(const Agen<T>& A)
{
    double numHojas = contarVerdesAgen(A, esHojaAgen);
    if( numHojas != 0 )
        return gradoAgen(A) / numHojas;
    else
        return 0.0;
}

/*
Implementa un subprograma que devuelva el porcentaje de descendientes 
propios de un árbol general que sean múltiplos de 3.
*/
//Si descendientes propios son solo los hijos
template <typename T> int contarHijos2(const Agen<T>& A, const typename Agen<T>::nodo& n)
{
    int numHijos = 0;
    typename Agen<T>::nodo nAux = A.hijoIzqdo(n);

    while( nAux != Agen<T>::NODO_NULO )
    {
        ++numHijos;
        nAux = A.hijoIzqdo(nAux);
    }

    return numHijos;
}

//Si descendientes propios son todos los descendientes
template <typename T> int contarDescendientesRec(const Agen<T>& A, const typename Agen<T>::nodo& n)
{
    if( n != Agen<T>::NODO_NULO )
        return 0;
    else
        return 1 + contarDescendientesRec(A, A.hijoIzqdo(n)) + contarDescendientesRec(A, A.hermDrcho(n));
}

template <typename T> int contarDescendientes(const Agen<T>& A, const typename Agen<T>::nodo& n)
{
    return 1 + contarDescendientesRec(A, A.hijoIzqdo(n));
}

template <typename T> double contarNodoAgen2(const Agen<T>& A, const typename Agen<T>::nodo& n)
{
    if( n != Agen<T>::NODO_NULO )
        return 0.0;
    else
        return 1.0 + contarNodoAgen2(A, A.hijoIzqdo(n)) + contarNodoAgen2(A, A.hermDrcho(n));
}

template <typename T> double multiplo3Rec(const Agen<T>& A, const typename Agen<T>::nodo& n)
{
    if( n != Agen<T>::NODO_NULO )
        return 0;
    else
        //if( contarHijos2(A, n) % 3 == 0 )
        if( contarDescendientes(A, n) % 3 == 0 )
            return 1 + multiplo3Rec(A, A.hijoIzqdo(n)) + multiplo3Rec(A, A.hermDrcho(n));
        else
            return multiplo3Rec(A, A.hijoIzqdo(n)) + multiplo3Rec(A, A.hermDrcho(n));
}

template <typename T> double multiplo3(const Agen<T>& A)
{
    return multiplo3Rec(A, A.raiz()) / contarNodoAgen2(A, A.raiz()) * 100.0;
}























/*
Implementa un subprograma que devuelva el porcentaje de descendientes 
propios de un árbol general que sean múltiplos de 3.
*/

template<typename T>
double nNodos(const Agen<T>& A)
{
    return multiplos3Rec2(A) / nNodos(A);
}

template<typename T>
double nNodosRec(const Agen<T>& A, const Agen<T>::nodo& a)
{
    if( a == Agen<T>::NODO_NULO )
        return 0;
    else
        return 1 + nNodosRec(A, A.hijoIzqdo(a)) + nNodosRec(A, A.hermDrcho(a));
}



template<typename T>
double nDescendientes(const Agen<T>& A, const Agen<T>::nodo& a)
{
    if( a == Agen<T>::NODO_NULO )
        return 0;
    else
        return 1 + nNodosRec(A, A.hermDrcho(a));
}


template<typename T>
double multiplos32(const Agen<T>& A)
{
    return multiplos3Rec2(A) / nNodos(A);
}

template<typename T>
double multiplos3Rec2(const Agen<T>& A, const Agen<T>::nodo& a)
{
    if( a == Agen<T>::NODO_NULO )
        return 0;
    else
        if( nDescendientes(A, a) % 3 == 0 )
            return 1 + multiplos3Rec2(A, A.hijoIzqdo(a)) + nNodosRec(A, A.hermDrcho(a));
        else
            return multiplos3Rec2(A, A.hijoIzqdo(a)) + nNodosRec(A, A.hermDrcho(a));
}

#endif // OPERAGEN_H