#include <iostream>
#include "expression.hpp"

int main(void) {
    const Add expr(Const(2), Const(3));
    std::cout << expr.eval({{"x", 2}}) << std::endl;
    return 0;

    // some changes
}