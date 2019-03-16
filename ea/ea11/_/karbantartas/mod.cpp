//K�sz�tette:       Gregorics Tibor
//D�tum:            2009.01.29.
//Feladat:          K�nyvt�ri nyilv�ntart�s t�rzsadatait tartalmaz� m�dos�t�sok szekv. inputf�jl t�pusa

#include "mod.h"
#include <iostream>
#include <cstdlib>

using namespace std;

//Feladat: 	        F�jl nyit�sa
//Bemen� adatok:    ifstream f     - sz�veges �llom�ny neve
//Kimen� adatok:    ifstream f     - sz�veges �llom�ny
//Tev�kenys�g:	    Ha van megadott n�v, akkor azzal, ha nincs, akkor
//                  egy beolvasott n�vvel megnyitja a f�jlt
Mod::Mod(string fnev = "")
{
    if (fnev.size()<1)
    {
        cout << "Add meg a m�dos�t� f�jl nev�t:" ;
        cin >> fnev;
    }
    f.open(fnev.c_str());
    if (f.fail())
    {
        cout << "Nincs m�dos�t� f�jl" << endl;
        char ch; cin>>ch;
        exit(1);
    }
}

//Feladat: 	        K�vetkez� m�dos�t�s adatainak olvas�sa
//Bemen� adatok:    ifstream f  - sz�veges �llom�ny
//Kimen� adatok:    ifstream f  - sz�veges �llom�ny
//                  Valt dm     - k�nyvm�dos�t�s adatai
//                  Status sm   - olvas�s siker�t jelz� st�tusz
//Tev�kenys�g:	    Beolvassa a sz�veges f�jlb�l a k�vetkez� sort
//                  (ha nincs ilyen, akkor sm:=abnorm, k�l�nben sm:=norm).
//                  Kioll�zza a sorb�l a v�ltoz�s adatait �s felt�lti a dm-t.
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


