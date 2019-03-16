//Készítette:       Gregorics Tibor
//Dátum:            2009.01.29.
//Feladat:          Könyvtári nyilvántartás törzsadatainak szekvenciális inputfájl típusa

#include "torzs.h"
#include <iostream>
#include <cstdlib>

using namespace std;

//Feladat: 	        Fájl nyitása
//Bemenõ adatok:    strinf fnev    - szöveges állomány neve
//Kimenõ adatok:    ifstream f     - szöveges állomány
//Tevékenység:	    Ha van megadott név, akkor azzal, ha nincs,
//                  akkor egy beolvasott névvel megnyitja a fájlt
Torzs::Torzs(string fnev = "")
{
    if (fnev.size()<1)
    {
        cout << "Add meg a törzs fájl nevét:" ;
        cin >> fnev;
    }
    f.open(fnev.c_str());
    if (f.fail())
    {
        cout << "Nincs törzs fájl" << endl;
        char ch; cin>>ch;
        exit(1);
    }
}

//Feladat: 	        Következõ könyv adatainak olvasása
//Bemenõ adatok:    ifstream f  - szöveges állomány
//Kimenõ adatok:    ifstream f  - szöveges állomány
//                  Konyv dt    - könyv adatai
//                  Status st   - olvasás sikerét jelzõ státusz
//Tevékenység:	    Beolvassa a szöveges fájlból a következõ sort
//                  (ha nincs ilyen, akkor st:=abnorm, különben st:=norm).
//                  Kiollózza a sorból a könyv adatait és feltölti a dt-t.
void Torzs::Read(Konyv &dt, Status &st)
{
    string sor;

    getline(f,sor,'\n');
    if (!f.eof()) {
        st=norm;
        dt.azon   =atoi(sor.substr( 0, 4).c_str());
        dt.szerzo =     sor.substr( 5,14);
        dt.cim    =     sor.substr(21,19);
        dt.kiado  =     sor.substr(42,14);
        dt.ev     =     sor.substr(58, 4);
        dt.db     =atoi(sor.substr(63, 3).c_str());
        dt.isbn   =     sor.substr(67,14);
    }
    else st = abnorm;
}

