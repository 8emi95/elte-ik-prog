//K�sz�tette:       Gregorics Tibor
//D�tum:            2009.01.24.
//Feladat:          K�nyvt�ri nyilv�ntart�s t�pusa: t�rzs f�jl

#ifndef _TORZS_
#define _TORZS_

#include "kozos.h"
#include <fstream>
#include <string>

enum Status {abnorm,norm};

//T�pus�rt�k:       K�nyvt�ri nyilv�ntart�s t�rzsf�jlja
//Reprezent�ci�:    ifstream f  - k�nyvek adatait tartalmaz� sz�veges �llom�ny
//M�veletek:        Torzs() - sz�veges �llom�ny megnyit�sa
//                  Read()  - K�vetkez� k�nyv olvas�sa
//                  ~Torzs()- sz�veges �llom�ny bez�r�sa
class Torzs{
public:
    Torzs(std::string fname = "");
    void Read(Konyv &df, Status &sf);
private:
    std::ifstream f;
};

#endif


