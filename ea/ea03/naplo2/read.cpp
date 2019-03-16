//K�sz�tette:Gregorics Tibor
//D�tum:     2010.02.26.
//Feladat:   seg�df�ggv�nyek sz�mok billenty�zetr�l val� beolvas�s�hoz

#include "read.h"

#include <iostream>

using namespace std;

//Feladat: 	Megadott felt�telt kiel�g�t� eg�sz sz�mot olvas be.
//Bemen� adatok:string msg	    - ki�rand� �zenet
//				string errormsg	- ki�rand� hiba�zenet
//              bool check(int) - ellen�rz� f�ggv�ny
//Kimen� adatok:int n (visszat�r�si �rt�k)  - beolvasott eg�sz sz�m: visszat�r�si �rt�k
//Tev�kenys�g:	Billenty�zetr�l olvas be egy a check() felt�telnek megfelel�
//		        eg�sz sz�mot.
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

// Ellen�rz� f�ggv�nyek
bool nat(int n) { return n>=0; }         // term�szetes sz�m
bool all(int n) { return true; }         // tetsz�leges eg�sz sz�m
