//Készítette:Gregorics Tibor
//Dátum:     2010.02.26.
//Feladat:   segédfüggvények számok billentyûzetrõl való beolvasásához

#include "read.h"

#include <iostream>

using namespace std;

//Feladat: 	Megadott feltételt kielégítõ egész számot olvas be.
//Bemenõ adatok:string msg	    - kiírandó üzenet
//				string errormsg	- kiírandó hibaüzenet
//              bool check(int) - ellenõrzõ függvény
//Kimenõ adatok:int n (visszatérési érték)  - beolvasott egész szám: visszatérési érték
//Tevékenység:	Billentyûzetrõl olvas be egy a check() feltételnek megfelelõ
//		        egész számot.
int read_int(const string &msg, const string &err, bool check(int))
{
    int n;
    bool hiba;
    string tmp;
    do{
        cout << msg;
        string str;
        cin >> n;
        hiba = cin.fail() || !check(n);
        if(hiba) {
            cout << err << endl;
            cin.clear(); getline(cin, tmp);
        }
    }while(hiba);
    getline(cin, tmp);

    return n;
}

// Ellenõrzõ függvények
bool nat(int n) { return n>=0; }         // természetes szám
bool all(int n) { return true; }         // tetszõleges egész szám
