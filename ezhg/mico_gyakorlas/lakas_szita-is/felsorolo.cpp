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
    dx.bef_ossz=0;
    dx.datum.clear();
    dx.fizet.clear();



    string sor;
    getline (x, sor);
    stringstream ss(sor);
   // cout <<"sor: " <<sor << endl;
    ss>> dx.azon >> dx.osszeg;
    dx.osszeg*=5;
    string temp;
    int temp2;
    while(ss>>temp)
    {
        dx.datum.push_back(temp);
        ss>> temp2;
        dx.bef_ossz+=temp2;
        dx.fizet.push_back(temp2);
    }

    dx.becsulet= dx.bef_ossz>=dx.osszeg;


    sx = (x.fail() ? abnorm : norm);
}
