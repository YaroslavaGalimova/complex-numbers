#include "primitives.hpp"

Const::Const(Complex value) noexcept
    : value_(value)
{
}
std::unique_ptr<Expression> Const::clone() const noexcept { return std::make_unique<Const>(value_); }

Complex Const::eval(std::map<std::string, Complex> m) const noexcept { return value_; }

std::string Const::to_string() const noexcept { return value_.str(); }

Variable::Variable(std::string name) noexcept
    : name_(name)
{
}

std::unique_ptr<Expression> Variable::clone() const noexcept { return std::make_unique<Variable>(name_); }

Complex Variable::eval(std::map<std::string, Complex> m) const noexcept
{
    if (!m.contains(name_))
        return 0;
    return m[name_];
}

std::string Variable::to_string() const noexcept { return name_; }
