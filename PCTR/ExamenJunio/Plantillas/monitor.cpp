#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>

using namespace std;

//clase del monitor
    class monitor {
        unsigned aforo, aforoMax;
        mutex em;
        condition_variable cv;

        public:
            //constructor
            monitor() : aforo{0}, aforoMax{100} {}

            //funciones monitor
            void entrar () {
                unique_lock <mutex> lck{em};
                while (aforo >= aforoMax) {cv.wait(lck);}
                //S.C++
            }

            void salir() {
                unique_lock <mutex> lck{em};
                //S.C--
                cv.notify_all();
            }
    };

//funcion que ejecutan los hilos
    void fun (monitor &m) {
        m.entrar();
        chrono::milliseconds t{1000}; //mandar a los hilos a dormir
        this_thread::sleep_for(t);
        m.salir();
    }

int main (int argc, char const *argv[]) {
    monitor m;
    thread hilos[200]; //vector de hilos

    for (unsigned i = 0; i < 200; ++i) hilos[i] = thread{fun, ref(m)};
    for (unsigned i = 0; i < 200; ++i) hilos[i].join();
return 0;
}