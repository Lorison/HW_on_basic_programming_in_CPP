#include "Parallelogram.h"

Parallelogram::Parallelogram(double a, double b, double A, double B)
    : Quadrangle(a, b, a, b, A, B, A, B)
{
    name = "Параллелограмм";
}