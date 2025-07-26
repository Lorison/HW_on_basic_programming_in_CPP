#include "RectangleShape.h"

RectangleShape::RectangleShape(double a, double b)
    : Parallelogram(a, b, 90, 90)
{
    name = "Прямоугольник";
}