#ifndef LINE_H_
#define LINE_H_
#include <iostream>

class Line {
private:
    double x0, y0, x1, y1;

public:
    Line(double _x0 = 0.0, double _y0 = 0.0, double _x1 = 1.0, double _y1 = 1.0) :
    x0(_x0), y0(_y0), x1(_x1), y1(_y1) {}

    double get_x0() const;
    double get_y0() const;
    double get_x1() const;
    double get_y1() const;
    double slope() const;
    double y_intercept() const;
    void vshift(double amount);
    friend std::ostream & operator << (std::ostream &os, const Line &l);
    friend std::istream & operator >> (std::istream &is, Line &l);
};

#endif