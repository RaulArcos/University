#include <iostream>
#include <fstream>
#include "../agen.h"
#include "../agen_E-S.h"
#include "p3.h"

using namespace std;
typedef char tElto;
const tElto fin = '#'; // fin de lectura
int main ()
{
 Agen<tElto> A;
 /*
 cout << "*** Lectura del arbol A ***\n";
 rellenarAgen(A, fin); // Desde std::cin
 
 ofstream fs("agen.dat"); // Abrir fichero de salida.
 imprimirAgen(fs, A, fin); // En fichero.
 fs.close();
 */
 cout << "\n*** Arbol A guardado en fichero agen.dat ***\n";
 cout << "\n*** Lectura de arbol A de agen.dat ***\n";
 ifstream fe("agen.dat"); // Abrir fichero de entrada.
 rellenarAgen(fe, A); // Desde fichero.
 fe.close();
 cout << "\n*** Mostrar arbol A ***\n";
 imprimirAgen(A); // En std::cout


cout << "\n\n\n" <<"-------------PRUEBAS DE LA P3------------" << endl;
cout << "Numero de hijos del nodo Raiz: " << numHijosAgen(A.raiz(),A) << endl;
cout << "El grado del Arbol es: " << gradoAgen(A) << endl;
cout << "La profundidad de Arbol es: " << profundidadNodoAgen(A.hijoIzqdo(A.raiz()),A);
} 
