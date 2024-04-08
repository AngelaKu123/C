#ifndef LINE2_H_
#define LINE2_H_
#include <iostream>

class Line2 {
private:
    double x0, y0, dx, dy;

public:
    Line2(double _x0 = 1.0, double _y0 = 1.0, double _dx = 1.0, double _dy = 1.0):
    x0(_x0), y0(_y0), dx(_dx), dy(_dy) {}

    double get_x0() const;
    double get_y0() const;
    double get_dx() const;
    double get_dy() const;
    
    void dx_new_value(double value);
    void dy_new_value(double value);
    void x0_new_value(double value);
    void y0_new_value(double value);

    friend std::ostream &operator << (std::ostream &os, const Line2 &l2);

    friend std::istream &operator >> (std::istream &is, Line2 &l2);

    bool normal(Line2 &l2);
    // friend std::ostream &operator << (std::ostream &os, const Line2 obj);
};
#endif
