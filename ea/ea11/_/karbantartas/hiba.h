//Készítette:           Gregorics Tibor
//Dátum:                2009.01.29.
//Feladat:              Hiba üzenetek szekv outputfájl típusa

#ifndef HIBA_H
#define HIBA_H

#include <fstream>
#include <string>
#include "kozos.h"

// Típusérték:      hibafájl
// Reprezentáció:   ofstream f - szöveges állomány
// Mûveletek:       Hiba(const std::string &fnev ) - a fájl megnyitása
//                  ~Hiba() - a fájl zárása
//                  void Write(const int azon, const std::string &uzen)- hibaüzenet kiírása
class Hiba
{
        std::ofstream f;
    public:
        Hiba( std::string fnev );
        void Write(const int azon, const std::string &uzen);
        ~Hiba(){f.close();}
};

#endif
