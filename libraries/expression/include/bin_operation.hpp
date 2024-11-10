#pragma once

#include "complex.hpp"
#include "IExpression.hpp"

#include <string>
#include <map>

class BinOperation : public Expression
{
public:
    Complex eval(std::map<std::string, Complex> m) const noexcept;
    std::string to_string() const noexcept;
    ~BinOperation() noexcept;

protected:
    const std::unique_ptr<Expression> a_;
    const std::unique_ptr<Expression> b_;
    BinOperation(const Expression &a, const Expression &b) noexcept;

    virtual std::string get_sign() const noexcept = 0;
    virtual Complex count(Complex a, Complex b) const noexcept = 0;
};