//Készítette:    Gregorics Tibor
//Dátum:         2014.12.08.
//Feladat:       Két természetes szám szorzata

#include <iostream>
using namespace std;

//Feladat:       két természetes szám szorzatának kiszámolása szorzás nélkül
//Bemenõ adatok: int x	- természetes szám
//               int y  - természetes szám
//Kimenõ adatok: int z  - természetes szám, a szorzat
//Tevékenység:   Beolvas két természetes számot,
//               az y-t összegzi az x folyamatos csökkentése mellett, amíg az nulla nem lesz
//               és kiírja az eredményt
int main()
{
    cout << "Ket termeszetes szam szorzatanak kiszamolasa\n";

    char ch;
    do{
    //Adatok beolvasása
        int x, y, z;
        cout << endl;
        cout << "x = "; cin >> x;
        cout << "y = "; cin >> y;
        cout << "x*y = " << x << "*" << y << " = ";

    // Kiértékelés
        z = 0;
        while(x!=0){
            z = z + y;
            x = x - 1;
        }

    // Eredmény kiírása
        cout << z << endl;

        cout << endl << "Futtassam ujra? (I/N)"; cin >> ch;
    }while( ch!='n' && ch!='N');

    return 0;
}
