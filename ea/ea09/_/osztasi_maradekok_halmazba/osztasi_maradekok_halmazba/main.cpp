//Készítette:       Gregorics Tibor
//Dátum:            2009.01.24.
//Feladat:          Egész számok adott számmal vett osztási maradákainak halmazba írása

#include <fstream>
#include <iostream>
#include "halmaz.h"
#include "read.h"

using namespace std;

bool notnull(int n) { return n!=0;}

//Feladat: 	        Írjuk ki egy szöveges fájlban megadott egész számoknak egy adott egész számmal vett
//                  osztási maradékait egy halmazba
//Bemenõ adatok:    istream f    - egész számokat tartalmazó szöveges állomány
//                  int n        - adott osztó
//Kimenõ adatok:    ostream cout - az osztási maradékokat tartalmazó szabványos kimenet
//Tevékenység:	    Bekéri a fájlnevét és megnyitja azt. Beolvassa az osztót. Létrehoz egy üres halmazt.
//                  Bejárja a szöveges állománynak, mint szekvenciális inputfájlnak az elemeit,
//                  egyenként kiszámolja azok osztási maradékát és beteszi õket a halmazba.
//                  Végül kiírja a halmaz elemeit.
int main()
{
    ifstream f;

    bool hiba = true;
    do{
        string fname;
        cout << "Mi a fajl neve: ";
        cin >> fname;
        f.open(fname.c_str());
        if(hiba=f.fail()) {
            cout << "Hibas fajlnev!\n";
            f.clear();
        }
    }while(hiba);

    int k = ReadInt("Adja meg az osztot: ", "Nem nulla egesz szamot kerek!", notnull);
    Halmaz h;

    int e;
    for(f >> e; !f.fail(); f >> e){ //Ha a fájl helyes és az utolsó sor végén is van sorvégejel, akkor elég lenne: !eof()
        h.Be(e%k);
    }

    cout << "Az osztasi maradekok: " << h << endl;

    char ch; cin >> ch;
    return 0;
}
