#pragma once
#include "un_operation.hpp"
#include "complex.hpp"

class Conjugate : public UnOperation
{
public:
    Conjugate(const Expression &a) noexcept;
    std::unique_ptr<Expression> clone() const noexcept;

protected:
    std::string get_sign() const noexcept;
    Complex count(Complex a) const noexcept;
};

class Negate : public UnOperation
{
public:
    Negate(const Expression &a) noexcept;
    std::unique_ptr<Expression> clone() const noexcept;

protected:
    std::string get_sign() const noexcept;
    Complex count(Complex a) const noexcept;
};

Conjugate operator~(const Expression &a);
Negate operator-(const Expression &a);