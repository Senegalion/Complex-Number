#include "Complex.h"

Complex::Complex(double real, double imaginary) : realPart(real), imaginaryPart(imaginary) {}

Complex& Complex::operator+=(const Complex& otherComplexNumber) {
    realPart += otherComplexNumber.realPart;
    imaginaryPart += otherComplexNumber.imaginaryPart;
    return *this;
}

Complex& Complex::operator-=(const Complex& otherComplexNumber) {
    realPart -= otherComplexNumber.realPart;
    imaginaryPart -= otherComplexNumber.imaginaryPart;
    return *this;
}

Complex& Complex::operator*=(const Complex& otherComplexNumber) {
    double realPartOfTheFirstComplexNumber = realPart;
    realPart = realPart * otherComplexNumber.realPart - imaginaryPart * otherComplexNumber.imaginaryPart;
    imaginaryPart = realPartOfTheFirstComplexNumber * otherComplexNumber.imaginaryPart + imaginaryPart * otherComplexNumber.realPart;
    return *this;
}

Complex& Complex::operator/=(const Complex& otherComplexNumber) {
    double realPartOfTheFirstComplexNumber = realPart;
    double denominator = pow(otherComplexNumber.realPart, 2) + pow(otherComplexNumber.imaginaryPart, 2);
    realPart = ((realPart * otherComplexNumber.realPart) + (imaginaryPart * otherComplexNumber.imaginaryPart)) / denominator;
    imaginaryPart = ((imaginaryPart * otherComplexNumber.realPart) - (realPartOfTheFirstComplexNumber * otherComplexNumber.imaginaryPart)) / denominator;
    return *this;
}

bool Complex::operator==(const Complex& otherComplexNumber) {
    bool areRealPartsEqual = (realPart == otherComplexNumber.realPart);
    bool areImaginaryPartsEqual = (imaginaryPart == otherComplexNumber.imaginaryPart);

    return areRealPartsEqual && areImaginaryPartsEqual;
}

bool Complex::operator!=(const Complex& otherComplexNumber) {
    return (*this != otherComplexNumber);
}

bool operator==(double real, const Complex& complexNumber) {
    return (real == complexNumber.realPart) && (complexNumber.imaginaryPart == 0.0);
}

bool operator!=(double real, const Complex& complexNumber) {
	return !(real == complexNumber);
}

Complex operator+(const Complex& firstComplexNumber, const Complex& secondComplexNumber) {
    double newComplexNumberRealPart = firstComplexNumber.realPart + secondComplexNumber.realPart;
    double newComplexNumberImaginaryPart = firstComplexNumber.imaginaryPart + secondComplexNumber.imaginaryPart;
    return Complex(newComplexNumberRealPart, newComplexNumberImaginaryPart);
}

Complex operator-(const Complex& firstComplexNumber, const Complex& secondComplexNumber) {
    double newComplexNumberRealPart = firstComplexNumber.realPart - secondComplexNumber.realPart;
    double newComplexNumberImaginaryPart = firstComplexNumber.imaginaryPart - secondComplexNumber.imaginaryPart;
    return Complex(newComplexNumberRealPart, newComplexNumberImaginaryPart);
}

Complex operator*(const Complex& firstComplexNumber, const Complex& secondComplexNumber) {
    double newComplexNumberRealPart = firstComplexNumber.realPart * secondComplexNumber.realPart - firstComplexNumber.imaginaryPart * secondComplexNumber.imaginaryPart;
    double newComplexNumberImaginaryPart = firstComplexNumber.realPart * secondComplexNumber.imaginaryPart + firstComplexNumber.imaginaryPart * secondComplexNumber.realPart;
    return Complex(newComplexNumberRealPart, newComplexNumberImaginaryPart);
}

Complex operator/(const Complex& firstComplexNumber, const Complex& secondComplexNumber) {
    double denominator = pow(secondComplexNumber.realPart, 2) + pow(secondComplexNumber.imaginaryPart, 2);
    double newComplexNumberRealPart = ((firstComplexNumber.realPart * secondComplexNumber.realPart) + (firstComplexNumber.imaginaryPart * secondComplexNumber.imaginaryPart)) / denominator;
    double newComplexNumberImaginaryPart = ((firstComplexNumber.imaginaryPart * secondComplexNumber.realPart) - (firstComplexNumber.realPart * secondComplexNumber.imaginaryPart)) / denominator;
    return Complex(newComplexNumberRealPart, newComplexNumberImaginaryPart);
}

std::ostream& operator<<(std::ostream& out, const Complex& complexNumber) {
    out << complexNumber.realPart;
    if (complexNumber.imaginaryPart >= 0) {
        out << " + " << complexNumber.imaginaryPart << "i";
    } else {
        out << " - " << -complexNumber.imaginaryPart << "i";
    }
    return out;
}

double Complex::amplitude() const {
    return sqrt(pow(realPart, 2) + pow(imaginaryPart, 2));
}

double Complex::phase() const {
    return atan2(imaginaryPart, realPart);
}
