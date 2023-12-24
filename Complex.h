#pragma once
#include <iostream>
#include <math.h>

class Complex {
public:
    double realPart;
    double imaginaryPart;

    Complex(double real = 0.0, double imaginary = 0.0);

    Complex& operator+=(const Complex& otherComplexNumber);
    Complex& operator-=(const Complex& otherComplexNumber);
    Complex& operator*=(const Complex& otherComplexNumber);
    Complex& operator/=(const Complex& otherComplexNumber);

    bool operator==(const Complex& otherComplexNumber);
    bool operator!=(const Complex& ptherComplexNumber);

    double amplitude() const;
    double phase() const;
};

Complex operator+(const Complex& firstComplexNumber, const Complex& secondComplexNumber);
Complex operator-(const Complex& firstComplexNumber, const Complex& secondComplexNumber);
Complex operator*(const Complex& firstComplexNumber, const Complex& secondComplexNumber);
Complex operator/(const Complex& firstComplexNumber, const Complex& secondComplexNumber);
bool operator==(double real, const Complex& complexNumber);
bool operator!=(double real, const Complex& complexNumber);

std::ostream& operator<<(std::ostream& out, const Complex& complexNumber);
