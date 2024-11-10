#include "complex.hpp"

#include <catch2/catch_test_macros.hpp>
#include <sstream>

TEST_CASE("Testing constructors and parts of complex numbers") {
    Complex a = Complex(0, 0);
    Complex b = Complex();
    Complex c = Complex(123.456);
    Complex d = Complex(1, -1);

    REQUIRE(a.imag() == 0);
    REQUIRE(a.real() == 0);
    REQUIRE(a == b);
    REQUIRE(c.real() == 123.456);
    REQUIRE(c.imag() == 0);
    REQUIRE(d.imag() == -1);
}

TEST_CASE("Testing unary functions of complex numbers") {
    Complex a = Complex(3, 4);
    Complex b = Complex(1, 0);

    SECTION("Testing abs") {
        REQUIRE(a.abs() == 5);
        REQUIRE(b.abs() == 1);
    }
    SECTION("Testing norm") {
        REQUIRE(a.norm() == 25);
        REQUIRE(b.norm() == 1);
    }
    SECTION("Testing str") {
        REQUIRE(a.str() == "3.000000 + 4.000000i");
        REQUIRE(b.str() == "1.000000");
    }
}

TEST_CASE("Testing binary operations") {
    Complex a = Complex(3, 4);
    Complex b = Complex(1, 0);
    Complex c = Complex(1, 2);

    SECTION("Testing +") {
        REQUIRE(a + b == Complex(4, 4));
        REQUIRE(b + c == Complex(2, 2));
        REQUIRE(a + c == Complex(4, 6));
    }
    SECTION("Testing -") {
        REQUIRE(a - b == Complex(2, 4));
        REQUIRE(c - b == Complex(0, 2));
        REQUIRE(a - c == Complex(2, 2));
    }
    SECTION("Testing *") {
        REQUIRE(a * b == Complex(3, 4));
        REQUIRE(a * c == Complex(-5, 10));
    }
    SECTION("Testing /") {
        REQUIRE(a / b == Complex(3, 4));
    }
}

TEST_CASE("Testing assignment operators") {
    Complex a = Complex(3, 4);
    Complex b = Complex(1, 0);
    Complex c = Complex(1, 2);
    Complex e = Complex(1, 1);
    Complex g = Complex(3, 3);

    SECTION("Testing +=") {
        a += b;
        b += c;
        REQUIRE(a == Complex(4, 4));
        REQUIRE(b == Complex(2, 2));
    }
    
    SECTION("Testing -=") {
        c -= c;
        e -= g;
        REQUIRE(c == Complex(0, 0));
        REQUIRE(e == Complex(-2, -2));
    }

    SECTION("Testing *=") {
        e *= g;
        a *= e;
        REQUIRE(e == Complex(0, 3));
        REQUIRE(a  == Complex(-12, -36));
    }
    SECTION("Testing /=") {
        a /= b;
        b /= c;
        REQUIRE(a == Complex(3, 4));
        REQUIRE(b == Complex(0.2, -0.08));
    }
}

TEST_CASE("Testing unary operators") {
    Complex a = Complex(1, 0);
    Complex b = Complex(-10, 123);
    SECTION("Testing ~") {
        REQUIRE(a == ~a);
        REQUIRE(~b == Complex(-10, -123));
    }
    SECTION("Testing -") {
        REQUIRE(-a == Complex(-1, 0));
        REQUIRE(-b == Complex(10, -123));
    }
}

TEST_CASE("Testing equality operator") {
    Complex a = Complex(1, 1);
    Complex b = Complex(2, 2);
    REQUIRE(a == b - a);
    REQUIRE(b == a * Complex(2, 0));
    REQUIRE(b != a);
    REQUIRE(a != b);
}

TEST_CASE("Testing << operator") {
    std::stringstream ss;
    SECTION("real") {
        ss << Complex(1, 0);
        REQUIRE(ss.str() == "1.000000");
    }
    SECTION("imaginary") {
        ss << Complex(0, 2);
        REQUIRE(ss.str() == "2.000000i");
    }
    SECTION("complex") {
        ss << Complex(1, -2);
        REQUIRE(ss.str() == "1.000000 - 2.000000i");
    }
}

