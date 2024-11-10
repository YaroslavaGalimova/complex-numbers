#pragma once

#include "IExpression.hpp"
#include "bin_operation.hpp"
#include "complex.hpp"

class Add : public BinOperation
{
public:
    Add(const Expression &a, const Expression &b) noexcept;
    std::unique_ptr<Expression> clone() const noexcept;

protected:
    std::string get_sign() const noexcept;
    Complex count(Complex a, Complex b) const noexcept;
};

class Subtract : public BinOperation
{
public:
    Subtract(const Expression &a, const Expression &b) noexcept;
    std::unique_ptr<Expression> clone() const noexcept;

protected:
    std::string get_sign() const noexcept;
    Complex count(Complex a, Complex b) const noexcept;
};

class Multiply : public BinOperation
{
public:
    Multiply(const Expression &a, const Expression &b) noexcept;
    std::unique_ptr<Expression> clone() const noexcept;

protected:
    std::string get_sign() const noexcept;
    Complex count(Complex a, Complex b) const noexcept;
};

class Divide : public BinOperation
{
public:
    Divide(const Expression &a, const Expression &b) noexcept;
    std::unique_ptr<Expression> clone() const noexcept;

protected:
    std::string get_sign() const noexcept;
    Complex count(Complex a, Complex b) const noexcept;
};

Add operator+(const Expression &lhs, const Expression &rhs);
Subtract operator-(const Expression &lhs, const Expression &rhs);
Multiply operator*(const Expression &lhs, const Expression &rhs);
Divide operator/(const Expression &lhs, const Expression &rhs);