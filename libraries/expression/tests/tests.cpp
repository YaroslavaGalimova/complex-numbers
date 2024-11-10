#include "complex.hpp"
#include "expression.hpp"

#include <catch2/catch_test_macros.hpp>
#include <sstream>

TEST_CASE("Testing Constants and Variables")
{
    Const e = Const(2.71);
    Variable x = Variable("x");
    REQUIRE(e.eval({{"x", 2}}) == 2.71);
    REQUIRE(x.eval({{"x", 2}}) == 2);
    REQUIRE(x.eval({{"abracadabra", 90}, {"x", 8}}) == 8);
    REQUIRE(x.eval({{"x", 2}, {"y", 3}}) == 2);
    REQUIRE(x.eval({{"x", 2}, {"y", 3}, {"z", 4}, {"a", 5}}) == 2);
    REQUIRE(e.eval({}) == 2.71);
}

TEST_CASE("Testing binary operations")
{
    Const e = Const(2.71);
    Const a = Const(1);
    Variable x = Variable("x");
    Variable y = Variable("y");
    SECTION("Add")
    {
        REQUIRE(Add(e, a).eval({}) == 3.71);
        REQUIRE(Add(e, x).eval({{"x", 2}}) == 4.71);
        REQUIRE(Add(x, y).eval({{"x", 2}, {"y", 3}}) == 5);
    }
    SECTION("Subtract")
    {
        REQUIRE(Subtract(e, a).eval({}) == 1.71);
        REQUIRE(Subtract(e, x).eval({{"x", 2}}) == 0.71);
        REQUIRE(Subtract(x, y).eval({{"x", 2}, {"y", 3}}) == -1);
    }
    SECTION("Multiply")
    {
        REQUIRE(Multiply(e, a).eval({}) == 2.71);
        REQUIRE(Multiply(e, x).eval({{"x", 2}}) == 5.42);
        REQUIRE(Multiply(x, y).eval({{"x", 2}, {"y", 3}}) == 6);
    }
    SECTION("Divide")
    {
        REQUIRE(Divide(e, a).eval({}) == 2.71);
        REQUIRE(Divide(e, x).eval({{"x", 2}}) == 1.355);
        REQUIRE(Divide(x, y).eval({{"x", 2}, {"y", 3}}) == 0.6666666666666666);
    }
}

TEST_CASE("Testing unary operations")
{
    Const e = Const(Complex(2.71, 10));
    Const a = Const(1);
    Variable x = Variable("x");
    Variable y = Variable("y");
    SECTION("Negate")
    {
        REQUIRE(Negate(e).eval({}) == Complex(-2.71, -10));
        REQUIRE(Negate(x).eval({{"x", 2}}) == -2);
        REQUIRE(Negate(y).eval({{"x", 2}, {"y", 3}}) == -3);
    }
    SECTION("Conjugate")
    {
        REQUIRE(Conjugate(e).eval({}) == Complex(2.71, -10));
        REQUIRE(Conjugate(x).eval({{"x", 2}}) == 2);
        REQUIRE(Conjugate(y).eval({{"x", 2}, {"y", 3}}) == 3);
    }
}

TEST_CASE("Testing operators")
{
    Const e = Const(2.71);
    Const a = Const(1);
    Variable x = Variable("x");
    Variable y = Variable("y");
    SECTION("+ - * /")
    {
        REQUIRE((a + e).eval({}) == Complex(3.71, 0));
        REQUIRE((a - e).eval({}) == Complex(-1.71, 0));
        REQUIRE((a * e).eval({}) == Complex(2.71, 0));
        REQUIRE((a / e).eval({}) == Complex(0.369004, 0));
        REQUIRE((x + y).eval({{"x", Complex(2.71, 10)}, {"y", Complex(3.1, -1)}}) == Complex(5.81, 9));
        REQUIRE((x - y).eval({{"x", Complex(2.71, 10)}, {"y", Complex(3.1, -1)}}) == Complex(-0.39, 11));
        REQUIRE((x * y).eval({{"x", Complex(2.71, 10)}, {"y", Complex(3.1, -1)}}) == Complex(18.401, 28.29));
        REQUIRE((x / y).eval({{"x", Complex(2.71, 10)}, {"y", Complex(1)}}) == Complex(2.71, 10));
    }
    SECTION("- ~")
    {
        REQUIRE((~a).eval({}) == Complex(1, 0));
        REQUIRE((~x).eval({{"x", Complex(1, 3)}}) == Complex(1, -3));
        REQUIRE((~y).eval({{"x", 2}, {"y", Complex(3, 5)}}) == Complex(3, -5));
        REQUIRE((-a).eval({}) == Complex(-1, 0));
        REQUIRE((-x).eval({{"x", Complex(1, 3)}}) == Complex(-1, -3));
    }
}

TEST_CASE("Testing random expressions")
{
    REQUIRE(Add(Subtract(Variable("x"), Const(Complex(10, -1))), Multiply(Variable("y"), Const(2))).eval({{"x", 2}}) == Complex(-8, 1));
    REQUIRE(Subtract(Add(Variable("x"), Const(Complex(10, -1))), Multiply(Const(2), Const(10))).eval({{"x", 2}}) == Complex(-8, -1));
    REQUIRE((Variable("x") + Const(Complex(10, -1))).eval({{"x", 2}}) == Complex(12, -1));
    REQUIRE((Variable("x") - Const(Complex(10, -1))).eval({{"x", 2}}) == Complex(-8, 1));
}

TEST_CASE("Testing << operator")
{
    std::stringstream ss;
    SECTION("Constant")
    {
        ss << Const(2.71);
        REQUIRE(ss.str() == "2.710000");
    }
    SECTION("Variable")
    {
        ss << Variable("x");
        REQUIRE(ss.str() == "x");
    }
    SECTION("Expression")
    {
        ss << Add(Subtract(Variable("x"), Const(Complex(10, -1))), Multiply(Variable("y"), Const(2)));
        REQUIRE(ss.str() == "((x - 10.000000 - 1.000000i) + (y * 2.000000))");
    }
}

TEST_CASE("Testing clone()")
{
    const Add temp = Add(Subtract(Variable("x"), Const(Complex(10, -1))), Multiply(Variable("y"), Const(2)));
    std::unique_ptr<Expression> clone = temp.clone();
    REQUIRE(temp.to_string() == clone->to_string());
}