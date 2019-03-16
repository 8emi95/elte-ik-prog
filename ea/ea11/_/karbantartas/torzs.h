//Készítette:       Gregorics Tibor
//Dátum:            2009.01.29.
//Feladat:          Könyvtári nyilvántartás törzsadatainak szekvenciális inputfájl típusa

#ifndef _TORZS_
#define _TORZS_

#include <fstream>
#include <string>
#include "kozos.h"

// Típusérték:      törzsfájl
// Reprezentáció:   ifstream f - szöveges állomány, könyvadatok könyvazonosító szerint szig. növekvõek
// Mûveletek:       Torzs(const std::string &fnev ) - a fájl megnyitása
//                  ~Torzs() - a fájl zárása
//                  void Read(Konyv &dt, Status &st)- következõ könyv adatainak olvasása
class Torzs
{
        std::ifstream f;
    public:
        Torzs( std::string fnev );
        void Read(Konyv &dt, Status &st);
        ~Torzs() {f.close();}
};

#endif
