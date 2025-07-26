#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Figure.h"

class Triangle : public Figure
{
protected:
    double a, b, c;
    double A, B, C;

public:
    Triangle(double a, double b, double c, double A, double B, double C);
    void print() const override;
};

#endif // TRIANGLE_H