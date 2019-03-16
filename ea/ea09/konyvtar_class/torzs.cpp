//K�sz�tette:       Gregorics Tibor
//D�tum:            2009.01.24.
//Feladat:          K�nyvt�ri nyilv�ntart�s t�pusa: t�rzs f�jl

#include "torzs.h"
#include <iostream>
#include <cstdlib>

using namespace std;

//Feladat: 	        T�rzs f�jl megnyit�sa
//Bemen� adatok:    string fname - sz�veges �llom�ny neve
//Kimen� adatok:    ifstream f   - megnyitott szekvenci�lis inputf�jl
//Tev�kenys�g:	    K�nyvt�ri nyilv�ntart�st tartalmaz� sz�veges �llom�ny megnyit�sa inputf�jlk�nt
Torzs::Torzs(string fname)
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

//Feladat: 	        Olvas�s  a t�rzsf�jlb�l
//Bemen� adatok:    ifstream f  - k�nyvek adatait tartalmaz� szekvenci�lis inputf�jl
//Kimen� adatok:    ifstream f  - k�nyvek adatait tartalmaz� szekvenci�lis inputf�jl
//                  Konyv df    - a k�vetkez� k�nyv
//                  Status sf   - az olvas�s st�tusza
//Tev�kenys�g:	    Olvas egy �j sort az inputf�jlb�l. Ha ez siker�l (a f�jl nem �res), akkor a beolvasott
//                  sorb�l kioll�zza a k�vetkez� k�nyv adatait �s a st�tuszt norm-ra �ll�tja,
//                  k�l�nben a st�tusz abnorm lesz.
void Torzs::Read(Konyv &df, Status &sf)
{
  string sor;

  getline(f, sor);
  if (!f.fail()) { //Ha az utols� sor v�g�n is van sorv�gejel, akkor el�g lenne: !eof()
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


