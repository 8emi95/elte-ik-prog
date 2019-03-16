//Készítette:    Gregorics Tibor
//Dátum:         2015.02.22.
//Feladat:       Felszíni horpadások száma pufferelt olvasással

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

//Feladat: 	        Adottak egy szöveges állományban a földfelszín tengerszint feletti magasságai.
//                  Hány horpadás található a felszínen?
//Bemenõ adatok:    ifstream f - szekvenciális inputfájl
//Kimenõ adatok:    int c      - horpadások száma
//Tevékenység:	    Számlálás a fájlbeli értékekbõl képzett hármasok felsorolására építve.
int main()
{
    ifstream f("input.txt"); // A fálj-nyitás ellenőrzése hiányzik
    if(f.fail()){
        cout << "Nem lehet olvasásra megnyitni a fájlt\n";
        exit(1);
    }
    int prev, curr, next;
    int c = 0;
    for( f >> prev >> curr >> next; !f.fail(); prev = curr, curr = next, f >> next){
        if( prev > curr && curr < next ) ++c;
    }

    cout << "Felszini horpadasok szama: " << c << endl;

    return 0;
}
