#pragma once

#include "complex.hpp"
#include "IExpression.hpp"

#include <string>
#include <map>

class Const : public Expression
{
public:
    Const(Complex value) noexcept;
    std::unique_ptr<Expression> clone() const noexcept;
    Complex eval(std::map<std::string, Complex> m) const noexcept;
    std::string to_string() const noexcept;
    ~Const() noexcept = default;

private:
    Complex value_;
};

class Variable : public Expression
{
public:
    Variable(std::string name) noexcept;
    std::unique_ptr<Expression> clone() const noexcept;
    Complex eval(std::map<std::string, Complex> m) const noexcept;
    std::string to_string() const noexcept;
    ~Variable() noexcept = default;

private:
    std::string name_;
};