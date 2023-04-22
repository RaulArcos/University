#include "p1.hpp"

int main(){
    typedef char tElto;
    const tElto fin = '#'; // Fin de lectura.
    Abin<tElto> A;
    /*
    std::cout << "*** Lectura del árbol binario A ***\n";
    rellenarAbin(A, fin); // Desde std::cin
    ofstream fs("abin.dat"); // Abrir fichero de salida.
    imprimirAbin(fs, A, fin); // En fichero.
    fs.close();
    std::cout << "\n*** Árbol A guardado en fichero abin.dat ***\n";
    std::cout << "\n*** Lectura de árbol binario B de abin.dat ***\n";
    
    */

    //IMPRIME EL ARBOL B A PARTIR DEL FICHERO ABIN.DAT
    std::ifstream fe("Material_Arboles/abin.dat"); // Abrir fichero de entrada.
    rellenarAbin(fe, A); // Desde fichero.
    fe.close();
    std::cout << "\n*** Mostrar árbol binario B ***\n";
    imprimirAbin(A); // En std::std::cout

    //PRUEBAS DE P1.H
    std::cout << "\n\n\nPRUEBAS DE LA P1\n--------------------------------" <<std::endl;
    std::cout << "El arbol tiene: " << num_nodos(A) << " nodos." <<std::endl;
    std::cout << "Su altura es de: " << altura_abin(A) << "." <<std::endl;
    // std::cout << "La profundidad del nodo 'i' es: " << profundidadNodoRec(A,A.hijoDrcho(A.hijoDrcho(A.raiz()))) << "." <<std::endl;
    // std::cout << "(Representacion enlazada) El nodo 'k' tiene altura: " << A.alturaNodoRec(A.hijoDrcho(A.hijoDrcho(A.hijoDrcho(A.raiz())))) << "." <<std::endl;
    // std::cout << "(Representacion enlazada) El nodo 'k' tiene profundidad: " << A.profundidadNodoRec(A.hijoDrcho(A.hijoDrcho(A.hijoDrcho(A.raiz())))) << "." <<std::endl;
    // std::cout << "El arbol tiene un desequilibrio de: " << desequilibrioAbin(A) << "." <<std::endl;

    // if(pseudocompleto(A))
    //     std::cout << "El arbol ES pseudocompleto." << std::endl;
    // else
    //     std::cout << "El arbol NO ES pseudocompleto." << std::endl;
    return 0;
}