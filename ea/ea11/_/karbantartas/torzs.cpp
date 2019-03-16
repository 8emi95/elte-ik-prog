//K�sz�tette:       Gregorics Tibor
//D�tum:            2009.01.29.
//Feladat:          K�nyvt�ri nyilv�ntart�s t�rzsadatainak szekvenci�lis inputf�jl t�pusa

#include "torzs.h"
#include <iostream>
#include <cstdlib>

using namespace std;

//Feladat: 	        F�jl nyit�sa
//Bemen� adatok:    strinf fnev    - sz�veges �llom�ny neve
//Kimen� adatok:    ifstream f     - sz�veges �llom�ny
//Tev�kenys�g:	    Ha van megadott n�v, akkor azzal, ha nincs,
//                  akkor egy beolvasott n�vvel megnyitja a f�jlt
Torzs::Torzs(string fnev = "")
{
    if (fnev.size()<1)
    {
        cout << "Add meg a t�rzs f�jl nev�t:" ;
        cin >> fnev;
    }
    f.open(fnev.c_str());
    if (f.fail())
    {
        cout << "Nincs t�rzs f�jl" << endl;
        char ch; cin>>ch;
        exit(1);
    }
}

//Feladat: 	        K�vetkez� k�nyv adatainak olvas�sa
//Bemen� adatok:    ifstream f  - sz�veges �llom�ny
//Kimen� adatok:    ifstream f  - sz�veges �llom�ny
//                  Konyv dt    - k�nyv adatai
//                  Status st   - olvas�s siker�t jelz� st�tusz
//Tev�kenys�g:	    Beolvassa a sz�veges f�jlb�l a k�vetkez� sort
//                  (ha nincs ilyen, akkor st:=abnorm, k�l�nben st:=norm).
//                  Kioll�zza a sorb�l a k�nyv adatait �s felt�lti a dt-t.
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

