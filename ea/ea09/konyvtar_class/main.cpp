//Készítette:       Gregorics Tibor
//Dátum:            2009.01.24.
//Feladat:          Könyvtári nyilvántartásból kiválogatjuk a nulla példányszámú könyveket

#include <fstream>
#include <string>
#include "torzs.h"
#include "eredm.h"
#include "kozos.h"

//Feladat: 	        Szöveges állományban elhelyezett könyvtári nyilvántartásból kiválogatjuk
//                  a nulla példányszámú könyveket és egy másik szöveges állományba írjuk azokat
//Bemenõ adatok:    Torzs x  - könyvek adatait tartalmazó szekvenciális inputfájl
//Kimenõ adatok:    Eredm y  - nulla példányszámú könyvek adatait tartalmazó szekvenciális outputfájl
//Tevékenység:	    A fájlok sikeres nyitása illetve létrehozása után egyenként olvassa a könyveket
//                  az input fájlból, és ha az nulla példány számú, akkor az output fájlba írja
int main()
{
  Torzs x("inp.txt");
  Eredm y("out.txt");

  Konyv dx;
  Status sx;
  for(x.Read(dx,sx); norm==sx; x.Read(dx,sx)) {
    if (0==dx.pld) y.Write(dx);
  }

  return 0;
}




