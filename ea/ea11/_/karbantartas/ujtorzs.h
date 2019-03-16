//Készítette:       Gregorics Tibor
//Dátum:            2009.01.29.
//Feladat:          Új könyvtári nyilvántartás törzsadatainak szekv. outputfájl típusa

#ifndef _UJTORZS_
#define _UJTORZS_

#include <fstream>
#include <string>
#include "kozos.h"

// Típusérték:      új törzsfájl
// Reprezentáció:   ofstream f - szöveges állomány
// Mûveletek:       Ujtorzs(const std::string &fnev ) - a fájl megnyitása
//                  ~Ujtorzs() - a fájl zárása
//                  void Write(const Konyv &du)- következõ könyv adatainak kiírása
class Ujtorzs
{
        std::ofstream f;
    public:
        Ujtorzs( std::string fnev );
        void Write(const Konyv &du);
        ~Ujtorzs(){ f.close();}
};

#endif
