//Készítette:       Gregorics Tibor
//Dátum:            2009.01.24.
//Feladat:          Természetes számok adott természetes számmal vett osztási maradákainak halmazba írása

#include <fstream>
#include <iostream>
#include "halmaz.h"
#include "read.h"

using namespace std;

bool positive(int n) { return n>0;}

//Feladat: 	        Írjuk ki egy szöveges fájlban megadott természetes számoknak
//                  egy adott természetes számmal vett
//                  osztási maradékait egy halmazba
//Bemenõ adatok:    istream f    - természetes számokat tartalmazó szöveges állomány
//                  int n        - adott természetes osztó
//Kimenõ adatok:    ostream cout - az osztási maradékokat tartalmazó szabványos kimenet
//Tevékenység:	    Bekéri a fájlnevét és megnyitja azt. Beolvassa az osztót. Létrehoz egy üres halmazt.
//                  Bejárja a szöveges állománynak, mint szekvenciális inputfájlnak az elemeit,
//                  egyenként kiszámolja azok osztási maradékát és beteszi õket a halmazba.
//                  Végül kiírja a halmaz elemeit.
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

    int k = read_int("Adja meg az osztot: ", "Pozitiv egesz szamot kerek!", positive);

    Halmaz h(k);
    int e;
    for(x >> e; !x.fail(); x >> e){ //Ha a fájl helyes és az utolsó sor végén is van sorvégejel, akkor elég lenne: !eof()
        try{
            h.Be(e%k);
        }catch(Halmaz::Exception ex){
            cout << "Nem lehet a fajlban negativ szam!\n";
        }
    }
    cout << "Az osztasi maradekok: " << h << endl;

    return 0;
}
