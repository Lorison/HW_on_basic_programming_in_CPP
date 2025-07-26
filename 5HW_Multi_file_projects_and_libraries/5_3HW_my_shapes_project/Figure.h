#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>

class Figure
{
protected:
    const char *name;

public:
    explicit Figure(const char *name);
    virtual ~Figure() = default;
    virtual void print() const = 0;
    const char *get_name() const;
};

#endif // FIGURE_H