//K�sz�tette:   Gregorics Tibor
//D�tum:        2008.12.06.
//Feladat:      Seg�df�ggv�nyek sz�mok billenty�zetr�l val� beolvas�s�hoz
//Copyright:    Gregorics Tibor

#ifndef _READ_
#define _READ_

#include <string>

//Feladat: 	    Minden eg�sz sz�mra igazat ad
//Bemen�:       int n - eg�sz sz�m
//Kimen�:       bool  - v�lasz (visszat�r�si �rt�k)
bool all(int n);

//Feladat: 	    Eld�nti, hogy egy eg�sz sz�m nem-negat�v-e
//Bemen�:       int n - eg�sz sz�m
//Kimen�:       bool  - v�lasz (visszat�r�si �rt�k)
bool nat(int n);

//Feladat: 	    Minden val�s sz�mra igazat ad
//Bemen�:       double r - val�s sz�m
//Kimen�:       bool     - v�lasz (visszat�r�si �rt�k)
bool all(double r);

//Feladat: 	    Eld�nti, hogy egy val�s sz�m nem-negat�v-e
//Bemen�:       double r - val�s sz�m
//Kimen�:       bool     - v�lasz (visszat�r�si �rt�k)
bool not_neg(double r);

//Feladat: 	    Megadott felt�telt kiel�g�t� eg�sz sz�mot olvas be.
//Bemen� adatok:string msg	    - ki�rand� �zenet
//              string err   	- ki�rand� hiba�zenet
//              bool valid(int)	- ellen�rz� f�ggv�ny
//Kimen� adatok:int n		- beolvasott term�szetes sz�m (visszat�r�si �rt�k)
//Tev�kenys�g:	Billenty�zetr�l olvas be egy a valid() felt�telnek megfelel� term�szetes sz�mot.
//              A  valid()felt�tel alap�rtelmez�s szerint mindent elfogad.
int     read_int (const std::string &msg, const std::string &err, bool valid(int) =  all);

//Feladat: 		Megadott felt�telt kiel�g�t� val�s sz�mot olvas be.
//Bemen� adatok:string msg	      - ki�rand� �zenet
//				string err  	  - ki�rand� hiba�zenet
//              bool valid(double)- ellen�rz� f�ggv�ny
//Kimen� adatok:double a	    - beolvasott eg�sz sz�m (visszat�r�si �rt�k)
//Tev�kenys�g:	Billenty�zetr�l olvas be egy a valid() felt�telnek megfelel� eg�sz sz�mot.
//              A  valid() felt�tel alap�rtelmez�s szerint mindent elfogad.
double  read_real(const std::string &msg, const std::string &err, bool valid(double) =  all);

#endif
