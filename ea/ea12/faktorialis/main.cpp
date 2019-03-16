//Készítette:    Gregorics Tibor
//Dátum:         2009.01.24.
//Feladat:       Faktoriális számítás

#include <iostream>
#include "bignumber.h"
#include "read.hpp"

using namespace std;

bool nat(int n) { return n>=0; }

//Feladat: 	    Kiszámolja egy nagy szám faktoriálisát.
//Bemenõ adatok:int n       - adott szám
//Kimenõ adatok:BigNumber f - faktoriális
//Tevékenység:	Bekér egy természetes számot és az összegzés (összeszorzás) tétele
//              segítségével kiszámolja a faktoriálisát.
int main()
{
    cout << "Faktorialis szamitas!" << endl << endl;

    char ch = 'I';
    do{
        BigNumber f;

        int n = read<int>("\nn = ", "Termeszetes szam kell!", nat );

        f = 1;
        for(int i = 2; i<=n; ++i){
            f = f * i;
        }

        cout << "n!= " << f << endl;

        cout << "Folytatod? (I/N)";
        cin >> ch; string tmp; getline(cin,tmp);
    }while( !('n'==ch || 'N'==ch) );

     return 0;
}
