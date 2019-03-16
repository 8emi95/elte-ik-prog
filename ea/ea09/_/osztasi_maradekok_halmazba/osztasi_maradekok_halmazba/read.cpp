//K�sz�tette:   Gregorics Tibor
//D�tum:        2008.12.06.
//Feladat:      seg�df�ggv�nyek sz�mok billenty�zetr�l val� beolvas�s�hoz

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

//Feladat: 	    Megadott felt�telt kiel�g�t� eg�sz sz�mot olvas be.
//Bemen� adatok:string msg	- ki�rand� �zenet
//              string errormsg	- ki�rand� hiba�zenet
//              bool cond(int)	    - ellen�rz� f�ggv�ny
//Kimen� adatok:int n		- beolvasott term�szetes sz�m (visszat�r�si �rt�k)
//Tev�kenys�g:	Billenty�zetr�l olvas be egy a cond() felt�telnek megfelel� term�szetes sz�mot.
//              A  cond()felt�tel alap�rtelmez�s szerint mindent elfogad, , azaz ci()
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

//Feladat: 	    Megadott felt�telt kiel�g�t� term�szetes sz�mot olvas be.
//Bemen� adatok:string msg	    - ki�rand� �zenet
//              string errormsg	- ki�rand� hiba�zenet
//              bool cond(int)	- ellen�rz� f�ggv�ny
//Kimen� adatok:int n		    - beolvasott term�szetes sz�m (visszat�r�si �rt�k)
//Tev�kenys�g:	Billenty�zetr�l olvas be egy a cond() felt�telnek megfelel� term�szetes sz�mot.
//              A  cond()felt�tel alap�rtelmez�s szerint mindent elfogad, azaz ci()
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

//Feladat: 		Megadott felt�telt kiel�g�t� val�s sz�mot olvas be.
//Bemen� adatok:string msg	    - ki�rand� �zenet
//				string errormsg	- ki�rand� hiba�zenet
//              bool cond(double)- ellen�rz� f�ggv�ny
//Kimen� adatok:double a	    - beolvasott eg�sz sz�m (visszat�r�si �rt�k)
//Tev�kenys�g:	Billenty�zetr�l olvas be egy a cond() felt�telnek megfelel� eg�sz sz�mot.
//              A  cond() felt�tel alap�rtelmez�s szerint mindent elfogad, azaz cd()
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
