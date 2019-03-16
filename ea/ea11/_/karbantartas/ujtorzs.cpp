//Készítette:       Gregorics Tibor
//Dátum:            2009.01.29.
//Feladat:          Új könyvtári nyilvántartás törzsadatainak szekv. outputfájl típusa

#include "ujtorzs.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

//Feladat: 	        Fájl nyitása
//Bemenõ adatok:    ofstream f     - szöveges állomány neve
//Kimenõ adatok:    ofstream f     - szöveges állomány
//Tevékenység:	    Ha van megadott név, akkor azzal, ha nincs, akkor
//                  egy beolvasott névvel megnyitja a fájlt
Ujtorzs::Ujtorzs(string fnev = "")
{
     if (fnev.size()<1)
    {
        cout << "Add meg az új törzsfájl nevét:";
        cin >> fnev;
    }
    f.open(fnev.c_str());
    if (f.fail())
    {
        cout << "Nem lehet létrehozni az új törzsfájlt" << endl;
        char ch; cin>>ch;
        exit(1);
    }
}

//Feladat: 	        Egy könyv adatainak kiírása
//Bemenõ adatok:    ofstream f  - szöveges állomány
//                  Konyv dt    - könyv adatai
//Kimenõ adatok:    ofstream f  - szöveges állomány
//Tevékenység:	    Kiírja a könyv adatait megfelelõ térközökkel a következõ sorba
void Ujtorzs::Write(const Konyv &du)
{
    f<<setw(4) <<du.azon  <<' '<<
       setw(15)<<du.szerzo<<' '<<
       setw(20)<<du.cim   <<' '<<
       setw(15)<<du.kiado <<' '<<
       setw(4)<<du.ev     <<' '<<
       setw(3)<<du.db     <<
       setw(15)<<du.isbn<<endl;
}

