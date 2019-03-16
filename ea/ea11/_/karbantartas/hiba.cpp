//Készítette:      Gregorics Tibor
//Dátum:           2009.01.29.
//Feladat:         Hiba üzenetek szekv outputfájl típusa

#include "hiba.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

//Feladat: 	        Fájl nyitása
//Bemenõ adatok:    string fnev    - szöveges állomány neve
//Kimenõ adatok:    ofstream f     - szöveges állomány
//Tevékenység:	    Ha van megadott név, akkor azzal, ha nincs, akkor
//                  egy beolvasott névvel megnyitja a fájlt
Hiba::Hiba(string fnev = "")
{
     if (fnev.size()<1)
    {
        cout << "Add meg az hiba fájl nevét:";
        cin >> fnev;
    }
    f.open(fnev.c_str());
    if (f.fail())
    {
        cout << "Nem lehet létrehozni hiba fájlt" << endl;
        char ch; cin>>ch;
        exit(1);
    }
}

//Feladat: 	        Egy hibaüzenet kiírása
//Bemenõ adatok:    ofstream f  - szöveges állomány
//                  int azon    - könyv azonosító
//                  string uzen - hibaüzenet
//Kimenõ adatok:    ofstream f  - szöveges állomány
//Tevékenység:	    Kiírja a hibaüzenetet a következõ sorba
void Hiba::Write(const int azon, const string &uzen)
{
    f<<setw(4)<<azon<<' '<<uzen<<endl;
}


