#pragma once
#include <string>
#include <map>
#include "complex.hpp"
#include <memory>

class Expression
{
public:
    virtual Complex eval(std::map<std::string, Complex> m) const noexcept;
    virtual std::string to_string() const noexcept;
    virtual std::unique_ptr<Expression> clone() const noexcept;
    virtual ~Expression() noexcept = default;
};
