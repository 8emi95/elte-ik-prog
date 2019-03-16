//K�sz�tette:           Gregorics Tibor
//D�tum:                2009.01.29.
//Feladat:              Hiba �zenetek szekv outputf�jl t�pusa

#ifndef HIBA_H
#define HIBA_H

#include <fstream>
#include <string>
#include "kozos.h"

// T�pus�rt�k:      hibaf�jl
// Reprezent�ci�:   ofstream f - sz�veges �llom�ny
// M�veletek:       Hiba(const std::string &fnev ) - a f�jl megnyit�sa
//                  ~Hiba() - a f�jl z�r�sa
//                  void Write(const int azon, const std::string &uzen)- hiba�zenet ki�r�sa
class Hiba
{
        std::ofstream f;
    public:
        Hiba( std::string fnev );
        void Write(const int azon, const std::string &uzen);
        ~Hiba(){f.close();}
};

#endif
