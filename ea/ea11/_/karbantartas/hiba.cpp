//K�sz�tette:      Gregorics Tibor
//D�tum:           2009.01.29.
//Feladat:         Hiba �zenetek szekv outputf�jl t�pusa

#include "hiba.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

//Feladat: 	        F�jl nyit�sa
//Bemen� adatok:    string fnev    - sz�veges �llom�ny neve
//Kimen� adatok:    ofstream f     - sz�veges �llom�ny
//Tev�kenys�g:	    Ha van megadott n�v, akkor azzal, ha nincs, akkor
//                  egy beolvasott n�vvel megnyitja a f�jlt
Hiba::Hiba(string fnev = "")
{
     if (fnev.size()<1)
    {
        cout << "Add meg az hiba f�jl nev�t:";
        cin >> fnev;
    }
    f.open(fnev.c_str());
    if (f.fail())
    {
        cout << "Nem lehet l�trehozni hiba f�jlt" << endl;
        char ch; cin>>ch;
        exit(1);
    }
}

//Feladat: 	        Egy hiba�zenet ki�r�sa
//Bemen� adatok:    ofstream f  - sz�veges �llom�ny
//                  int azon    - k�nyv azonos�t�
//                  string uzen - hiba�zenet
//Kimen� adatok:    ofstream f  - sz�veges �llom�ny
//Tev�kenys�g:	    Ki�rja a hiba�zenetet a k�vetkez� sorba
void Hiba::Write(const int azon, const string &uzen)
{
    f<<setw(4)<<azon<<' '<<uzen<<endl;
}


