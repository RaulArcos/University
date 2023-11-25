#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#define tam 1000

int m1[tam][tam];
int m2[tam][tam];

int m[tam][tam];

void sec (int ini, int fin){
    int res = 0;
    for (int i = ini; i <= fin; i++){
        for (int j = ini; j <= fin; j++){
            res = 0;
            for (int k = ini; k <= fin; k++)
                res = res + (m1[j][k] * m2[k][i]);
            m[j][i] = res;
        }
    }
}

int main(){
    for (int i = 0; i < tam; i++){
        for (int j = 0; j < tam; j++){
            m1[i][j] = 1;
            m2[i][j] = 1;
        }
    }

    auto iniciar = std::chrono::system_clock::now();
    std::thread t(sec, 0, tam - 1);
    t.join();
    auto acabar = std::chrono::system_clock::now();
    auto lapso1 = std::chrono::duration_cast<std::chrono::milliseconds>(acabar - iniciar);

    std::cout << "Secuencial en " << lapso1.count() << " milisegundos";
    system("pause");
return 0;
}
