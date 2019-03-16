//Készítette:   Gregorics Tibor
//Dátum:        2008.12.06.
//Feladat:      segédfüggvények számok billentyûzetrõl való beolvasásához

#include "read.h"
#include <iostream>

using namespace std;

bool ci(int k)
{
    return true;
}

bool cd(double k)
{
    return true;
}

//Feladat: 	    Megadott feltételt kielégítõ egész számot olvas be.
//Bemenõ adatok:string msg	- kiírandó üzenet
//              string errormsg	- kiírandó hibaüzenet
//              bool cond(int)	    - ellenõrzõ függvény
//Kimenõ adatok:int n		- beolvasott természetes szám (visszatérési érték)
//Tevékenység:	Billentyûzetrõl olvas be egy a cond() feltételnek megfelelõ természetes számot.
//              A  cond()feltétel alapértelmezés szerint mindent elfogad, , azaz ci()
int ReadInt(string msg, string errormsg, bool cond(int) )
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

//Feladat: 	    Megadott feltételt kielégítõ természetes számot olvas be.
//Bemenõ adatok:string msg	    - kiírandó üzenet
//              string errormsg	- kiírandó hibaüzenet
//              bool cond(int)	- ellenõrzõ függvény
//Kimenõ adatok:int n		    - beolvasott természetes szám (visszatérési érték)
//Tevékenység:	Billentyûzetrõl olvas be egy a cond() feltételnek megfelelõ természetes számot.
//              A  cond()feltétel alapértelmezés szerint mindent elfogad, azaz ci()
int ReadNat(string msg, string errormsg, bool cond(int) )
{
    int n;
    bool hiba;
    do{
        cout << msg;
        string str;
        cin >> str;
        n = atoi(str.c_str());
        hiba = n==0 && str!="0" || n<0;
       if(hiba) cout<< errormsg<< endl;
    }while(hiba);
    return n;
}

//Feladat: 		Megadott feltételt kielégítõ valós számot olvas be.
//Bemenõ adatok:string msg	    - kiírandó üzenet
//				string errormsg	- kiírandó hibaüzenet
//              bool cond(double)- ellenõrzõ függvény
//Kimenõ adatok:double a	    - beolvasott egész szám (visszatérési érték)
//Tevékenység:	Billentyûzetrõl olvas be egy a cond() feltételnek megfelelõ egész számot.
//              A  cond() feltétel alapértelmezés szerint mindent elfogad, azaz cd()
double  ReadReal(string msg, string errormsg, bool cond(double))
{
    double a;
    bool hiba;
    do{
        cout << msg;
        string str;
        cin >> str;
        a = atof(str.c_str());
        hiba = a==0 && str!="0";
       if(hiba) cout<< errormsg<< endl;
    }while(hiba);
    return a;
}
