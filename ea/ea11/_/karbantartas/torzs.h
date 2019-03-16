//K�sz�tette:       Gregorics Tibor
//D�tum:            2009.01.29.
//Feladat:          K�nyvt�ri nyilv�ntart�s t�rzsadatainak szekvenci�lis inputf�jl t�pusa

#ifndef _TORZS_
#define _TORZS_

#include <fstream>
#include <string>
#include "kozos.h"

// T�pus�rt�k:      t�rzsf�jl
// Reprezent�ci�:   ifstream f - sz�veges �llom�ny, k�nyvadatok k�nyvazonos�t� szerint szig. n�vekv�ek
// M�veletek:       Torzs(const std::string &fnev ) - a f�jl megnyit�sa
//                  ~Torzs() - a f�jl z�r�sa
//                  void Read(Konyv &dt, Status &st)- k�vetkez� k�nyv adatainak olvas�sa
class Torzs
{
        std::ifstream f;
    public:
        Torzs( std::string fnev );
        void Read(Konyv &dt, Status &st);
        ~Torzs() {f.close();}
};

#endif
