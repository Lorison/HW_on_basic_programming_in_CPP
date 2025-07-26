#ifndef SQUARE_H
#define SQUARE_H

#include "RectangleShape.h"

class Square : public RectangleShape
{
public:
    explicit Square(double side);
};

#endif // SQUARE_H