#include "Circle.h"
using namespace std;

double Circle::radius_of() const {
    return radius;
}

void Circle::set_center(double new_cx, double new_cy) {
    cx = new_cx;
    cy = new_cy;
}

bool Circle::is_inside(double x, double y) const {
    // circle formula: (x - cx)^2 + (y - cy)^2 = radius^2 
    return ((x - cx) * (x - cx) + (y - cy) * (y - cy)) <= (radius * radius);
}

double Circle::get_cx() const {
    return cx;
}
double Circle::get_cy() const {
    return cy;
}

ostream &operator << (ostream &os, const Circle &circle) {
    // center: (cx, cy), radius = radius
    os << "center: (" << circle.get_cx() << ", " << circle.get_cy()
     << "), radius = " << circle.radius_of() << endl;
    return os;
}
