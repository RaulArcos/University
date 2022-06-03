#include <iostream>
#include <string>

//Clase Par

template <class T1, class T2>
class Par{

    public: 
        Par(): prime(T1()), segun(T2()){}
        Par(const T1& p, const T2& s): prime(p), segun(s){}
        T1 primero() const {return prime;}
        T1& primero() {return prime;}
        T2 segundo() const {return segun;}
        T2& segundo() {return segun;}

    private:
        T1 prime;
        T2 segun;
};

//Sobrecarga del operador << (Apartado a)
template <class T1, class T2>
std::ostream& operator <<(std::ostream& bufferDeFlujo, const Par<T1,T2>& par){

    bufferDeFlujo << "Primero: " << par.primero() << "Segundo: " << par.segundo() << std::endl;
    return bufferDeFlujo;

}

//sobrecarga del operador + de la clase racional (Apartado b)
template <class T1, class T2>
class Racional: public Par<int, int>{

    public:
        Racional(int numerador, int denominador):Par(numerador,denominador){}
    private:
};

template <class T1, class T2>
Racional operator + (const Racional& r1, const Racional& r2){
    return Racional(r1.primero() * r2.segundo() + r2.primero() + r1.segundo(), r1.segundo()*r2.segundo());
}

