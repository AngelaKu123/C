#ifndef CIRCLE2_H_
#define CIRCLE2_H_
#include <iostream>

class Circle2 {
private:
    double x0, y0, x1, y1;

public:
    // constructor to Circle2
    Circle2(double _x0 = 1.0, double _y0 = 1.0, double _x1 = 1.0, double _y1 = 1.0):
    x0(_x0), y0(_y0), x1(_x1), y1(_y1) {}

    bool is_inside(double Point_x, double Point_y) const;
};
#endif
