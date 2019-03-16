//Készítette:       Gregorics Tibor
//Dátum:            2009.01.29.
//Feladat:          Könyvtári nyilvántartás törzsadatait tartalmazó módosítások szekv. inputfájl típusa

#include "mod.h"
#include <iostream>
#include <cstdlib>

using namespace std;

//Feladat: 	        Fájl nyitása
//Bemenõ adatok:    ifstream f     - szöveges állomány neve
//Kimenõ adatok:    ifstream f     - szöveges állomány
//Tevékenység:	    Ha van megadott név, akkor azzal, ha nincs, akkor
//                  egy beolvasott névvel megnyitja a fájlt
Mod::Mod(string fnev = "")
{
    if (fnev.size()<1)
    {
        cout << "Add meg a módosító fájl nevét:" ;
        cin >> fnev;
    }
    f.open(fnev.c_str());
    if (f.fail())
    {
        cout << "Nincs módosító fájl" << endl;
        char ch; cin>>ch;
        exit(1);
    }
}

//Feladat: 	        Következõ módosítás adatainak olvasása
//Bemenõ adatok:    ifstream f  - szöveges állomány
//Kimenõ adatok:    ifstream f  - szöveges állomány
//                  Valt dm     - könyvmódosítás adatai
//                  Status sm   - olvasás sikerét jelzõ státusz
//Tevékenység:	    Beolvassa a szöveges fájlból a következõ sort
//                  (ha nincs ilyen, akkor sm:=abnorm, különben sm:=norm).
//                  Kiollózza a sorból a változás adatait és feltölti a dm-t.
void Mod::Read(Valt &dm, Status &sm)
{
    string sor;
    getline(f,sor,'\n');
    if (!f.eof( ))
    {
        sm = norm;
        dm.funk       = sor[0];
        dm.konyv.azon = atoi(sor.substr( 2, 4).c_str());
        if(dm.funk =='K')
                dm.konyv.db = atoi(sor.substr(7, 3).c_str());
        if(dm.funk=='B')
        {
            dm.konyv.szerzo  =      sor.substr( 7,14);
            dm.konyv.cim     =      sor.substr(22,19);
            dm.konyv.kiado   =      sor.substr(42,14);
            dm.konyv.ev      =      sor.substr(57, 4);
            dm.konyv.db      = atoi(sor.substr(62, 3).c_str());
            dm.konyv.isbn    =      sor.substr(66,14);
        }
    }
    else sm = abnorm;
}


