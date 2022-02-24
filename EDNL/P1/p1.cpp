/*
Práctica 1 EDNL by Raúl Arcos Herrera
*/

#include <iostream>
#include <fstream>
#include "p1.h"
using namespace std;
typedef char tElto;
const tElto fin = '#'; // Fin de lectura.
int main ()
{
   
Abin<tElto> A;
/*
 cout << "*** Lectura del árbol binario A ***\n";
 rellenarAbin(A, fin); // Desde std::cin
 ofstream fs("abin.dat"); // Abrir fichero de salida.
 imprimirAbin(fs, A, fin); // En fichero.
 fs.close();
 cout << "\n*** Árbol A guardado en fichero abin.dat ***\n";
 cout << "\n*** Lectura de árbol binario B de abin.dat ***\n";
 
*/

//IMPRIME EL ARBOL B A PARTIR DEL FICHERO ABIN.DAT
ifstream fe("../abin.dat"); // Abrir fichero de entrada.
rellenarAbin(fe, A); // Desde fichero.
fe.close();
cout << "\n*** Mostrar árbol binario B ***\n";
imprimirAbin(A); // En std::cout

//PRUEBAS DE P1.H
cout << "\n\n\nPRUEBAS DE LA P1\n--------------------------------" <<endl;
cout << "El arbol tiene: " << numNodos(A) << " nodos." <<endl;
cout << "Su altura es de: " << alturaAbin(A) << "." <<endl;
cout << "La profundidad del nodo 'i' es: " << profundidadNodoRec(A,A.hijoDrcho(A.hijoDrcho(A.raiz()))) << "." <<endl;
cout << "(Representacion enlazada) El nodo 'k' tiene altura: " << A.alturaNodoRec(A.hijoDrcho(A.hijoDrcho(A.hijoDrcho(A.raiz())))) << "." <<endl;
cout << "(Representacion enlazada) El nodo 'k' tiene profundidad: " << A.profundidadNodoRec(A.hijoDrcho(A.hijoDrcho(A.hijoDrcho(A.raiz())))) << "." <<endl;
cout << "El arbol tiene un desequilibrio de: " << desequilibrioAbin(A) << "." <<endl;

if(pseudocompleto(A))
    cout << "El arbol ES pseudocompleto." << endl;
else
    cout << "El arbol NO ES pseudocompleto." << endl;
} 
