//hebras en C++ que procesan funciones con carga parametrica...
//17/01/2017
//A.T.

#include<iostream>
#include <thread>
using namespace std;

void hola(int hola) //codigo a ejecutar por la hebras con parametros
{
cout <<"Hola Mundo..." << this_thread::get_id()<< " ";
}
int main()
{ 
int nHilos = 100;
thread hilos[nHilos];
for(int i=0; i<nHilos; i++)hilos[i]=thread (hola, i); //las hebras se crean -y ejecutan de esta forma
for(int i=0; i<nHilos; i++)hilos[i].join();
cout << "Hilo main tambien saluda...";
return(0);
}