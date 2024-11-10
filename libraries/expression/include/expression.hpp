#pragma once

#include "primitives.hpp"
#include "bin_operations.hpp"
#include "un_operations.hpp"

#include <iostream>

inline std::ostream &operator<<(std::ostream &stream, const Expression &expression)
{
    stream << expression.to_string();
    return stream;
}
