#ifndef AGEN_LIS_H
#define AGEN_LIS_H
#include <cassert>
#include <iostream>
#include "listaenla.h"
template <typename T> class Agen {
public:
typedef size_t nodo; // índice de la matriz
// entre 0 y maxNodos-1
static const nodo NODO_NULO;
explicit Agen(size_t maxNodos); // ctor., requiere ctor. T()
void insertarRaiz(const T& e);
void insertarHijoIzqdo(nodo n, const T& e);
void insertarHermDrcho(nodo n, const T& e);
void eliminarHijoIzqdo(nodo n);
void eliminarHermDrcho(nodo n);
void eliminarRaiz();
bool arbolVacio() const;
const T& elemento(nodo n) const; // acceso a elto, lectura
T& elemento(nodo n); // acceso a elto, lectura/escritura
 30
nodo raiz() const;
nodo padre(nodo n) const;
nodo hijoIzqdo(nodo n) const;
nodo hermDrcho(nodo n) const;
Agen(const Agen<T>& A); // ctor. de copia
Agen<T>& operator =(const Agen<T>& A); // asignación de árboles
~Agen(); // destructor
private:
struct celda {
T elto;
nodo padre;
Lista<nodo> hijos;
};
celda *nodos; // vector de nodos
size_t maxNodos; // tamaño del vector
size_t numNodos; // número de nodos del árbol
};
/* Definición del nodo nulo */
template <typename T>
const typename Agen<T>::nodo Agen<T>::NODO_NULO(SIZE_MAX);

template <typename T>
inline Agen<T>::Agen(size_t maxNodos) :
nodos(new celda[maxNodos]), // Se crean las listas de
// hijos vacías.
maxNodos(maxNodos),
numNodos(0)
{
// Marcar todas las celdas como libres.
for (nodo i = 0; i <= maxNodos-1; i++)
nodos[i].padre = NODO_NULO;
}
template <typename T>
void Agen<T>::insertarRaiz(const T& e)
{
assert(numNodos == 0); // Árbol vacío.
numNodos = 1;
nodos[0].elto = e;
// La lista de hijos está vacía.
}

template <typename T>
void Agen<T>::insertarHijoIzqdo(Agen<T>::nodo n, const T& e)
{
nodo hizqdo;
assert(numNodos > 0); // Árbol no vacío.
assert(n >= 0 && n <= maxNodos-1); // n es una celda del vector
assert(n == 0 || nodos[n].padre != NODO_NULO); // que está ocupada.
assert(numNodos < maxNodos); // Árbol no lleno.
// Añadir el nuevo nodo en la primera celda libre.
for (hizqdo = 1; nodos[hizqdo].padre != NODO_NULO; hizqdo++);
nodos[hizqdo].elto = e;
nodos[hizqdo].padre = n;
// Insertar el nuevo nodo al inicio de la lista de hijos de n.
Lista<nodo>& Lh = nodos[n].hijos; // Lista de hijos.
Lh.insertar(hizqdo, Lh.primera());
++numNodos;
}

template <typename T>
void Agen<T>::insertarHermDrcho(Agen<T>::nodo n, const T& e)
{
nodo hedrcho;
assert(n >= 0 && n <= maxNodos-1); // n es un nodo válido.
assert(nodos[n].padre != NODO_NULO); // n existe y no es la raíz.
assert(numNodos < maxNodos); // Árbol no lleno.
// Añadir el nuevo nodo en la primera celda libre.
for (hedrcho = 1; nodos[hedrcho].padre != NODO_NULO; hedrcho++);
nodos[hedrcho].elto = e;
nodos[hedrcho].padre = nodos[n].padre;
// Insertar el nuevo nodo en la lista de hijos del padre
// en la posición siguiente a la de n.
Lista<nodo>& Lhp = nodos[nodos[n].padre].hijos; // Lista de hijos
// del padre.
Lhp.insertar(hedrcho, Lhp.siguiente(Lhp.buscar(n)));
++numNodos;
}

template <typename T>
void Agen<T>::eliminarHijoIzqdo(Agen<T>::nodo n)
{
nodo hizqdo;
assert(numNodos > 0); // Árbol no vacío.
assert(n >= 0 && n <= maxNodos-1); // n es una celda del vector
assert(n == 0 || nodos[n].padre != NODO_NULO); // que está ocupada.
Lista<nodo>& Lh = nodos[n].hijos; // Lista de hijos.
assert(Lh.primera() != Lh.fin()); // Lista no vacía, n tiene hijos.
hizqdo = Lh.elemento(Lh.primera());
assert(nodos[hizqdo].hijos.primera() == // Lista vacía, hijo izq.
nodos[hizqdo].hijos.fin()); // de n es una hoja.
// Eliminar hijo izqdo. de n.
nodos[hizqdo].padre = NODO_NULO; // Marcar celda libre.
Lh.eliminar(lh.primera()); // Eliminar primer nodo de la
// lista de hijos de n.
--numNodos;
}

template <typename T>
void Agen<T>::eliminarHermDrcho(Agen<T>::nodo n)
{
nodo hdrcho;
Lista<nodo>::posicion p;
assert(n >= 0 && n <= maxNodos-1); // n es un nodo válido.
assert(nodos[n].padre != NODO_NULO); // n existe y no es la raíz.
// Buscar hermano drcho. de n en la lista de hijos del padre.
Lista<nodo>& Lhp = nodos[nodos[n].padre].hijos; // Lista de hijos
// del padre.
p = Lhp.siguiente(Lhp.buscar(n));
assert(p != Lhp.fin()); // n tiene hermano drcho.
hdrcho = Lhp.elemento(p);
assert(nodos[hdrcho].hijos.primera() == // Lista vacía, hermano
nodos[hdrcho].hijos.fin()); // drcho. de n es hoja.
// Eliminar hermano drcho. de n.
nodos[hdrcho].padre = NODO_NULO; // Marcar celda libre.
Lhp.eliminar(p); // Eliminar hermano de la lista
// de hijos del padre.
--numNodos;
}

template <typename T>
inline void Agen<T>::eliminarRaiz()
{
assert(numNodos == 1);
numNodos = 0;
}
template <typename T>
inline bool Agen<T>::arbolVacio() const
{
return (numNodos == 0);
}
template <typename T>
inline const T& Agen<T>::elemento(Agen<T>::nodo n) const
{
assert(numNodos > 0); // Árbol no vacío.
assert(n >= 0 && n <= maxNodos-1); // n es una celda del vector
assert(n == 0 || nodos[n].padre != NODO_NULO); // que está ocupada
return nodos[n].elto;
}

template <typename T>
inline T& Agen<T>::elemento(Agen<T>::nodo n)
{
assert(numNodos > 0); // Árbol no vacío.
assert(n >= 0 && n <= maxNodos-1); // n es una celda del vector
assert(n == 0 || nodos[n].padre != NODO_NULO); // que está ocupada
return nodos[n].elto;
}
template <typename T>
inline typename Agen<T>::nodo Agen<T>::raiz() const
{
return (numNodos > 0) ? 0 : NODO_NULO;
}
template <typename T>
inline typename Agen<T>::nodo Agen<T>::padre(Agen<T>::nodo n) const
{
assert(numNodos > 0); // Árbol no vacío.
assert(n >= 0 && n <= maxNodos-1); // n es una celda del vector
assert(n == 0 || nodos[n].padre != NODO_NULO); // que está ocupada
return nodos[n].padre;
}

template <typename T>
inline typename Agen<T>::nodo Agen<T>::hijoIzqdo(Agen<T>::nodo n) const
{
assert(numNodos > 0); // Árbol no vacío.
assert(n >= 0 && n <= maxNodos-1); // n es una celda del vector
assert(n == 0 || nodos[n].padre != NODO_NULO); // que está ocupada.
Lista<nodo>& Lh = nodos[n].hijos;
if (Lh.primera() != Lh.fin()) // Lista no vacía.
return Lh.elemento(Lh.primera());
else
return NODO_NULO;
}

template <typename T>
inline typename Agen<T>::nodo Agen<T>::hermDrcho(Agen<T>::nodo n) const
{
Lista<nodo>::posicion p;
assert(numNodos > 0); // Árbol no vacío.
assert(n >= 0 && n <= maxNodos-1); // n es una celda del vector
assert(n == 0 || nodos[n].padre != NODO_NULO); // que está ocupada.
if (n == 0) // n es la raíz.
return NODO_NULO;
else
{
Lista<nodo>& Lhp = nodos[nodos[n].padre].hijos; // Lista de hijos
// del padre.
p = Lhp.siguiente(Lhp.buscar(n));
if (p != Lhp.fin()) // n tiene hermano drcho.
return Lhp.elemento(p);
else
return NODO_NULO;
}
}

template <typename T>
Agen<T>::Agen(const Agen<T>& A) :
nodos(new celda[A.maxNodos]),
maxNodos(A.maxNodos), numNodos(A.numNodos)
{
for (nodo n = 0; n <= maxNodos-1; n++) // Copiar el vector.
nodos[n] = A.nodos[n];
}
template <typename T>
Agen<T>& Agen<T>::operator =(const Agen<T>& A)
{
if (this != &A) { // Evitar autoasignación.
// Destruir el vector y crear uno nuevo si es necesario.
if (maxNodos != A.maxNodos) {
delete[] nodos;
maxNodos = A.maxNodos;
nodos = new celda[maxNodos];
}
numNodos = A.numNodos;
for (nodo n = 0; n <= maxNodos-1; n++) // Copiar el vector.
nodos[n] = a.nodos[n];
}
return *this;
}

template <typename T>
inline Agen<T>::~Agen()
{
delete[] nodos; // También destruye las listas de hijos.
}
#endif // AGEN_LIS_H