//
// Created by Jackson Brajer on 2019-10-17.
//

#ifndef BOIDS_UTIL_H
#define BOIDS_UTIL_H

#include "cmath"

namespace MUtil {
    template<typename T>
    int signum(T val) {
        return (T(0) < val) - (val < T(0));
    }

    double angleBetween(double a, double b) {
        a *= M_PI/180.0;
        b *= M_PI/180.0;

        double x1 = std::cos(a);
        double y1 = std::sin(a);
        double x2 = std::cos(b);
        double y2 = std::sin(b);

        double dot = x1*x2 + y1+y2;

//        return std::acos(dot) * 180.0/M_PI;
        double angle = (atan2(y1,x1) - atan2(y2,x2) * 180/M_PI);
        while(angle >= 360) angle -= 360;
        while(angle < 0) angle += 360;
        return angle;
    }
}

#endif //BOIDS_UTIL_H
