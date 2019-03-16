//Készítette:    Gregorics Tibor
//Dátum:         2009.01.24.
//Feladat:       Könyv és változtatásának adatai

#ifndef _KOZOS_
#define _KOZOS_

#include <string>

enum Status{abnorm, norm};

struct Konyv{
    int         azon;
    std::string szerzo;
    std::string cim;
    std::string kiado;
    std::string ev;
    int         db;
    std::string isbn;
};

struct Valt{
    char   funk;
    Konyv  konyv;
};

#endif
