#include <iostream>
#include <vector>
#include <thread>

int main(){
    std::vector<std::thread> threads;
    int num = 1000;
    int contador = 0;

    for(int i = 0; i < num; i++){
        threads.push_back(std::thread([&](){
            for(int i = 0; i < num; i++){
                contador++;
            }
        }));
    }
    for(auto& thread : threads){
        thread.join();
    }

    std::cout << contador << std::endl;
    return 0;
}