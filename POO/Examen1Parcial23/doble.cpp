#include <iostream>

class doble{
    public:
        doble(double dato = 0): dato_(dato){}
        explicit operator double() const {return dato_;}

    private:
        double dato_;

};

int main(){ 
    double a=1.5,b=10.5; 
    double c=5.25, d=c ; 
    std::cout<<c/d*b+b*c -c*c/b+b/c<<std::endl; //65 
    d=a=b+=c; 
    std::cout<<d<< ' '<<a<< ' '<<b<< ' '<<c<<std::endl; //15,75 15,75 15,75 5,25 
}