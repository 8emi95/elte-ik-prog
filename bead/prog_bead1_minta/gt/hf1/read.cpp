//Készítette:Gregorics Tibor
//Dátum:     2008.01.23.
//Feladat:   segédfüggvények számok billentyûzetrõl való beolvasásához

#include "read.h"
#include <iostream>

using namespace std;

bool all(int k) {return true;}

//Feladat: 	Megadott feltételt kielégítõ egész számot olvas be.
//Bemenõ adatok:string msg	    - kiírandó üzenet
//				string errormsg	- kiírandó hibaüzenet
//Kimenõ adatok:int n (visszatérési érték)  - beolvasott egész szám: visszatérési érték
//Tevékenység:	Billentyûzetrõl olvas be egy a cond() feltételnek megfelelõ
//		egész számot. A  cond() feltétel alapértelmezés szerint
//		mindent elfogad, azaz bool c(int) { return true;}
int ReadInt(const string &msg, const string &errormsg, bool cond(int) )
{
    int n;
    bool hiba;
    do{
        cout << msg;
        string str;
        cin >> str;
        n = atoi(str.c_str());
        hiba = n==0 && str!="0" || !cond(n);
       if(hiba) cout<< errormsg<< endl;
    }while(hiba);
    return n;
}

//Feladat: 	Megadott feltételt kielégítõ természetes számot olvas be.
//Bemenõ adatok:string msg	    - kiírandó üzenet
//				string errormsg	- kiírandó hibaüzenet
//Kimenõ adatok:int n		    - beolvasott természetes szám: visszatérési érték
//Tevékenység:	Billentyûzetrõl olvas be egy a cond() feltételnek megfelelõ
// 		természetes számot. A  cond()feltétel alapértelmezés szerint
//		mindent elfogad, azaz bool c(int) { return true;}
int ReadNat(const string &msg, const string &errormsg, bool cond(int) )
{
    int n;
    bool hiba;
    do{
        cout << msg;
        string str;
        cin >> str;
        n = atoi(str.c_str());
        hiba = n==0 && str!="0" || n<0 || !cond(n);
       if(hiba) cout<< errormsg<< endl;
    }while(hiba);
    return n;
}
