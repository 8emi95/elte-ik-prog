#include "felsorolo.h"
#include <sstream>
#include <locale>  //isdigit()
#include <stdlib.h>
#include <iostream>
#include <cstdlib>

using namespace std;

Felsorolo::Felsorolo(string fajlnev)
{
    x.open(fajlnev.c_str());
    if (x.fail())cout << "Fajl megnyitasa sikertelen. "<< endl;
}

Felsorolo::~Felsorolo()
{
    x.close();
}

void Felsorolo::First()
{
    Read(sx, dx, x);
}

void Felsorolo::Next()
{
    Read(sx, dx, x);
}

Struktura Felsorolo::Current() const
{
    return dx;
}

bool Felsorolo::End() const
{
    return (abnorm == sx);
}

void Felsorolo::Read(Status & sx, Struktura & dx, ifstream & x)
{
    dx.osszeg=0;
    dx.nev.clear();
    dx.fizet.clear();
    dx.datum.clear();
    string temp;
    getline(x, temp);
    stringstream ss(temp);
    int mennyiseg;
    string szoveg;
    while (ss >> szoveg)
    {
        if (!isdigit(szoveg[0]))
        {
            dx.nev.push_back(szoveg);
        }
        else
        {
           dx.datum.push_back(szoveg);

           ss>> mennyiseg;
           dx.fizet.push_back(mennyiseg);
           dx.osszeg+= mennyiseg;
        }
    }
    string temp_d= szoveg;
    for (int i=0; i<10; i++)
    {
        if (!isdigit(temp_d[i]))
        {
            temp_d[i]='0';
        }
    }
    dx.last_date=atoi(temp_d.c_str());
    sx = (x.fail() ? abnorm : norm);
}
