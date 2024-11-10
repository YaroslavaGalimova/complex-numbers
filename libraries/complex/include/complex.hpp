#pragma once
#include <iostream>
#include <string>
#include <cmath>
#include <stdexcept>

class Complex {
public:
    Complex(double real = 0, double imag = 0) noexcept;
    Complex(const Complex& other) noexcept = default;
    Complex(Complex&& other) noexcept = default;

    double real() const noexcept;
    double imag() const noexcept;
    double abs() const noexcept;
    double norm() const noexcept;
    std::string str() const noexcept;

    Complex operator+ (const Complex& c) const noexcept;
    Complex operator- (const Complex& c) const noexcept;
    Complex operator* (const Complex& c) const noexcept;
    Complex operator/ (const Complex& c) const;

    Complex& operator= (const Complex& c) noexcept = default;
    Complex& operator= (Complex&& c) noexcept = default;

    Complex& operator+= (const Complex& c) noexcept;
    Complex& operator-= (const Complex& c) noexcept;
    Complex& operator*= (const Complex& c) noexcept;
    Complex& operator/= (const Complex& c);

    bool operator== (const Complex& c) const noexcept;
    bool operator!= (const Complex& c) const noexcept;

    Complex operator~ () const noexcept;
    Complex operator- () const noexcept;

    ~Complex() = default;
    friend std::ostream& operator<< (std::ostream& stream, const Complex& c);

private:
    double real_;
    double imag_;
};


