//Készítette:    Gregorics Tibor
//Dátum:         2015.02.22.
//Feladat:       Hallgatók átlagainak kiszámítása

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include "enor.h"

using namespace std;

//Feladat: 	        Egy szöveges állományban a hallgatók jegyeit tároljuk, név szerint rendezve
//                  Adjuk meg az egyes hallgatók jegyátlagát!
//Bemenõ adatok:    ifstream   - inputfájl
//Kimenõ adatok:    ofstream g - outputfájl
//Tevékenység:	    Az átlagok felsorolásának másolása
int main()
{
    ofstream y("output.txt");
    if(y.fail()){
        cout << "Nem lehet írásra megnyitni a fájlt\n";
        exit(1);
    }
    Enor t("input.txt");
    y.setf(ios::left);
    for( t.first(); !t.end(); t.next()){
        y << setw(10) << t.current().azon << " "
          << setprecision(2) << t.current().jegy
          << endl;
    }
    return 0;
}
