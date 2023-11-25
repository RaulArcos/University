#include <iostream>
#include <random>
#include <thread>
#include <mutex>

using namespace std;

int totalHits = 0, numPuntos, numTareas;
mutex l;

double fun (double x) { return x * x;}

void monteCarlo () {
    int ip = 0;

    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(0.0, 1.0);

    for (int i = 0; i < numPuntos; i++) {
        double x = dis(gen);
        double y = dis(gen);
        if (y <= fun(x)) ip++;
    }

    l.lock();
    totalHits += ip;
    l.unlock();
}

int main() {

    std::cout << "Ingrese el numero de puntos: ";
    std::cin >> numPuntos;

    std::cout << "Ingrese el numero de tareas: ";
    std::cin >> numTareas;

    thread hilos[numTareas];
    auto iniciar = std::chrono::system_clock::now();

    for(int i = 0; i < numTareas; i++) hilos[i] = thread(monteCarlo);
    for(int i = 0; i < numTareas; i++) hilos[i].join();

    auto acabar = std::chrono::system_clock::now();
    auto lapso2 = std::chrono::duration_cast<std::chrono::milliseconds>(acabar - iniciar);
    
    std::cout << "Aproximacion: " << (double)totalHits / (numPuntos * numTareas) << std::endl;
    std::cout << "Paralelo para " << numTareas << " hilos en " << lapso2.count() << " milisegundos\n";
    return 0;     
}