//K�sz�tette:       Gregorics Tibor
//D�tum:            2009.01.24.
//Feladat:          Kiv�logatott k�nyvek t�pusa: eredm�ny f�jl

#ifndef _EREDM_
#define _EREDM_

#include "kozos.h"
#include <fstream>
#include <string>

//T�pus�rt�k:       Kiv�logatott k�nyvek eredm�nyf�jlja
//Reprezent�ci�:    ofstream f  - k�nyvek adatait tartalmaz� sz�veges �llom�ny
//M�veletek:        Eredm() - sz�veges �llom�ny l�trehoz�sa
//                  Write() - K�nyv �r�sa
//                  ~Eredm()- sz�veges �llom�ny bez�r�sa
class Eredm{
public:
    Eredm(std::string fname = "");
    void Write(const Konyv &df);
private:
    std::ofstream f;
};

#endif

