#ifndef ENOR_H
#define ENOR_H
#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib>

// Típusérték:      hallgató-átlag párok sorozata
// Reprezentáció:   inputfájl (f),
//                  hallgató-jegy pár (df),
//                  aktuális hallgató-átlag pár (cur)
//                  "nincs több hallgató" flag (fin)
// Mûveletek:       Enor() - a bemenő adatokat tartalmazó állomány megnyitása szekvenciális inputfájlként
//                  first(), next(), end(), current()  - felsoroló mûveletek
class Enor
{
    public:
        struct Hallg{
            std::string azon;
            int jegy;
        };

        Enor(const std::string &str) ;
        void first() { x >> dx.azon >> dx.jegy; next();}
        void next();
        bool end() const { return vege;}
        Hallg current() const { return h;}
    private:
        std::ifstream x;
        Hallg dx;

        Hallg h;
        bool vege;
};

#endif // ENOR_H
