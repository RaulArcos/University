#include <vector>
#include <set>
#include <algorithm>

#include "listaenla.h"
#include "Abb.hpp"

//
template <typename T> void Abb_to_vectorRec(const Abb<T>& A, std::vector<T>& v)
{
    if( !A.vacio() )
    {
        equilibrar2Aux(A.izqdo(), v);
        v.push_back(A.elemento());
        equilibrar2Aux(A.drcho(), v);
    }
}

template <typename T> void insertar_medianaRec(Abb<T>& A, std::vector<T>& v)
{
    if( !A.vacio() )
    {
        A.insertar(v[v.size()/2]);
        equilibrar2Aux(A.izqdo, (v.begin(), v.end()/2 - 1));
        equilibrar2Aux(A.drcho, (v.end()/2 + 1, v.end()));
    }
}

template <typename T> void equilibrar2(Abb<T>& A)
{
    std::vector<T> v;
    Abb_to_vectorRec(A, v);

    A = Abb<T>();
    insertar_medianaRec(A, v);
}








//
template <typename T> Abb<T> unionAbb2(const Abb<T>& A, const Abb<T>& B)
{
    std::vector<T> va;
    Abb_to_vectorRec(A, va);

    std::vector<T> vb;
    Abb_to_vectorRec(B, vb);

    va.insert(va.end(), vb.begin(), vb.end());

    set<T> s(va.begin(), va.end());
    va = std::vector<T>(s.begin(), s.end());

    Abb<T> C;
    insertar_medianaRec(C, va);
    return C;
}








//
template <typename T> Abb<T> interseccionAbb2(const Abb<T>& A, const Abb<T>& B)
{
    std::vector<T> va;
    Abb_to_vectorRec(A, va);

    std::vector<T> vb;
    Abb_to_vectorRec(B, vb);

    std::vector<T> vc;

    for( T e : va )
        if( find(vb.begin(), vb.end(), e) == vb.end() )
            vc.push_back(e);

    for( T e : vb )
        if( find(va.begin(), va.end(), e) == va.end() )
            vc.push_back(e);

    vc.sort();

    Abb<T> C;
    insertar_medianaRec(C, va);
    return C;
}








//
template <typename T> Abb<T> diferenciaAbb2(const Abb<T>& A, const Abb<T>& B)
{
    std::vector<T> va;
    Abb_to_vectorRec(A, va);

    std::vector<T> vb;
    Abb_to_vectorRec(B, vb);

    std::vector<T> vc;

    for( T e : va )
        if( find(vb.begin(), vb.end(), e) == vb.end() )
            vc.push_back(e);

    vc.sort();

    Abb<T> C;
    insertar_medianaRec(C, va);
    return C;
}

template <typename T> Abb<T> romboAbb2(const Abb<T>& A, const Abb<T>& B)
{
    return diferenciaAbb2(unionAbb2(A, B), interseccionAbb2(A, B));
}



















//Ejercicio de exámen
/*
Dado un conjunto ordenado no vacío A, se define el ínfimo de x como el mayor 
elemento de A menor o igual que x, si existe. Análogamente, el supremo de x 
en A, si existe, es el menor elemento de A mayor o igual que x.

Implementa dos funciones de O(log n) en promedio que dados un valor x cualquiera
y un ABB A no vacío devuelvan, respectivamente, el ínfimo y el supremo de x en A. 
Si no existe el ínfimo de x en A, la función correspondiente devolverá el mínimo 
de A. Así mismo, la otra función devolverá el máximo de A, en el caso de que no 
existe el supremo.

Nota: Es absolutamente necesario definir todos los tipos de datos implicados en 
la resulución del ejercicio, así como los prototipos de las operaciones 
utilizadas de los TADs conocidos.
*/

template<typename T> T minAbb2(const Abb<T>& A)
{
    if( A.izqdo().vacio() )
        return A.elemento();
    else
        return minAbb2(A.izqdo());
}

template<typename T> T maxAbb2(const Abb<T>& A)
{
    if( A.drcho().vacio() )
        return A.elemento();
    else
        return maxAbb2(A.drcho());
}


template<typename T> T infimoAbb2(const Abb<T>& A, const T& x)
{
    T supremo;

    Abb<T> aux, B = A.buscar(x);

    if( !B.vacio() && !B.izqdo().vacio() )
    {
        Abb<T> aux = B.izqdo();

        while( !aux.drcho().vacio() )
            aux = aux.drcho();
    }
    else
        supremo = maxAbb2(A);
}

template<typename T> T supremoAbb2(const Abb<T>& A, const T& x)
{
    T supremo;

    Abb<T> aux, B = A.buscar(x);

    if( !B.vacio() && !B.drcho().vacio() )
    {
        Abb<T> aux = B.drcho();

        while( !aux.izqdo().vacio() )
            aux = aux.izqdo();
    }
    else
        supremo = maxAbb2(A);
}

/*
Tenemos un diccionario con su palabra española (string) y su 
traducción al zuelandés (string). Se deben implementar las 
siguientes operaciones:
Construir un diccionario vacío
Insertar una palabra española con su traducción al zuelandés
Eliminar una palabra española y su traducción.
Buscar la traducción de esa palabra en español.
Listar las palabras españolas con su traducción al zuelandés en orden alfabético.
*/

struct palabra
{
    palabra(std::string o, std::string t) : ori(o), tra(t) {}
    std::string ori, tra;
};

