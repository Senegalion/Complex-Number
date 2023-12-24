#include "Complex.h"

void addingNumbers() {
	Complex a(1.0, 1.0);
    Complex b(2.1, -8.0);
    Complex c(-3.0, 4.5);
    
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "c = " << c << std::endl;
    
    a += b += c;
    std::cout << "a += b += c: " << a << std::endl;
    
    (a += b) += c;
    std::cout << "(a += b) += c: " << a << std::endl;
    
    std::cout << "a + 7: " << a + 7 << std::endl;
    std::cout << "7 + a: " << 7 + a << std::endl;
    
}

void multiplicatingNumbers() {
	Complex a(1.0, 1.0);
    Complex b(1.0, -1.0);
    Complex c(1.0, 1.0);
    
    a *= b *= c;
    std::cout << "a *= b *= c: " << a << std::endl;
    
    (a *= b) *= c;
    std::cout << "(a *= b) *= c: " << a << std::endl;
    
    std::cout << "b * 5: " << b * 5 << std::endl;
    std::cout << "5 * b: " << 5 * b << std::endl;
}

void comparisingNumbers() {
	Complex c(1.0, 1.0);
    std::cout << "c == 3.5: " << (c == 3.5) << std::endl;
    std::cout << "3.5 == c: " << (3.5 == c) << std::endl;
    
    std::cout << "c amplitude: " << c.amplitude() << std::endl;
    std::cout << "c phase: " << c.phase() << std::endl;
}

int main() {
    addingNumbers();

	multiplicatingNumbers();

	comparisingNumbers();

    return 0;
}
