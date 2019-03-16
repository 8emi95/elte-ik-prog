//Készítette:Gregorics Tibor
//Dátum:     2010.02.26.
//Feladat:   segédfüggvények számok billentyûzetrõl való beolvasásához

#ifndef READ_H
#define READ_H

#include <string>

// Ellenõrzõ függvények
bool nat(int n) ;   // Természetes szám
bool all (int n);   // Minden egész szám

//Feladat: 	Megadott feltételt kielégítõ egész számot olvas be.
//Bemenõ adatok:string msg	    - kiírandó üzenet
//				string errormsg	- kiírandó hibaüzenet
//              bool check(int) - ellenõrzõ függvény
//Kimenõ adatok:int n (visszatérési érték)  - beolvasott egész szám: visszatérési érték
//Tevékenység:	Billentyûzetrõl olvas be egy a check() feltételnek megfelelõ
//		        egész számot.
int read_int(const std::string &msg, const std::string &err, bool check(int) = all);

#endif
