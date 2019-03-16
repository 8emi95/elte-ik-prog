//Készítette:    Gregorics Tibor
//Dátum:         2014.12.08.
//Feladat:       Két természetes szám szorzata

#include <iostream>

using namespace std;

int read_nat(const string &msg);

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
        int x = read_nat("x = ");
        int y = read_nat("y = ");

        cout << "x*y = " << x << "*" << y << " = ";

    // Kiértékelés
        int z = 0;
        for(int i=1; i<=x; ++i){
            z = z + y;
        }

    // Eredmény kiírása
        cout << z << endl;

        cout << endl << "Futtassam ujra? (I/N)"; cin >> ch;
        string tmp=""; getline(cin, tmp);
    }while( ch!='n' && ch!='N');

    return 0;
}

//Feladat: 	Természetes számot olvas be.
//Bemenő adatok:string msg	    - kiírandó üzenet
//Kimenő adatok:int n (visszatérési érték)  - beolvasott egész szám: visszatérési érték
//Tevékenység:	Billentyűzetről olvas be egy természetes számot,
//              leellenőrzi, és amíg nem lesz helyes, újra és újra beolvassa.
int read_nat(const string &msg)
{
    int n;
    bool hiba;
    do{
        cout << msg;
        cin >> n;
        if((hiba=cin.fail())) cin.clear();
        string tmp=""; getline(cin, tmp);
        hiba = hiba || tmp.size()!=0 || n<0;
        if(hiba) cout << "Hibas input: Termeszetes szamot varok!\n";
    }while(hiba);

    return n;
}

