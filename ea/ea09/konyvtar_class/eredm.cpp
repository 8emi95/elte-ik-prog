//Készítette:       Gregorics Tibor
//Dátum:            2009.01.24.
//Feladat:          Kiválogatott könyvek típusa

#include "eredm.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

//Feladat: 	        Eredmány fájl megnyitása
//Bemenõ adatok:    string fname - szöveges állomány neve
//Kimenõ adatok:    ofstream f   - létrehozott szekvenciális outfájl
//Tevékenység:	    Kiválogatás eredményét tartalmazó szöveges állomány létrehozása outputfájlként
Eredm::Eredm(string fname)
{
    if ( fname.size()<1 ) {
        cout << "Add meg a törzsfájl nevét:" ;
        cin >> fname;
    }
    f.open(fname.c_str());
    if ( f.fail() ){
        cerr << "Nincs törzs fájl" <<endl;
        char ch; cin>>ch;
        exit(2);
    }
}

//Feladat:          Könyv adatainak kiírása a szekvenciális outputfájlba
//Bemenõ adatok:    Konyv df    - könyv
//                  ofstream f  - könyvek adatait tartalmazó szekvenciális outputfájl
//Kimenõ adatok:    ofstream f  - könyvek adatait tartalmazó szekvenciális outputfájl
//Tevékenység:	    Kiírja a könyv adatait a szekvenciális outputfájlba
void Eredm::Write(const Konyv &df)
{
    f << setw(4)  << df.azon   << ' '
      << setw(14) << df.szerzo << ' '
      << setw(19) << df.cim    << endl;
}

