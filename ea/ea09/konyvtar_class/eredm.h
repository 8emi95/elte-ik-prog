//Készítette:       Gregorics Tibor
//Dátum:            2009.01.24.
//Feladat:          Kiválogatott könyvek típusa: eredmény fájl

#ifndef _EREDM_
#define _EREDM_

#include "kozos.h"
#include <fstream>
#include <string>

//Típusérték:       Kiválogatott könyvek eredményfájlja
//Reprezentáció:    ofstream f  - könyvek adatait tartalmazó szöveges állomány
//Mûveletek:        Eredm() - szöveges állomány létrehozása
//                  Write() - Könyv írása
//                  ~Eredm()- szöveges állomány bezárása
class Eredm{
public:
    Eredm(std::string fname = "");
    void Write(const Konyv &df);
private:
    std::ofstream f;
};

#endif

