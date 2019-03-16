//Készítette:       Gregorics Tibor
//Dátum:            2009.01.24.
//Feladat:          Természetes számok adott természetes számmal vett osztási maradákainak kiírása

#include <fstream>
#include <iostream>
#include "read.hpp"

using namespace std;

bool not_null(int n) { return n!=0;}

//Feladat: 	        Írjuk ki egy szöveges fájlban megadott természetes számoknak
//                  egy adott természetes számmal vett
//                  osztási maradékait a szabványos kimenetre
//Bemenõ adatok:    istream f    - természetes számokat tartalmazó szöveges állomány
//                  int n        - adott természetes szám osztó
//Kimenõ adatok:    ostream cout - az osztási maradékokat tartalmazó szabványos kimenet
//Tevékenység:	    Bekéri a fájlnevét és megnyitja azt. Beolvassa az osztót. Bejárja a szöveges állománynak,
//                  mint szekvenciális inputfájlnak az elemeit, egyenként kiszámolja azok
//                  osztási maradékát és kiírja õket a szabványos kimenetre.
int main()
{
    ifstream x;
    bool hiba = true;
    do{
        string fname;
        cout << "Mi a fajl neve: ";
        cin >> fname;
        x.open(fname.c_str());
        if( (hiba=x.fail()) ) {
            cout << "Hibas fajlnev!\n";
            x.clear();
        }
    }while(hiba);

    int k = read<int>("Adja meg az osztot: ", "Pozitiv egesz szamot kerek!", not_null);

    cout << "A megadott szamok osztasi maradekai: ";
    int e;
    for(x >> e; !x.fail(); x >> e){ //Ha a fájl helyes és az utolsó sor végén is van sorvégejel, akkor elég lenne: !eof()
        cout << e%k << " ";
    }

    return 0;
}
