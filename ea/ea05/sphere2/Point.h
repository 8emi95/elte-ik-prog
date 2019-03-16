#ifndef POINT_H
#define POINT_H
#include <cmath>

class Point
{
    public:
        Point():_x(0.0),_y(0.0),_z(0.0){}
        // Point(){Set(0.0,0.0,0.0);}
        Point(double x, double y, double z):_x(x),_y(y),_z(z){}
        // Point(){Set(x,y,z);}

        void set(double x, double y, double z){
            _x = x; _y = y; _z = z;
        }

        double distance(const Point &p) const {
            return sqrt(pow(_x-p._x, 2) + pow(_y-p._y,2) + pow(_z-p._z,2)) ;
        }

    private:
        double _x;
        double _y;
        double _z;;
};

#endif // POINT_H
