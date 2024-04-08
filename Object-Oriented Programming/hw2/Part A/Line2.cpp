#include "Line2.h"
#include <iostream>
#include <numeric>
using namespace std;

double Line2::get_x0() const {
    return x0;
}
double Line2::get_y0() const {
    return y0;
}
double Line2::get_dx() const {
    return dx;
}
double Line2::get_dy() const {
    return dy;
}

void Line2::dx_new_value(double value) {
    dx = value;
}
void Line2::dy_new_value(double value) {
    dy = value;
}
void Line2::x0_new_value(double value) {
    x0 = value;
}
void Line2::y0_new_value(double value) {
    y0 = value;
}

ostream &operator << (ostream &os, const Line2 &l3) {
    // 10^-6 < coefficient^2 < 10^6
    double a = l3.get_dx() * 1000000;
    double b = l3.get_dy() * 1000000;
    double c = a * l3.get_x0() + b * l3.get_y0();
    
    // compute greatest common factor
    int factor = gcd(abs((int)a), gcd(abs((int)b), abs((int)c)));
    a /= (double)factor; // simplify
    b /= (double)factor;
    c /= (double)factor;
    
    os << a << "x + " << b << "y = " << c << endl;
    return os;
}

istream &operator >> (std::istream &is, Line2 &l2) {
    double a, b, c;
    is >> a >> b >> c;
    // ax + by = c, x = 0
    l2.x0_new_value(0.0);
    l2.y0_new_value(-c / b);
    l2 = Line2(l2.x0, l2.y0, a, b);
    return is;
}

bool Line2::normal(Line2 &l2) {
    if (get_dx() == 0 && get_dy() == 0) // invalid line
        return false;
    
    l2.dx_new_value(-1 * (this->get_dy()));
    l2.dy_new_value(this->get_dx());
    
    return true;
}
