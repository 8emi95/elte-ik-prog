//K�sz�tette:       Gregorics Tibor
//D�tum:            2009.01.24.
//Feladat:          K�nyvt�ri nyilv�ntart�sb�l kiv�logatjuk a nulla p�ld�nysz�m� k�nyveket

#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>

using namespace std;

struct Konyv{
    int azon;
    string szerzo;
    string cim;
    string kiado;
    string ev;
    int pld;
    string isbn;
};

enum Status{abnorm, norm};

void Read(ifstream &x, Konyv &dx, Status &sx);
void Write(ofstream &x, const Konyv &dx);

//Feladat: 	        Sz�veges �llom�nyban elhelyezett k�nyvt�ri nyilv�ntart�sb�l kiv�logatjuk
//                  a nulla p�ld�nysz�m� k�nyveket �s egy m�sik sz�veges �llom�nyba �rjuk azokat
//Bemen� adatok:    ifstream x  - k�nyvek adatait tartalmaz� szekvenci�lis inputf�jl
//Kimen� adatok:    ofstream y  - nulla p�ld�nysz�m� k�nyvek adatait tartalmaz� szekvenci�lis outputf�jl
//Tev�kenys�g:	    A f�jlok sikeres nyit�sa illetve l�trehoz�sa ut�n egyenk�nt olvassa a k�nyveket
//                  az input f�jlb�l, �s ha az nulla p�ld�ny sz�m�, akkor az output f�jlba �rja
int main()
{
    ifstream x("inp.txt");
    if (x.fail() ) {
        cerr << "Nincs input file!\n";
        char ch; cin>>ch;
        exit(1);
    }

    ofstream y("out.txt");
    if (y.fail() ) {
        cerr << "Nem lehet l�trehozni az output f�jlt!\n";
        char ch; cin>>ch;
        exit(1);
    }

    Konyv dx;
    Status sx;
    for(Read(x,dx,sx); norm==sx; Read(x,dx,sx)) {
        if (0==dx.pld) {
            Write(y,dx);
        }
    }

    return 0;
}

//Feladat: 	        A k�vetkez� k�nyv olvas�sa a szekvenci�lis inputf�jlb�l
//Bemen� adatok:    ifstream x  - k�nyvek adatait tartalmaz� szekvenci�lis inputf�jl
//Kimen� adatok:    ifstream x  - k�nyvek adatait tartalmaz� szekvenci�lis inputf�jl
//                  Konyv dx    - a k�vetkez� k�nyv
//                  Status sx   - az olvas�s st�tusza
//Tev�kenys�g:	    Olvas egy �j sort az inputf�jlb�l. Ha ez siker�l (a f�jl nem �res), akkor a beolvasott
//                  sorb�l kioll�zza a k�vetkez� k�nyv adatait �s a st�tuszt norm-ra �ll�tja,
//                  k�l�nben a st�tusz abnorm lesz.
void Read(ifstream &x, Konyv &dx, Status &sx)
{
    string sor;

    getline(x,sor);
    if (!x.fail()) { //Ha az utols� sor v�g�n is van sorv�gejel, akkor el�g lenne: !eof()
        sx = norm;
        dx.azon   =atoi(sor.substr( 0, 4).c_str());
        dx.szerzo =     sor.substr( 5,14);
        dx.cim    =     sor.substr(21,19);
        dx.kiado  =     sor.substr(42,14);
        dx.ev     =     sor.substr(58, 4);
        dx.pld    =atoi(sor.substr(63, 3).c_str());
        dx.isbn   =     sor.substr(67,14);
    }
    else sx=abnorm;
}
//Feladat:          K�nyv adatainak ki�r�sa a szekvenci�lis outputf�jlba
//Bemen� adatok:    ofstream y  - k�nyvek adatait tartalmaz� szekvenci�lis outputf�jl
//                     Konyv dx    - k�nyv
//Kimen� adatok:    ofstream y  - k�nyvek adatait tartalmaz� szekvenci�lis outputf�jl
//Tev�kenys�g:	    Ki�rja a k�nyv adatait a szekvenci�lis outputf�jlba
void Write(ofstream &y, const Konyv &dy)
{
    y << setw(4)  << dy.azon  << ' '
      << setw(14) << dy.szerzo << ' '
      << setw(19) << dy.cim    << endl;
}

