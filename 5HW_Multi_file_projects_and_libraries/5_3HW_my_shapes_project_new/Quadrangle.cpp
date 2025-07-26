#include "Quadrangle.h"

Quadrangle::Quadrangle(double a, double b, double c, double d, double A, double B, double C, double D)
    : Figure("Четырёхугольник"), a(a), b(b), c(c), d(d), A(A), B(B), C(C), D(D) {}

void Quadrangle::print() const
{
    std::cout << get_name() << ":\n";
    std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << "\n";
    std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << " D=" << D << "\n\n";
}