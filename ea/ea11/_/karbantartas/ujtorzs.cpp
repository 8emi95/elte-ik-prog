//K�sz�tette:       Gregorics Tibor
//D�tum:            2009.01.29.
//Feladat:          �j k�nyvt�ri nyilv�ntart�s t�rzsadatainak szekv. outputf�jl t�pusa

#include "ujtorzs.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

//Feladat: 	        F�jl nyit�sa
//Bemen� adatok:    ofstream f     - sz�veges �llom�ny neve
//Kimen� adatok:    ofstream f     - sz�veges �llom�ny
//Tev�kenys�g:	    Ha van megadott n�v, akkor azzal, ha nincs, akkor
//                  egy beolvasott n�vvel megnyitja a f�jlt
Ujtorzs::Ujtorzs(string fnev = "")
{
     if (fnev.size()<1)
    {
        cout << "Add meg az �j t�rzsf�jl nev�t:";
        cin >> fnev;
    }
    f.open(fnev.c_str());
    if (f.fail())
    {
        cout << "Nem lehet l�trehozni az �j t�rzsf�jlt" << endl;
        char ch; cin>>ch;
        exit(1);
    }
}

//Feladat: 	        Egy k�nyv adatainak ki�r�sa
//Bemen� adatok:    ofstream f  - sz�veges �llom�ny
//                  Konyv dt    - k�nyv adatai
//Kimen� adatok:    ofstream f  - sz�veges �llom�ny
//Tev�kenys�g:	    Ki�rja a k�nyv adatait megfelel� t�rk�z�kkel a k�vetkez� sorba
void Ujtorzs::Write(const Konyv &du)
{
    f<<setw(4) <<du.azon  <<' '<<
       setw(15)<<du.szerzo<<' '<<
       setw(20)<<du.cim   <<' '<<
       setw(15)<<du.kiado <<' '<<
       setw(4)<<du.ev     <<' '<<
       setw(3)<<du.db     <<
       setw(15)<<du.isbn<<endl;
}

