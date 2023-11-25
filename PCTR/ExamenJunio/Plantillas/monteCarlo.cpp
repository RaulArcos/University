#include <iostream>
#include <random>
#include <thread>
#include <mutex>

using namespace std;

//variable compartida
    int totalHits = 0;

//protocolo de E.M (cerrojo en este caso)
    mutex l;

//funcion a integrar con monteCarlo
double fun (double x) { /*hace cosas*/}

void monteCarlo (int numPuntos) {
    int ip = 0;

    //generacion de numero randoms reentrantes (con rand() no sale)
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(0.0, 1.0); //entre 0 y 1

    for (int i = 0; i < numPuntos; i++) {
        double x = dis(gen);
        double y = dis(gen);
        if (y <= fun(x)) ip++;
    }

    //S.C
        l.lock();
        totalHits += ip;
        l.unlock();
}

int main() {
    //pedir datos

    //crear vector
    thread hilos[numTareas];
    
    //iniciar tiempo
    auto iniciar = std::chrono::system_clock::now();

    //lanzar los hilos
    for(int i = 0; i < numTareas; i++) hilos[i] = thread(monteCarlo, nPuntos);
    for(int i = 0; i < numTareas; i++) hilos[i].join();

    auto acabar = std::chrono::system_clock::now();
    auto lapso2 = std::chrono::duration_cast<std::chrono::milliseconds>(acabar - iniciar);
    
    //imprimir resultado
    std::cout << "Aproximacion: " << (double)totalHits / (numPuntos * numTareas) << std::endl;
    std::cout << "Paralelo para " << numTareas << " hilos en " << lapso2.count() << " milisegundos\n";
    return 0;     
}