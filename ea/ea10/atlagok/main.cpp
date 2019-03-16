//K�sz�tette:    Gregorics Tibor
//D�tum:         2015.02.22.
//Feladat:       Hallgat�k �tlagainak kisz�m�t�sa

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include "enor.h"

using namespace std;

//Feladat: 	        Egy sz�veges �llom�nyban a hallgat�k jegyeit t�roljuk, n�v szerint rendezve
//                  Adjuk meg az egyes hallgat�k jegy�tlag�t!
//Bemen� adatok:    ifstream   - inputf�jl
//Kimen� adatok:    ofstream g - outputf�jl
//Tev�kenys�g:	    Az �tlagok felsorol�s�nak m�sol�sa
int main()
{
    ofstream y("output.txt");
    if(y.fail()){
        cout << "Nem lehet �r�sra megnyitni a f�jlt\n";
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
