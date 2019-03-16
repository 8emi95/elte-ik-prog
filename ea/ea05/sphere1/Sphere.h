#ifndef SPHERE_H
#define SPHERE_H
#include "Point.h"

class Sphere
{
    public:
        enum Errors { NEGATIVE_RADIUS };
        Sphere(double x, double y, double z, double r):_centre(x,y,z){
            if( r<0) throw NEGATIVE_RADIUS;
            _radius = r;
        }
        // Sphere(double x, double y, double z, double r){_x = x; _y = y; _z = z; _radius = r}

        bool contains(const Point &p)const {
            return _centre.distance(p) <= _radius;
        }



    private:
        Point _centre;
        double _radius;
};

#endif // SPHERE_H
