//Készítette:    Gregorics Tibor
//Dátum:         2009.01.24.
//Feladat:       Könyv adatai

#ifndef _KOZOS_
#define _KOZOS_

#include <string>

struct Konyv {
    int azon;
    std::string szerzo;
    std::string cim;
    std::string kiado;
    std::string ev;
    int pld;
    std::string isbn;
};

#endif
