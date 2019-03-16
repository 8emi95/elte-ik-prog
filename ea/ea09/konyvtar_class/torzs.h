//Készítette:       Gregorics Tibor
//Dátum:            2009.01.24.
//Feladat:          Könyvtári nyilvántartás típusa: törzs fájl

#ifndef _TORZS_
#define _TORZS_

#include "kozos.h"
#include <fstream>
#include <string>

enum Status {abnorm,norm};

//Típusérték:       Könyvtári nyilvántartás törzsfájlja
//Reprezentáció:    ifstream f  - könyvek adatait tartalmazó szöveges állomány
//Mûveletek:        Torzs() - szöveges állomány megnyitása
//                  Read()  - Következõ könyv olvasása
//                  ~Torzs()- szöveges állomány bezárása
class Torzs{
public:
    Torzs(std::string fname = "");
    void Read(Konyv &df, Status &sf);
private:
    std::ifstream f;
};

#endif


