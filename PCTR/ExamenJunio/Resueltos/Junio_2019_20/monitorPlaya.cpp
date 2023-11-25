#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>

using namespace std;

class monitorPlaya {
    unsigned aforo, aforoMax;
    mutex em;
    condition_variable cv;

    public:
        monitorPlaya() : aforo{0}, aforoMax{100} {}

        void entrarPlaya () {
            unique_lock <mutex> lck{em};
            while (aforo >= aforoMax) {
                cout << "Persona" << this_thread::get_id << "esperando en la cola" << endl;
                cv.wait(lck);
            }
            aforo++;
            cout << "Persona" << this_thread::get_id << "llega a la playa" << endl;
            cout << "Aforo actual: " << aforo << endl;
        }

        void salirPlaya() {
            unique_lock <mutex> lck{em};
            aforo--;

            cout << "Persona" << this_thread::get_id << "abandona la playa" << endl;
            cout << "Aforo actual: " << aforo << endl;

            cv.notify_all();
        }
};

void playa (monitorPlaya &mp) {
    mp.entrarPlaya();
    chrono::milliseconds t{1000};
    this_thread::sleep_for(t);
    mp.salirPlaya();
}

int main (int argc, char const *argv[]) {
    monitorPlaya mp;
    thread personas[200];

    for (unsigned i = 0; i < 200; ++i) personas[i] = thread{playa, ref(mp)};
    for (unsigned i = 0; i < 200; ++i) personas[i].join();
return 0;
}