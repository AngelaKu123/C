#include "Circle2.h"
#include <cmath>

bool Circle2::is_inside(double Point_x, double Point_y) const {
    // compute radius with Pythagoras' theorem
    double radius = (std::sqrt(static_cast<double>((y1 - y0) * (y1 - y0) + (x1 - x0) * (x1 - x0)))) / 2;
    // compute center
    double cx = x0 + (x1 - x0) / 2;
    double cy = y0 + (y1 - y0) / 2;
    return ((Point_x - cx) * (Point_x - cx) + (Point_y - cy) * (Point_y - cy)) <= (radius * radius);
}
