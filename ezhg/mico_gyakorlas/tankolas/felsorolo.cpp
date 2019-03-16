#include "felsorolo.h"
#include <sstream>

using namespace std;

Felsorolo::Felsorolo(string fajlnev)
{
    x.open(fajlnev.c_str());
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
    dx.hanyszor=0;
    dx.osszeg=0;

    x >> dx.rendszam;
    dx.tank.clear();

    string temp;
    getline(x, temp);

    stringstream ss(temp);
    int mennyiseg;
    while (ss >> mennyiseg)
    {
        dx.osszeg+=mennyiseg;
        dx.tank.push_back(mennyiseg);
    }
    dx.hanyszor=(int)dx.tank.size();
    sx = (x.fail() ? abnorm : norm);
}
