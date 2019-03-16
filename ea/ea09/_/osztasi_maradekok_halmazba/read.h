//Készítette:   Gregorics Tibor
//Dátum:        2008.12.06.
//Feladat:      Segédfüggvények számok billentyûzetrõl való beolvasásához
//Copyright:    Gregorics Tibor

#ifndef _READ_
#define _READ_

#include <string>

//Feladat: 	    Minden egész számra igazat ad
//Bemenõ:       int n - egész szám
//Kimenõ:       bool  - válasz (visszatérési érték)
bool all(int n);

//Feladat: 	    Eldönti, hogy egy egész szám nem-negatív-e
//Bemenõ:       int n - egész szám
//Kimenõ:       bool  - válasz (visszatérési érték)
bool nat(int n);

//Feladat: 	    Minden valós számra igazat ad
//Bemenõ:       double r - valós szám
//Kimenõ:       bool     - válasz (visszatérési érték)
bool all(double r);

//Feladat: 	    Eldönti, hogy egy valós szám nem-negatív-e
//Bemenõ:       double r - valós szám
//Kimenõ:       bool     - válasz (visszatérési érték)
bool not_neg(double r);

//Feladat: 	    Megadott feltételt kielégítõ egész számot olvas be.
//Bemenõ adatok:string msg	    - kiírandó üzenet
//              string err   	- kiírandó hibaüzenet
//              bool valid(int)	- ellenõrzõ függvény
//Kimenõ adatok:int n		- beolvasott természetes szám (visszatérési érték)
//Tevékenység:	Billentyûzetrõl olvas be egy a valid() feltételnek megfelelõ természetes számot.
//              A  valid()feltétel alapértelmezés szerint mindent elfogad.
int     read_int (const std::string &msg, const std::string &err, bool valid(int) =  all);

//Feladat: 		Megadott feltételt kielégítõ valós számot olvas be.
//Bemenõ adatok:string msg	      - kiírandó üzenet
//				string err  	  - kiírandó hibaüzenet
//              bool valid(double)- ellenõrzõ függvény
//Kimenõ adatok:double a	    - beolvasott egész szám (visszatérési érték)
//Tevékenység:	Billentyûzetrõl olvas be egy a valid() feltételnek megfelelõ egész számot.
//              A  valid() feltétel alapértelmezés szerint mindent elfogad.
double  read_real(const std::string &msg, const std::string &err, bool valid(double) =  all);

#endif
