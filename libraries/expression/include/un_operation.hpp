#pragma once

#include "complex.hpp"
#include "IExpression.hpp"

#include <string>
#include <map>

class UnOperation : public Expression
{
public:
    Complex eval(std::map<std::string, Complex> m) const noexcept;
    std::string to_string() const noexcept;
    ~UnOperation() noexcept;

protected:
    const std::unique_ptr<Expression> a_;
    UnOperation(const Expression &a) noexcept;

    virtual std::string get_sign() const noexcept = 0;
    virtual Complex count(Complex a) const noexcept = 0;
};