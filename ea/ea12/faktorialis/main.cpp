//K�sz�tette:    Gregorics Tibor
//D�tum:         2009.01.24.
//Feladat:       Faktori�lis sz�m�t�s

#include <iostream>
#include "bignumber.h"
#include "read.hpp"

using namespace std;

bool nat(int n) { return n>=0; }

//Feladat: 	    Kisz�molja egy nagy sz�m faktori�lis�t.
//Bemen� adatok:int n       - adott sz�m
//Kimen� adatok:BigNumber f - faktori�lis
//Tev�kenys�g:	Bek�r egy term�szetes sz�mot �s az �sszegz�s (�sszeszorz�s) t�tele
//              seg�ts�g�vel kisz�molja a faktori�lis�t.
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
