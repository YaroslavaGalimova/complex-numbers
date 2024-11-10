#include "bin_operation.hpp"
#include "un_operation.hpp"
#include "IExpression.hpp"

Complex Expression::eval(std::map<std::string, Complex> m) const noexcept { return 0; }

std::string Expression::to_string() const noexcept { return ""; }

std::unique_ptr<Expression> Expression::clone() const noexcept { return nullptr; }

BinOperation::BinOperation(const Expression &a, const Expression &b) noexcept
    : a_(a.clone()), b_(b.clone())
{
}

std::string BinOperation::to_string() const noexcept
{
    return "(" + a_->to_string() + " " + get_sign() + " " + b_->to_string() + ")";
}

BinOperation::~BinOperation() noexcept
{
}

Complex BinOperation::eval(std::map<std::string, Complex> m) const noexcept
{
    return count(a_->eval(m), b_->eval(m));
}

UnOperation::UnOperation(const Expression &a) noexcept
    : a_(a.clone())
{
}

Complex UnOperation::eval(std::map<std::string, Complex> m) const noexcept
{
    return count(a_->eval(m));
}

std::string UnOperation::to_string() const noexcept
{
    return get_sign() + a_->to_string();
}

UnOperation::~UnOperation() noexcept
{
}
