#ifndef CIRCLE_H_
#define CIRCLE_H_
#include <iostream>

class Circle {
private:
    double cx, cy, radius;
    
public:
    // constructor for customize circle, default point(0.0, 0.0), default radius 1.0
    Circle(double _cx = 0.0, double _cy = 0.0, double _radius = 1.0):
    cx(_cx), cy(_cy), radius(_radius) {}

    // constructor for unix circle, default point(0.0, 0.0)
    Circle(int _cx, int _cy):
    cx(static_cast<double>(_cx)), cy(static_cast<double>(_cy)), radius(1.0) {}

    double radius_of() const;
    void set_center(double new_cx, double new_cy);
    bool is_inside(double x, double y) const;

    double get_cx() const;
    double get_cy() const;
    friend std::ostream &operator << (std::ostream &os, const Circle &circle);
};
#endif
