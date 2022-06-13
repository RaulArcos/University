#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#define tam 1000

int m1[tam][tam];
int m2[tam][tam];

int m[tam][tam];

void par (int in, int su){
    for (int i = 0; i < tam; i++){
        for (int j = 0; j < tam; j++){
            for (int k = in; k < su; k++)
                m[i][j] = m1[i][j] + (m1[i][k] * m2[k][j]);
        }
    }
}

int main(){
    std::cout << "Preparando matriz" << std::endl;
    for (int i = 0; i < tam; i++){
        for (int j = 0; j < tam; j++){
            m1[i][j] = 1;
            m2[i][j] = 1;
        }
    }
    auto iniciar = std::chrono::system_clock::now();
    std::thread t0(par, 0,  499);
    std::thread t1(par, 500, 999);
    a0.join(); 
    a1.join(); 
    auto acabar = std::chrono::system_clock::now();
    auto lapso2 = std::chrono::duration_cast<std::chrono::milliseconds>(acabar - iniciar);
    std::cout << "Paralelo para 2 hilos en   " << lapso2.count() << " milisegundos\n";

    iniciar = std::chrono::system_clock::now();
    std::thread b0(par, 0,  249);
    std::thread b1(par, 250, 499);
    std::thread b2(par, 500, 749);
    std::thread b3(par, 750, 999);
    b0.join(); 
    b1.join(); 
    b2.join(); 
    b3.join();
    acabar = std::chrono::system_clock::now();
    lapso2 = std::chrono::duration_cast<std::chrono::milliseconds>(acabar - iniciar);
    std::cout << "Paralelo para 4 hilos en   " << lapso2.count() << " milisegundos\n";

    auto iniciar = std::chrono::system_clock::now();
    std::thread c0(par, 0,  166);
    std::thread c1(par, 167, 334);
    std::thread c2(par, 335, 501);
    std::thread c3(par, 502, 668);
    std::thread c4(par, 669, 835);
    std::thread c5(par, 836, 999);
    c0.join(); 
    c1.join(); 
    c2.join(); 
    c3.join();
    c4.join();
    c5.join();
    auto acabar = std::chrono::system_clock::now();
    auto lapso2 = std::chrono::duration_cast<std::chrono::milliseconds>(acabar - iniciar);
    std::cout << "Paralelo para 6 hilos en   " << lapso2.count() << " milisegundos\n";

    auto iniciar = std::chrono::system_clock::now();
    std::thread d0(par, 0,  124);
    std::thread d1(par, 125, 250);
    std::thread d2(par, 251, 375);
    std::thread d3(par, 376, 500);
    std::thread d4(par, 501, 625);
    std::thread d5(par, 626, 750);
    std::thread d6(par, 751, 875);
    std::thread d7(par, 876, 999);
    d0.join(); 
    d1.join(); 
    d2.join(); 
    d3.join();
    d4.join();
    d5.join();
    d6.join();
    d7.join();
    auto acabar = std::chrono::system_clock::now();
    auto lapso2 = std::chrono::duration_cast<std::chrono::milliseconds>(acabar - iniciar);
    std::cout << "Paralelo para 8 hilos en   " << lapso2.count() << " milisegundos\n";

    auto iniciar = std::chrono::system_clock::now();
    std::thread e0(par, 0,  99);
    std::thread e1(par, 100, 199);
    std::thread e2(par, 200, 299);
    std::thread e3(par, 300, 299);
    std::thread e4(par, 400, 499);
    std::thread e5(par, 500, 599);
    std::thread e6(par, 600, 699);
    std::thread e7(par, 700, 799);
    std::thread e8(par, 800, 899);
    std::thread e9(par, 900, 999);
    e0.join(); 
    e1.join(); 
    e2.join(); 
    e3.join();
    e4.join();
    e5.join();
    e6.join();
    e7.join();
    e8.join();
    e9.join();
    auto acabar = std::chrono::system_clock::now();
    auto lapso2 = std::chrono::duration_cast<std::chrono::milliseconds>(acabar - iniciar);
    std::cout << "Paralelo para 10 hilos en   " << lapso2.count() << " milisegundos\n";

    auto iniciar = std::chrono::system_clock::now();
    std::thread f0(par, 0,  83);
    std::thread f1(par, 84, 168);
    std::thread f2(par, 169, 252);
    std::thread f3(par, 253, 336);
    std::thread f4(par, 337, 420);
    std::thread f5(par, 421, 504);
    std::thread f6(par, 505, 588);
    std::thread f7(par, 589, 672);
    std::thread f8(par, 673, 756);
    std::thread f9(par, 757, 840);
    std::thread f10(par, 841, 924);
    std::thread f11(par, 925, 999);
    f0.join(); 
    f1.join(); 
    f2.join(); 
    f3.join();
    f4.join();
    f5.join();
    f6.join();
    f7.join();
    f8.join();
    f9.join();
    f10.join();
    f11.join();
    auto acabar = std::chrono::system_clock::now();
    auto lapso2 = std::chrono::duration_cast<std::chrono::milliseconds>(acabar - iniciar);
    std::cout << "Paralelo para 12 hilos en   " << lapso2.count() << " milisegundos\n";    
    
    system("pause");
    return 0;     
}

