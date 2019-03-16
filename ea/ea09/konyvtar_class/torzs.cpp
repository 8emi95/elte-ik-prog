//Készítette:       Gregorics Tibor
//Dátum:            2009.01.24.
//Feladat:          Könyvtári nyilvántartás típusa: törzs fájl

#include "torzs.h"
#include <iostream>
#include <cstdlib>

using namespace std;

//Feladat: 	        Törzs fájl megnyitása
//Bemenõ adatok:    string fname - szöveges állomány neve
//Kimenõ adatok:    ifstream f   - megnyitott szekvenciális inputfájl
//Tevékenység:	    Könyvtári nyilvántartást tartalmazó szöveges állomány megnyitása inputfájlként
Torzs::Torzs(string fname)
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

//Feladat: 	        Olvasás  a törzsfájlból
//Bemenõ adatok:    ifstream f  - könyvek adatait tartalmazó szekvenciális inputfájl
//Kimenõ adatok:    ifstream f  - könyvek adatait tartalmazó szekvenciális inputfájl
//                  Konyv df    - a következõ könyv
//                  Status sf   - az olvasás státusza
//Tevékenység:	    Olvas egy új sort az inputfájlból. Ha ez sikerül (a fájl nem üres), akkor a beolvasott
//                  sorból kiollózza a következõ könyv adatait és a státuszt norm-ra állítja,
//                  különben a státusz abnorm lesz.
void Torzs::Read(Konyv &df, Status &sf)
{
  string sor;

  getline(f, sor);
  if (!f.fail()) { //Ha az utolsó sor végén is van sorvégejel, akkor elég lenne: !eof()
    sf = norm;
    df.azon   =atoi(sor.substr( 0, 4).c_str());
    df.szerzo =     sor.substr( 5,14);
    df.cim    =     sor.substr(21,19);
    df.kiado  =     sor.substr(42,14);
    df.ev     =     sor.substr(58, 4);
    df.pld    =atoi(sor.substr(63, 3).c_str());
    df.isbn   =     sor.substr(67,14);
  }
  else sf = abnorm;
}


