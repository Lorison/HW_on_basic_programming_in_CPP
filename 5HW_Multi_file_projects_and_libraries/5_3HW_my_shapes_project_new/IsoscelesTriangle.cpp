#include "IsoscelesTriangle.h"

IsoscelesTriangle::IsoscelesTriangle(double a, double b, double A, double B)
    : Triangle(a, b, a, A, B, A)
{
    name = "Равнобедренный треугольник";
}