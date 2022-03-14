/*
Práctica 2 EDNL by Raúl Arcos Herrera
*/

#include <iostream>
#include <fstream>
#include "p2.h"
using namespace std;

/*
typedef char tElto;
const tElto fin = '#'; // Fin de lectura.
*/

typedef string tElto;
const tElto fin = "#"; // Fin de lectura.

int main ()
{
   
Abin<tElto> A,B,C;
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
ifstream fe2("../abinb.dat"); // Abrir fichero de entrada.
rellenarAbin(fe2, B); // Desde fichero.
fe2.close();
cout << "\n*** Mostrar árbol binario A ***\n";
imprimirAbin(A); // En std::cout
cout << "\n*** Mostrar árbol binario B ***\n";
imprimirAbin(B); // En std::cout




cout << "\n\n\nPRUEBAS DE LA P2\n--------------------------------" <<endl;
if(similaresAbin(A,B))
    cout << "Los arboles A y B SON SIMILARES." << endl;
else 
    cout << "Los arboles A y B NO SON SIMILARES." << endl;

cout << "Arbol A reflejado: " << endl;
imprimirAbin(reflejado(A));

}