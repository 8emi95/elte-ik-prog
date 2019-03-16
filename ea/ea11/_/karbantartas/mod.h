//K�sz�tette:       Gregorics Tibor
//D�tum:            2009.01.29.
//Feladat:          K�nyvt�ri nyilv�ntart�s t�rzsadatait tartalmaz� m�dos�t�sok szekv. inputf�jl t�pusa

#ifndef _MOD_
#define _MOD_

#include <fstream>
#include <string>
#include "kozos.h"

// T�pus�rt�k:      m�dos�t� f�jl
// Reprezent�ci�:   ifstream f - sz�veges �llom�ny, k�nyvadatok k�nyvazonos�t� szerint szig. n�vekv�ek
// M�veletek:       Mod(const std::string &fnev ) - a f�jl megnyit�sa
//                  ~Mod() - a f�jl z�r�sa
//                  void ReadValt&dt, Status &st)- k�vetkez� m�dos�t�s adatainak olvas�sa
class Mod
{
        std::ifstream f;
    public:
        Mod( std::string fnev );
        void Read(Valt &dm, Status &sm);
        ~Mod(){f.close();}
};

#endif
