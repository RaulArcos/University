//----------------------------------CPP----------------------------------
    //compilacion: g++ ----.cpp -o salida -pthread -std=c++11
    //ejecucion: ./----


    //compilacion: g++ -std=c++11 -pthread intParalela.cpp
    //ejecucion: ./a

#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <random>
#include <vector>
#include <condition_variable> //monitores
#include <atomic> //atomic
#include <semaphore> //semaforos
#include <latch> //barrera de un solo uso
#include <barrier> //barrera reutilizable

using namespace std;

    //NUMEROS RANDOMS (no reentrante), no vale para los hilos
        srand(time(NULL)); //asignas una semilla
        a = rand(); // Genera un valor entre 0 y RAND_MAX
        a = rand() % 20; // Genera un valor entre 0 y 19
        a = 25 + rand() % 100; 	// Genera un valor entre 25 y 124
        
    //NUMEROS RANDOMS (reentrante), vale para los hilos
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis(1, 2); //asignas el rango entre 1 y 2
        dis(gen); //genera numero aleatorio

    //TIEMPOS
        chrono::milliseconds t{1000};
        this_thread::sleep_for(t); //duerme el hilo

        //cronometra el tiempo
        auto iniciar = std::chrono::system_clock::now();
        auto acabar = std::chrono::system_clock::now();
        auto lapso2 = std::chrono::duration_cast<std::chrono::milliseconds>(acabar - iniciar);
        lapso2.count(); //ms

    //E/S
        //E
            std::cin >> numPuntos;
        //S
            std::cout << "Ingrese el numero de puntos: " << std::endl;

    //CERROJO
        mutex l;
        l.lock();
        //S.C
        l.unlock();
    
    //CERROJO REENTRANTE
        std::recursive_mutex lr;
        lr.lock();
        //S.C
        lr.unlock();

    //OBJETO ATOMICOS
        std::atomic_int x(0);
        //S.C

        //tambien se puede ejecutar sobre un tipo creado por el programador
        std::atomic<int> valor;
        void incremento() { ++valor;} //pero hay que implementar funciones para poder modificar u observar el valor
        void decremento() { --valor;}
        int obtener() { return valor.load();}


    //SEMAFOROS (desde 2020)
        //COUNTING
        std::counting_semaphore misemaforocounting(1);

        misemaforocounting.acquire();
        //S.C
        misemaforocounting.release();

        //BINARY (solo tiene dos estados posibles)
        std::binary_semaphore misemaforo(1);

        misemaforo.acquire();
        //S.C
        misemaforo.release();

    //BARRERAS (desde 2020)
        std::barrier sync_point(tamaño, funcion);
        sync_point.arrive_and_wait();

    //HILOS
        void fun (int i) { /*hace cosas */ } //funcion que ejecuta los hilos

        int main() {
            thread hilos[nHilos]; //crear un vector de hilos
            for(int i=0; i<nHilos; i++) hilos[i] = thread (fun, i); //las hebras se crean -y ejecutan de esta forma (no hace falta start en cpp)
            for(int i=0; i<nHilos; i++) hilos[i].join();

            //con la clase vector
            vector <thread> threads;
            for(int i = 0; i < nHilos; i++ ) hilos.push_back (thread (fun, i));
            for(auto& i : hilos) i->join();
        }

    //FUNCIONES HILOS
        std::this_thread::get_id(); //devuelve el id del hilo que se este ejecutando
        std::this_thread::yield(); //replanifica las hebras, siendo la hebra con la que es llamada la funcion la que deja que las demas se ejecuten
        
        std::once_flag flag; //flag para la funcion call_once
        std::call_once(flag, fun); //hace q la funcion fun, solo se llame 1 VEZ, independientemente del numero de hebras que la utilicen
