//K�sz�tette:Gregorics Tibor
//D�tum:     2010.02.26.
//Feladat:   seg�df�ggv�nyek sz�mok billenty�zetr�l val� beolvas�s�hoz

#ifndef READ_H
#define READ_H

#include <string>

// Ellen�rz� f�ggv�nyek
bool nat(int n) ;   // Term�szetes sz�m
bool all (int n);   // Minden eg�sz sz�m

//Feladat: 	Megadott felt�telt kiel�g�t� eg�sz sz�mot olvas be.
//Bemen� adatok:string msg	    - ki�rand� �zenet
//				string errormsg	- ki�rand� hiba�zenet
//              bool check(int) - ellen�rz� f�ggv�ny
//Kimen� adatok:int n (visszat�r�si �rt�k)  - beolvasott eg�sz sz�m: visszat�r�si �rt�k
//Tev�kenys�g:	Billenty�zetr�l olvas be egy a check() felt�telnek megfelel�
//		        eg�sz sz�mot.
int read_int(const std::string &msg, const std::string &err, bool check(int) = all);

#endif
