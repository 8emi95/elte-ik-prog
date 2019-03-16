//K�sz�tette:       Gregorics Tibor
//D�tum:            2009.01.24.
//Feladat:          Kiv�logatott k�nyvek t�pusa

#include "eredm.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

//Feladat: 	        Eredm�ny f�jl megnyit�sa
//Bemen� adatok:    string fname - sz�veges �llom�ny neve
//Kimen� adatok:    ofstream f   - l�trehozott szekvenci�lis outf�jl
//Tev�kenys�g:	    Kiv�logat�s eredm�ny�t tartalmaz� sz�veges �llom�ny l�trehoz�sa outputf�jlk�nt
Eredm::Eredm(string fname)
{
    if ( fname.size()<1 ) {
        cout << "Add meg a t�rzsf�jl nev�t:" ;
        cin >> fname;
    }
    f.open(fname.c_str());
    if ( f.fail() ){
        cerr << "Nincs t�rzs f�jl" <<endl;
        char ch; cin>>ch;
        exit(2);
    }
}

//Feladat:          K�nyv adatainak ki�r�sa a szekvenci�lis outputf�jlba
//Bemen� adatok:    Konyv df    - k�nyv
//                  ofstream f  - k�nyvek adatait tartalmaz� szekvenci�lis outputf�jl
//Kimen� adatok:    ofstream f  - k�nyvek adatait tartalmaz� szekvenci�lis outputf�jl
//Tev�kenys�g:	    Ki�rja a k�nyv adatait a szekvenci�lis outputf�jlba
void Eredm::Write(const Konyv &df)
{
    f << setw(4)  << df.azon   << ' '
      << setw(14) << df.szerzo << ' '
      << setw(19) << df.cim    << endl;
}

