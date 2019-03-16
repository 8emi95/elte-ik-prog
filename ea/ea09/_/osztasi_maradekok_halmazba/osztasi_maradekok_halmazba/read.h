//K�sz�tette:   Gregorics Tibor
//D�tum:        2008.12.06.
//Feladat:      Seg�df�ggv�nyek sz�mok billenty�zetr�l val� beolvas�s�hoz

#ifndef _READ_
#define _READ_

#include <string>

bool ci(int k);
bool cd(double k);

int     ReadInt(std::string msg, std::string errormsg, bool cond(int) =  ci);
int     ReadNat(std::string msg, std::string errormsg, bool cond(int) =  ci);
double  ReadReal(std::string msg, std::string errormsg, bool cond(double) =  cd);

#endif
