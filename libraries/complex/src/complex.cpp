#include "complex.hpp"

const Complex kZero(0, 0);

Complex::Complex(double real, double imag) noexcept
    : real_(real)
    , imag_(imag)
{
}

double Complex::real() const noexcept { return real_; }

double Complex::imag() const noexcept { return imag_; }

double Complex::abs() const noexcept { return std::sqrt(norm()); }

std::string Complex::str() const noexcept
{
    if (real_ == 0) 
        return std::to_string(imag_) + "i";

    if (imag_ < 0) 
        return std::to_string(real_) + " - " + std::to_string(-1 * imag_) + "i";

    if (imag_ == 0) 
        return std::to_string(real_);

    return std::to_string(real_) + " + " + std::to_string(imag_) + "i";
}

Complex Complex::operator+(const Complex& c) const noexcept { return Complex(real_ + c.real_, imag_ + c.imag_); }

Complex Complex::operator-(const Complex& c) const noexcept { return Complex(real_ - c.real_, imag_ - c.imag_); }

Complex Complex::operator*(const Complex& c) const noexcept { return Complex(real_ * c.real_ - imag_ * c.imag_, real_ * c.imag_ + imag_ * c.real_); }

Complex Complex::operator/(const Complex& c) const
{
    if (c == kZero) 
        throw std::runtime_error("Division by zero!");
    
    return (*this * ~c) * Complex(1 / c.norm(), 0);
}

Complex& Complex::operator+=(const Complex& c) noexcept
{
    real_ += c.real_;
    imag_ += c.imag_;
    return *this;
}

Complex& Complex::operator-=(const Complex& c) noexcept
{
    real_ -= c.real_;
    imag_ -= c.imag_;
    return *this;
}

Complex& Complex::operator*=(const Complex& c) noexcept
{
    real_ = (*this * c).real_;
    imag_ = (*this * c).imag_;
    return *this;
}

Complex& Complex::operator/=(const Complex& c)
{
    real_ = (*this / c).real_;
    imag_ = (*this / c).imag_;
    return *this;
}

bool Complex::operator==(const Complex& c) const noexcept { return std::abs(real_ - c.real_) <= 1e-6 && std::abs(imag_ - c.imag_) <= 1e-6; }

bool Complex::operator!=(const Complex& c) const noexcept { return !(*this == c); }

Complex Complex::operator~() const noexcept { return Complex(real_, -imag_); }

Complex Complex::operator-() const noexcept { return Complex(-real_, -imag_); }

double Complex::norm() const noexcept { return real_ * real_ + imag_ * imag_; }

std::ostream &operator<<(std::ostream& stream, const Complex& c)
{
    stream << c.str();
    return stream;
}
