#ifndef OPERABB_HPP
#define OPERABB_HPP

#include <vector>
#include <algorithm>

#include "listaenla.h"
#include "Abb.hpp"

/////////////////////////////FUNCIONES AUXILIARES/////////////////////////////

template <typename T> void mostrar (ostream& cout, const Abb<T>& A, const string& ascendiente)
{
    if(!A.vacio())
    {
        cout << ascendiente << A.elemento() << std::endl;
        mostrar(cout, A.izqdo(), "Hijo izquierdo de " + std::to_string(A.elemento()) + ": ");
        mostrar(cout, A.drcho(), "Hijo derecho de " + std::to_string(A.elemento()) + ": ");
    }
}

template <typename T> ostream& operator <<(ostream& cout, const Abb<T>& A)
{
    if(!A.vacio())
        mostrar(cout, A, "Raíz del árbol: ");
    return cout;
}
/*
template <typename T> void vaciarAbb(Abb<T>& A)
{
    if( !A.vacio() )
    {
        vaciarAbb(const_cast<Abb<T>&>(A.izqdo()));
        vaciarAbb(const_cast<Abb<T>&>(A.drcho()));
        A.eliminar(A.elemento());
    }
}
*/
template <typename T> void vaciarAbb(Abb<T>& A)
{
    /*
    Abb<T> nuevo;
    A = nuevo;
    */
   A = Abb<T>();
}

//Inserta los elementos del Abb en preorden al final del vector
template <typename T> void insert_to_vector(const Abb<T>& A, std::vector<T>& AbbEltos)
{
    if( !A.vacio() )
    {
        AbbEltos.push_back(A.elemento());
        insert_to_vector(A.izqdo(), AbbEltos);
        insert_to_vector(A.drcho(), AbbEltos);
    }
}

//////////////////////////////////////////////////////////////////////////////










/*
1. Implementa una nueva operación del TAD Abb que tomando un elemento 
del mismo elimine al completo el subárbol que cuelga de él. Ejemplo: 
Para el árbol binario de búsqueda de la figura se muestra la 
transformación si la entrada fuera el valor 9. 
*/
/*
template <typename T> void podarEltoAbbRec(Abb<T>& A)
{
    if( !A.vacio() )
    {
        podarEltoAbbRec(const_cast<Abb<T>&>(A.izqdo()));
        podarEltoAbbRec(const_cast<Abb<T>&>(A.drcho()));
        A.eliminar(A.elemento());
    }
}
*/

//Poda el árbol que recibe
template <typename T> void podarEltoAbb(Abb<T>& A, const T& e)
{
    //podarEltoAbbRec(const_cast<Abb<T>&>(A.buscar(e)));
    //const_cast<Abb<T>&>(A.buscar(e)) = Abb<T>();
    A.buscar(e).~Abb<T>();
}

//No poda el árbol que recibe y devuelve una copia del árbol podado
template <typename T> Abb<T> podarEltoAbb(const Abb<T>& A, const T& e)
{
    Abb<T> nuevo(A);
    return podarEltoAbbRec(const_cast<Abb<T>&>(nuevo.buscar(e)));
}

/*
2. Un árbol binario de búsqueda se puede equilibrar realizando el 
recorrido en inorden del árbol para obtener el listado ordenado de sus 
elementos y a continuación, repartir equitativamente los elementos a 
izquierda y derecha colocando la mediana en la raíz y construyendo 
recursivamente los subárboles izquierdo y derecho de cada nodo. 
Implementa este algoritmo para equilibrar un ABB. 
*/

template <typename T> void equilibrarAbbRec(Abb<T>& A, const std::vector<T>& eltos, int inicio, int fin)
{
    if( fin >= inicio )
    {
        int centro = inicio + (fin - inicio) / 2;
        
        A.insertar(eltos[centro]);
        
        if( fin >= inicio ) equilibrarAbbRec(A, eltos, inicio, centro - 1);
        if( fin >= inicio ) equilibrarAbbRec(A, eltos, centro + 1, fin);
    }
}
/*
//Devuelve el árbol recibido equilibrido, machacando el propio árbol
template <typename T> void equilibrarAbb(const Abb<T>& A)
{
    std::vector<T> eltos;

    insert_to_vector(A, eltos);
    std::sort(eltos.begin(), eltos.end());

    equilibrarAbbRec(A, eltos, 0, eltos.size() - 1);
}
*/
//Devuelve una copia el árbol recibido equilibrado, sin modificarlo
template <typename T> Abb<T> equilibrarAbb(const Abb<T>& A)
{
    Abb<T> AbbEquilibrado;
    std::vector<T> eltos;

    insert_to_vector(A, eltos);
    std::sort(eltos.begin(), eltos.end());

    equilibrarAbbRec(AbbEquilibrado, eltos, 0, eltos.size() - 1);

    return AbbEquilibrado;
}

/*
3. Dados dos conjuntos representados mediante árboles binarios de 
búsqueda, implementa la operación unión de dos conjuntos que devuelva 
como resultado otro conjunto que sea la unión de ambos, representado 
por un ABB equilibrado. 
*/

template <typename T> Abb<T> unionConjuntosAbb(const Abb<T>& A, const Abb<T>& B)
{
    Abb<T> AbbUnion;
    std::vector<T> eltos;

    insert_to_vector(A, eltos);
    insert_to_vector(B, eltos);

    std::sort(eltos.begin(), eltos.end());

    equilibrarAbbRec(AbbUnion, eltos, 0, eltos.size() - 1);

    return AbbUnion;
}

/*
4. Dados dos conjuntos representados mediante árboles binarios de 
búsqueda, implementa la operación intersección de dos conjuntos, que 
devuelva como resultado otro conjunto que sea la intersección de ambos.
El resultado debe quedar en un árbol equilibrado. 
*/

template <typename T> Abb<T> interseccionConjuntosAbb(const Abb<T>& A, const Abb<T>& B)
{
    Abb<T> AbbInterseccion;
    std::vector<T> eltos, eltosInterseccion;

    insert_to_vector(A, eltos);
    insert_to_vector(B, eltos);

    std::sort(eltos.begin(), eltos.end());

    for( int i = 0; i < eltos.size() - 1; ++i )
        if( eltos[i] == eltos[i + 1] )
            eltosInterseccion.push_back(eltos[i]);

    equilibrarAbbRec(AbbInterseccion, eltosInterseccion, 0, eltosInterseccion.size() - 1);

    return AbbInterseccion;
}

/*
5. Implementa el operador ROMBO para conjuntos definido como 
A ROMBO B = (A U B) - (A n B). La implementación del operador ROMBO debe 
realizarse utilizando obligatoriamente la operación E, que nos indica 
si un elemento dado pertenece o no a un conjunto. La representación 
del tipo Conjunto debe ser tal que la operación de pertenencia esté en 
el caso promedio en O(log n). 
*/

//Devuelve true si elto pertenece a A, si no devuelve false
template <typename T> bool operadorPertenencia(const Abb<T>& A, const T& elto)
{
    return !(A.buscar(elto).vacio());
}

template <typename T> void operadorRomboRec(Abb<T>& AbbRes, const Abb<T>& AbbInterseccion, const Abb<T>& subAbbUnion)
{
    if( !subAbbUnion.vacio() )
    {
        operadorRomboRec(AbbRes, AbbInterseccion, subAbbUnion.izqdo());
        operadorRomboRec(AbbRes, AbbInterseccion, subAbbUnion.drcho());

        if( !operadorPertenencia(AbbInterseccion, subAbbUnion.elemento()) )
            AbbRes.insertar(subAbbUnion.elemento());
    }
}

template <typename T> Abb<T> operadorRombo(const Abb<T>& A, const Abb<T>& B)
{
    Abb<T> AbbRes, AbbInterseccion = interseccionConjuntosAbb(A, B), AbbUnion = unionConjuntosAbb(A, B);
    
    operadorRomboRec(AbbRes, AbbInterseccion, AbbUnion);

    return AbbRes;
}

/*
EJERCICIO DE EXAMEN
Haz una agenda usando un Arbol de búsqueda. Utiliza como estructura una
con los campos telefono y nombre por ejemplo y acuerdate de sobrecargar
los operandos de comparación de la estructura.
*/

struct Contacto
{
    Contacto(std::string no, std::string nu) : nombre(no), numero(nu) {}
    std::string nombre, numero;
};

//Ordenar por nombre
bool operator <(const Contacto& c1, const Contacto& c2)
{
    return (c1.nombre < c2.nombre ? true : false);
}
/*
//Ordenar por número
bool operator <(const Contacto& c1, const Contacto& c2)
{
    return (c1.numero < c2.numero ? true : false);
}
*/

class Agenda
{
public:
    void nuevoContacto(const Contacto& c) { agenda.insertar(c); }
    void eliminarContacto(const Contacto& c) { agenda.eliminar(c); }
    
    //Si se ordena por el nombre
    const Contacto& buscarContacto(std::string no) { return agenda.buscar(Contacto(no, std::string())).elemento(); }
    /*
    //Si se ordena por el número
    const Contacto& buscarContacto(std::string nu) { return agenda.buscar(Contacto(std::string(), nu)).elemento(); }
    */
private:
    Abb<Contacto> agenda;
};

//////////////////////////////////////////////////////////////////////////////










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
//ESTÁ MAL (??????????)
/*
template <typename T> T infimo(const Abb<T>& A, const T& e)
{
    Abb<T> eltoAbb = A.buscar(e), infimoAbb, minimoAbb;
    if( !eltoAbb.vacio() )  //Si e pertenece a A
    {
        infimoAbb = eltoAbb.izqdo();
        if( !infimoAbb.vacio() )    //Si existe el ínfimo se devuelve
        {
            while( !infimoAbb.drcho().vacio() )
                infimoAbb = infimoAbb.drcho();
            return infimoAbb.elemento();
        }
        else                        //Si no existe el ínfimo se devuelve el mínimo
        {
            minimoAbb = A;
            while( !minimoAbb.izqdo().vacio() )
                minimoAbb = minimoAbb.izqdo();
            return minimoAbb.elemento();
        }
    }
    else 
        return T();
}

template <typename T> T supremo(const Abb<T>& A, const T& e)
{
    Abb<T> eltoAbb = A.buscar(e), supremoAbb, minAbb;
    if( !eltoAbb.vacio() )  //Si e pertenece a A
    {
        supremoAbb = eltoAbb.drcho();
        if( !supremoAbb.vacio() )    //Si existe el supremo se devuelve
            return supremoAbb.elemento();
        else                        //Si no existe el supremo se devuelve el máximo
            minAbb = A;
            while( !minAbb.drcho().vacio() )
                minAbb = minAbb.drcho();
            return minAbb.elemento();
    }
    else 
        return T();
}
*/

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

struct Palabra
{
    std::string original, traduccion;
    Palabra(std::string o, std::string t) : original(o), traduccion(t) {}
};

bool operator <(const Palabra& p1, const Palabra& p2)
{
    return p1.original < p2.original;
}

class Diccionario
{
public:
    Diccionario() {};
    void insertar(Palabra p);
    void eliminar(Palabra p);
    std::string traduccion(const std::string& t) const;
    std::string listar() const;

private:
    Abb<Palabra> d;
    std::string traduccionRec(const std::string& t, Abb<Palabra> dAux) const;
    std::string listarRec(Abb<Palabra> dAux) const;
};

inline void Diccionario::insertar(Palabra p)
{
    d.insertar(p);
}

inline void Diccionario::eliminar(Palabra p)
{
    d.eliminar(p);
}

std::string Diccionario::traduccion(const std::string& t) const
{
    return traduccionRec(t, d);
}

std::string Diccionario::traduccionRec(const std::string& t, Abb<Palabra> dAux) const
{
    if( !dAux.vacio() )
        if( dAux.elemento().traduccion == t )
            return dAux.elemento().original;
        else
            return "" + traduccionRec(t, dAux.izqdo()) + traduccionRec(t, dAux.drcho());
    else
        return "";
}

std::string Diccionario::listar() const
{
    return listarRec(d);
}

std::string Diccionario::listarRec(Abb<Palabra> dAux) const
{
    if( !dAux.vacio() )
        return listarRec(dAux.izqdo()) + dAux.elemento().original + " : " + dAux.elemento().traduccion + "\n" + listarRec(dAux.drcho());
    else
        return "";
}

#endif // OPERABB_HPP