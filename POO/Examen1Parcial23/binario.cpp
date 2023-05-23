#include <iostream>
#include <climits>

class refBit {
    public:
        refBit(unsigned* const ptr, const size_t offset)
        : ptr(ptr), mask(1u << offset) {}
        operator bool() const {
            return ((*ptr & mask) != 0u);
        }
        refBit& operator=(const bool value) {
            if (value) {
                *ptr |= mask;
            } else {
                *ptr &= ~mask;
            }
            return *this;
        }
    private:
        unsigned* const ptr;
        const unsigned int mask;
};

class Binario{
    
    Binario(const char* cad): n(std::strlen(cad)), m((std::strlen(cad)+1)/bits_elto + 1){}

    refBit operator[](size_t i);
    bool bit(size_t i) const;

private:
    static const size_t bits_elto = CHAR_BIT * sizeof(unsigned); // CHARBIT = bits por byte
    const size_t n; // longitud en bits
    const size_t m; // longitud del vector de enteros
    unsigned *bits; // vector de enteros
};

int main(){

    return 0;
}