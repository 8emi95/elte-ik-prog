//Készítette:       Gregorics Tibor
//Dátum:            2009.01.24.
//Feladat:          Könyvtári nyilvántartásból kiválogatjuk a nulla példányszámú könyveket

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

//Feladat: 	        Szöveges állományban elhelyezett könyvtári nyilvántartásból kiválogatjuk
//                  a nulla példányszámú könyveket és egy másik szöveges állományba írjuk azokat
//Bemenõ adatok:    ifstream x  - könyvek adatait tartalmazó szekvenciális inputfájl
//Kimenõ adatok:    ofstream y  - nulla példányszámú könyvek adatait tartalmazó szekvenciális outputfájl
//Tevékenység:	    A fájlok sikeres nyitása illetve létrehozása után egyenként olvassa a könyveket
//                  az input fájlból, és ha az nulla példány számú, akkor az output fájlba írja
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
        cerr << "Nem lehet létrehozni az output fájlt!\n";
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

//Feladat: 	        A következõ könyv olvasása a szekvenciális inputfájlból
//Bemenõ adatok:    ifstream x  - könyvek adatait tartalmazó szekvenciális inputfájl
//Kimenõ adatok:    ifstream x  - könyvek adatait tartalmazó szekvenciális inputfájl
//                  Konyv dx    - a következõ könyv
//                  Status sx   - az olvasás státusza
//Tevékenység:	    Olvas egy új sort az inputfájlból. Ha ez sikerül (a fájl nem üres), akkor a beolvasott
//                  sorból kiollózza a következõ könyv adatait és a státuszt norm-ra állítja,
//                  különben a státusz abnorm lesz.
void Read(ifstream &x, Konyv &dx, Status &sx)
{
    string sor;

    getline(x,sor);
    if (!x.fail()) { //Ha az utolsó sor végén is van sorvégejel, akkor elég lenne: !eof()
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
//Feladat:          Könyv adatainak kiírása a szekvenciális outputfájlba
//Bemenõ adatok:    ofstream y  - könyvek adatait tartalmazó szekvenciális outputfájl
//                     Konyv dx    - könyv
//Kimenõ adatok:    ofstream y  - könyvek adatait tartalmazó szekvenciális outputfájl
//Tevékenység:	    Kiírja a könyv adatait a szekvenciális outputfájlba
void Write(ofstream &y, const Konyv &dy)
{
    y << setw(4)  << dy.azon  << ' '
      << setw(14) << dy.szerzo << ' '
      << setw(19) << dy.cim    << endl;
}

