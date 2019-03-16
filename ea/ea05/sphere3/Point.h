#ifndef POINT_H
#define POINT_H

#include "Sphere.h"

class Point : public Sphere{
    public:
        Point():Sphere(0.0,0.0,0.0,0.0){}
        // Point(){set(0.0,0.0,0.0);}
        Point(double x, double y, double z):Sphere(x,y,z,0.0){}
        // Point(){set(x,y,z);}
        void set(double x, double y, double z){_x = x; _y = y; _z = z;}
//        void set(double x, double y, double z, double r){Sphere::set(x,y,z,0.0);}
};

#endif // POINT_H
