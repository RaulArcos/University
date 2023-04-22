#ifndef ABIN_H
#define ABIN_H
#include <cassert>
template <typename T> class Abin {
struct celda; // declaración adelantada privada
public:
typedef celda* nodo;
static const nodo NODO_NULO;
Abin(); // constructor
void insertarRaiz(const T& e);
void insertarHijoIzqdo(nodo n, const T& e);
void insertarHijoDrcho(nodo n, const T& e);
void eliminarHijoIzqdo(nodo n);
void eliminarHijoDrcho(nodo n);
void eliminarRaiz();
bool arbolVacio() const;
int alturaNodoRec(nodo n);
int profundidadNodoRec(nodo n);
const T& elemento(nodo n) const; // acceso a elto, lectura
T& elemento(nodo n); // acceso a elto, lectura/escritura
nodo raiz() const;
nodo padre(nodo n) const;
nodo hijoIzqdo(nodo n) const;
nodo hijoDrcho(nodo n) const;
Abin(const Abin<T>& a); // ctor. de copia
Abin<T>& operator =(const Abin<T>& A); // asig.de árboles
~Abin(); // destructor
private:
struct celda {
T elto;
nodo padre, hizq, hder;
celda(const T& e, nodo p = NODO_NULO): elto(e),
padre(p), hizq(NODO_NULO), hder(NODO_NULO) {}
};
nodo r; // nodo raíz del árbol
void destruirNodos(nodo& n);
nodo copiar(nodo n);
};

/* Definición del nodo nulo */
template <typename T>
const typename Abin<T>::nodo Abin<T>::NODO_NULO(nullptr);
/*--------------------------------------------------------*/
/* Métodos públicos */
/*--------------------------------------------------------*/
template <typename T>
inline Abin<T>::Abin() : r(NODO_NULO) {}
template <typename T>
inline void Abin<T>::insertarRaiz(const T& e)
{
assert(r == NODO_NULO); // Árbol vacío
r = new celda(e);
}
template <typename T>
inline void Abin<T>::insertarHijoIzqdo(nodo n, const T& e)
{
assert(n != NODO_NULO);
assert(n->hizq == NODO_NULO); // No existe hijo izqdo.
n->hizq = new celda(e, n);
}
template <typename T>
inline void Abin<T>::insertarHijoDrcho(nodo n, const T& e)
{
assert(n != NODO_NULO);
assert(n->hder == NODO_NULO); // No existe hijo drcho.
n->hder = new celda(e, n);
}
template <typename T>
inline void Abin<T>::eliminarHijoIzqdo(nodo n)
{
assert(n != NODO_NULO);
assert(n->hizq != NODO_NULO); // Existe hijo izqdo.
assert(n->hizq->hizq == NODO_NULO && // Hijo izqdo.
n->hizq->hder == NODO_NULO); // es hoja.
delete n->hizq;
n->hizq = NODO_NULO;
}
template <typename T>
inline void Abin<T>::eliminarHijoDrcho(nodo n)
{
assert(n != NODO_NULO);
assert(n->hder != NODO_NULO); // Existe hijo drcho.
assert(n->hder->hizq == NODO_NULO && // Hijo drcho.
n->hder->hder == NODO_NULO); // es hoja
delete n->hder;
n->hder = NODO_NULO;
}
template <typename T>
inline void Abin<T>::eliminarRaiz()
{
assert(r != NODO_NULO); // Árbol no vacío.
assert(r->hizq == NODO_NULO &&
r->hder == NODO_NULO); // La raíz es hoja.
delete r;
r = NODO_NULO;
}
template <typename T> inline bool Abin<T>::arbolVacio() const
{ return (r == NODO_NULO); }
template <typename T>
inline const T& Abin<T>::elemento(nodo n) const
{
assert(n != NODO_NULO);
return n->elto;
}
template <typename T>
inline T& Abin<T>::elemento(nodo n)
{
assert(n != NODO_NULO);
return n->elto;
}
template <typename T>
inline typename Abin<T>::nodo Abin<T>::raiz() const
{ return r; }
template <typename T> inline
typename Abin<T>::nodo Abin<T>::padre(nodo n) const
{
assert(n != NODO_NULO);
return n->padre;
}
template <typename T> inline
typename Abin<T>::nodo Abin<T>::hijoIzqdo(nodo n) const
{
assert(n != NODO_NULO);
return n->hizq;
}
template <typename T> inline
typename Abin<T>::nodo Abin<T>::hijoDrcho(nodo n) const
{
assert(n != NODO_NULO);
return n->hder;
}
template <typename T>
inline Abin<T>::Abin(const Abin<T>& A)
{
r = copiar(A.r); // Copiar raíz y descendientes.
}
template <typename T>
Abin<T>& Abin<T>::operator =(const Abin<T>& A)
{
if (this != &A) // Evitar autoasignación.
{
this->~Abin(); // Vaciar el árbol.
r = copiar(A.r); // Copiar raíz y descendientes.
}
return *this;
}
template <typename T>
inline Abin<T>::~Abin()
{
destruirNodos(r); // Vaciar el árbol.
}
/*--------------------------------------------------------*/
/* Métodos privados */
/*--------------------------------------------------------*/
// Destruye un nodo y todos sus descendientes
template <typename T>
void Abin<T>::destruirNodos(nodo& n)
{
if (n != NODO_NULO)
{
destruirNodos(n->hizq);
destruirNodos(n->hder);
delete n;
n = NODO_NULO;
}
}
// Devuelve una copia de un nodo y todos sus descendientes
template <typename T>
typename Abin<T>::nodo Abin<T>::copiar(nodo n)
{
nodo m = NODO_NULO;
if (n != NODO_NULO) {
m = new celda(n->elto); // Copiar n.
m->hizq = copiar(n->hizq); // Copiar subárbol izqdo.
if (m->hizq != NODO_NULO) m->hizq->padre = m;
m->hder = copiar(n->hder); // Copiar subárbol drcho.
if (m->hder != NODO_NULO) m->hder->padre = m;
}
return m;
}

// //Implementación de las funciones (Ejercicio 5, P1)

// template <typename T>
// int Abin<T>::alturaNodoRec(const nodo n){
//     if(n == Abin<T>::NODO_NULO)
//         return -1;
//     else 
//         return 1 + std::max( alturaNodoRec(n->hizq), alturaNodoRec(n->hder));
// }


// template <typename T>
// int Abin<T>::profundidadNodoRec(const nodo n){
//     if(n == Abin<T>::NODO_NULO)
//         return -1;
//     else
//         return 1 + profundidadNodoRec(n->padre);
// }



#endif // ABIN_H
