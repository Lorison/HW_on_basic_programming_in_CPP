#include "Figure.h"

Figure::Figure(const char *name) : name(name) {}

const char *Figure::get_name() const
{
    return name;
}