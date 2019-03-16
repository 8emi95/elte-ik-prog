//Készítette:Gregorics Tibor
//Dátum:     2008.01.23.
//Feladat:   segédfüggvények számok billentyûzetrõl való beolvasásához


#ifndef _READ_
#define _READ_

#include <string>

bool all(int k);

int ReadInt(const std::string &msg, const std::string &errormsg, bool cond(int) =  all);
int ReadNat(const std::string &msg, const std::string &errormsg, bool cond(int) =  all);

#endif
