#include "bin_operations.hpp"

Add::Add(const Expression &a, const Expression &b) noexcept
    : BinOperation(a, b)
{
}

std::unique_ptr<Expression> Add::clone() const noexcept { return std::make_unique<Add>(*a_, *b_); }

std::string Add::get_sign() const noexcept { return "+"; }

Complex Add::count(Complex a, Complex b) const noexcept { return a + b; }

Subtract::Subtract(const Expression &a, const Expression &b) noexcept
    : BinOperation(a, b)
{
}

std::unique_ptr<Expression> Subtract::clone() const noexcept { return std::make_unique<Subtract>(*a_, *b_); }

std::string Subtract::get_sign() const noexcept { return "-"; }

Complex Subtract::count(Complex a, Complex b) const noexcept { return a - b; }

Multiply::Multiply(const Expression &a, const Expression &b) noexcept
    : BinOperation(a, b)
{
}

std::unique_ptr<Expression> Multiply::clone() const noexcept { return std::make_unique<Multiply>(*a_, *b_); }

std::string Multiply::get_sign() const noexcept { return "*"; }

Complex Multiply::count(Complex a, Complex b) const noexcept { return a * b; }

Divide::Divide(const Expression &a, const Expression &b) noexcept
    : BinOperation(a, b)
{
}

std::unique_ptr<Expression> Divide::clone() const noexcept { return std::make_unique<Divide>(*a_, *b_); }

std::string Divide::get_sign() const noexcept { return "/"; }

Complex Divide::count(Complex a, Complex b) const noexcept { return a / b; }

Add operator+(const Expression &lhs, const Expression &rhs)
{
    return Add(lhs, rhs);
}

Subtract operator-(const Expression &lhs, const Expression &rhs)
{
    return Subtract(lhs, rhs);
}

Multiply operator*(const Expression &lhs, const Expression &rhs)
{
    return Multiply(lhs, rhs);
}

Divide operator/(const Expression &lhs, const Expression &rhs)
{
    return Divide(lhs, rhs);
}