//K�sz�tette:       Gregorics Tibor
//D�tum:            2009.01.24.
//Feladat:          K�nyvt�ri nyilv�ntart�sb�l kiv�logatjuk a nulla p�ld�nysz�m� k�nyveket

#include <fstream>
#include <string>
#include "torzs.h"
#include "eredm.h"
#include "kozos.h"

//Feladat: 	        Sz�veges �llom�nyban elhelyezett k�nyvt�ri nyilv�ntart�sb�l kiv�logatjuk
//                  a nulla p�ld�nysz�m� k�nyveket �s egy m�sik sz�veges �llom�nyba �rjuk azokat
//Bemen� adatok:    Torzs x  - k�nyvek adatait tartalmaz� szekvenci�lis inputf�jl
//Kimen� adatok:    Eredm y  - nulla p�ld�nysz�m� k�nyvek adatait tartalmaz� szekvenci�lis outputf�jl
//Tev�kenys�g:	    A f�jlok sikeres nyit�sa illetve l�trehoz�sa ut�n egyenk�nt olvassa a k�nyveket
//                  az input f�jlb�l, �s ha az nulla p�ld�ny sz�m�, akkor az output f�jlba �rja
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




