#include "Rhombus.h"

Rhombus::Rhombus(double side, double A, double B)
    : Parallelogram(side, side, A, B)
{
    name = "Ромб";
}