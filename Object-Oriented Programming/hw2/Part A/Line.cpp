#include "Line.h"
#include <iostream>
using namespace std;

double Line::get_x0() const {
    return x0;
}

double Line::get_y0() const {
    return y0;
}

double Line::get_x1() const {
    return x1;
}

double Line::get_y1() const {
    return y1;
}

double Line::slope() const {
    if (x0 == x1) {
        cout << "Slope doesn't exist." << endl;
        return 0;
    }
    return (y1 - y0) / (x1 - x0);
}

double Line::y_intercept() const {
    if (x0 == 0 && x1 != 0)
        return y0;
    else if (x0 != 0 && x1 == 0)
        return y1;
    else if (x0 == x1) {
        cout << "There is no y-intercept." << endl;
        return 0;
    }
    else{
        return y0 - Line::slope() * x0; // slope-intercept form
    }
    
}

void Line::vshift(double amount) {
    y0 = y0 + amount;
    y1 = y1 + amount;
}

ostream & operator << (ostream &os, const Line &l) {
    os << "(" << l.get_x0() << ", " << l.get_y0() << ")";
    os << "(" << l.get_x1() << ", " << l.get_y1() << ")";
    return os;
}

istream & operator >> (istream &is, Line &l) {
    double a, b, c, d;
    is >> a >> b >> c >> d;
    l = Line(a, b, c, d);
    return is;
}
