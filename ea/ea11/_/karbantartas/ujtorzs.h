//K�sz�tette:       Gregorics Tibor
//D�tum:            2009.01.29.
//Feladat:          �j k�nyvt�ri nyilv�ntart�s t�rzsadatainak szekv. outputf�jl t�pusa

#ifndef _UJTORZS_
#define _UJTORZS_

#include <fstream>
#include <string>
#include "kozos.h"

// T�pus�rt�k:      �j t�rzsf�jl
// Reprezent�ci�:   ofstream f - sz�veges �llom�ny
// M�veletek:       Ujtorzs(const std::string &fnev ) - a f�jl megnyit�sa
//                  ~Ujtorzs() - a f�jl z�r�sa
//                  void Write(const Konyv &du)- k�vetkez� k�nyv adatainak ki�r�sa
class Ujtorzs
{
        std::ofstream f;
    public:
        Ujtorzs( std::string fnev );
        void Write(const Konyv &du);
        ~Ujtorzs(){ f.close();}
};

#endif
