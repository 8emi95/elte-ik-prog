//K�sz�tette:Gregorics Tibor
//D�tum:     2008.01.23.
//Feladat:   seg�df�ggv�nyek sz�mok billenty�zetr�l val� beolvas�s�hoz


#ifndef _READ_
#define _READ_

#include <string>

bool all(int k);

int ReadInt(const std::string &msg, const std::string &errormsg, bool cond(int) =  all);
int ReadNat(const std::string &msg, const std::string &errormsg, bool cond(int) =  all);

#endif
