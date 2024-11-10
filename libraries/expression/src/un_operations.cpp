#include "un_operations.hpp"

Conjugate::Conjugate(const Expression &a) noexcept
    : UnOperation(a)
{
}

std::unique_ptr<Expression> Conjugate::clone() const noexcept { return std::make_unique<Conjugate>(*a_); }

std::string Conjugate::get_sign() const noexcept { return "~"; }

Complex Conjugate::count(Complex a) const noexcept { return ~a; }

Negate::Negate(const Expression &a) noexcept
    : UnOperation(a)
{
}

std::unique_ptr<Expression> Negate::clone() const noexcept { return std::make_unique<Negate>(*a_); }

std::string Negate::get_sign() const noexcept { return "-"; }

Complex Negate::count(Complex a) const noexcept { return -a; }

Conjugate operator~(const Expression &a)
{
    return Conjugate(a);
}

Negate operator-(const Expression &a)
{
    return Negate(a);
}
