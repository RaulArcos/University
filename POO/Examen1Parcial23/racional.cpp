#include <iostream>

class racional{
    public:
        racional(int num = 0, int den = 1): n(num/mcd(num,den)), d(den/mcd(num,den)){}
        racional(const 
        racional& r): n(r.n), d(r.d){}
        friend std::ostream& operator<<(std::ostream& os, const racional& r);
        // racional& operator =(const racional& r);
        unsigned int absoluto(int num){
            if(num < 0){
                num *= -1;
            }
            return num;
        }
    private:
        int n,d;
        static int mcd(int num,int den){
            if (den == 0) {
                return num;
            }
            return mcd(den, num % den);
        }
      
};

// racional& racional::operator=(const racional& r){
//     n = r.n;
//     d = r.d;
//     return *this;
// }

std::ostream& racional::operator<<(std::ostream& os, const racional& r){
    int num = absoluto(r.n);
    int den = absoluto(r.d);
    if(r.n<0 && r.d<0 || r.n>=0 && r.d>=0){
        os<<num<<"/"<<den;
    }
    else if( r.n>=0 && r.d<0 || r.n<0 && r.d>=0){
        os<<"-"<<num<<"/"<<den;
    }
    return os;
}

int main(){
    racional v=5;
    racional w=v;
    v=w;
    racional s;
    s = racional{9,6};
    racional t = -4;
    return 0;
}

//No necesitamos ni operador de asignacio


