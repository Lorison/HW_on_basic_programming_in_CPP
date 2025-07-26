#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Parallelogram.h"

class RectangleShape : public Parallelogram
{
public:
    explicit RectangleShape(double a, double b);
};

#endif // RECTANGLE_H