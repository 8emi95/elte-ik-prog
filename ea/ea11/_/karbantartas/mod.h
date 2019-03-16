//Készítette:       Gregorics Tibor
//Dátum:            2009.01.29.
//Feladat:          Könyvtári nyilvántartás törzsadatait tartalmazó módosítások szekv. inputfájl típusa

#ifndef _MOD_
#define _MOD_

#include <fstream>
#include <string>
#include "kozos.h"

// Típusérték:      módosító fájl
// Reprezentáció:   ifstream f - szöveges állomány, könyvadatok könyvazonosító szerint szig. növekvõek
// Mûveletek:       Mod(const std::string &fnev ) - a fájl megnyitása
//                  ~Mod() - a fájl zárása
//                  void ReadValt&dt, Status &st)- következõ módosítás adatainak olvasása
class Mod
{
        std::ifstream f;
    public:
        Mod( std::string fnev );
        void Read(Valt &dm, Status &sm);
        ~Mod(){f.close();}
};

#endif
