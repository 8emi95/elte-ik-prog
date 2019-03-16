#ifndef SPHERE_H
#define SPHERE_H
#include "Point.h"

class Sphere : protected Point
{
    public:
        enum Errors { NEGATIVE_RADIUS };
        Sphere(double x, double y, double z, double r) : Point(x,y,z){
            if( r<0) throw NEGATIVE_RADIUS;
            _radius = r;
        }

        /*
        Sphere(double x, double y, double z, double r){
          set(x,y,z);
          if( r<0) throw NEGATIVE_RADIUS;
            _radius = r;
        }*/

        bool contains(const Point &p) const {
            return distance(p) <= _radius;
        }
    private:
        double _radius;
};

#endif // SPHERE_H
