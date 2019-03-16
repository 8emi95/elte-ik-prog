//Készítette:    Gregorics Tibor
//Dátum:         2014.12.08.
//Feladat:       Két természetes szám szorzata

#include <iostream>
#include <string>

using namespace std;

bool nat(int n){ return n>=0;}
bool all(int n) { return true; }
int read_int(const string &msg, const string &err, bool valid(int) = all);

//Feladat:       két természetes szám szorzatának kiszámolása szorzás nélkül
//Bemenõ adatok: int x	- természetes szám
//               int y  - természetes szám
//Kimenõ adatok: int z  - természetes szám, a szorzat
//Tevékenység:   Beolvas ellenőrzés mellett két természetes számot,
//               az y-t összegzi x-szer (összegzés programozási tétele)
//               és kiírja az eredményt
int  main()
{
    cout << "Ket termeszetes szam szorzatanak kiszamolasa\n";

    char ch;
    do{
    //Adatok beolvasása
        cout << endl;
        string str = "Hibas input: 0 es 2^31-1 kozotti termeszetes szam kell!";
        int a = read_int("x = ", str, nat);
        int b = read_int("y = ", str, nat);
        cout << "x*y = " << a << "*" << b << " = ";

    // Kiértékelés
        int x, y;

        if(a<b){ x = a; y = b;}
        else{ x = b; y = a;}

        bool overflow = false;
        int z = 0;
        for(int i=0; i<x; ++i){
            if ((overflow =(y>2147483647-z)))  break;
            z = z + y;
        }

    // Eredmény kiírása
        if (overflow) cout << "Tulcsordulas!\n";
        else cout << z << endl;

        cout << endl << "Futtassam ujra? (I/N)"; cin >> ch;
        string tmp; getline(cin, tmp);
    }while( ch!='n' && ch!='N');

    return 0;
}

//Feladat: 	Megadott feltételt kielégítő egész számot olvas be.
//Bemenő adatok:string msg	    - kiírandó üzenet
//				string err  	- kiírandó hibaüzenet
//              bool valid(int)- ellenőrző függvény
//Kimenő adatok:int n (visszatérési érték)  - beolvasott egész szám: visszatérési érték
//Tevékenység:	Billentyűzetről olvas be egy a valid() feltételnek megfelelő
//		        egész számot.
//Copyright:    Gregorics Tibor
int read_int(const string &msg, const string &err, bool valid(int))
{
    int n;
    bool hiba;
    do{
        cout << msg;
        cin >> n;
        if((hiba=cin.fail())) cin.clear();
        string tmp=""; getline(cin, tmp);
        hiba = hiba || tmp.size()!=0 || !valid(n);
        if(hiba) cout << err << endl;
    }while(hiba);

    return n;
}
