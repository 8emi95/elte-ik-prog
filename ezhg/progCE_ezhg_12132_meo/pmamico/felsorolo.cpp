#include "felsorolo.h"
#include <sstream>
#include <stdlib.h>
using namespace std;

Felsorolo::Felsorolo(string filename)
{
    x.open(filename.c_str());
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
    return (sx==abnorm);
}

void Felsorolo::Read(Status & sx, Struktura & dx, ifstream & x)
{
    dx.korido.clear();
    dx.gyorsul=true;
    x >> dx.nev >>dx.csapat;
    string temp;
    Korido kor_temp;
    getline(x, temp);

    stringstream ss(temp);
    while (ss >> temp)
    {
        kor_temp.kor=atoi(temp.c_str());
        ss >> kor_temp.ido;

        dx.korido.push_back(kor_temp);
    }

    temp=dx.korido[0].ido;
    for (int i=1; i<(int)dx.korido.size(); i++)
    {
        if (dx.korido[i].ido>temp)
        {
            dx.gyorsul=false;
        }
        temp=dx.korido[i].ido;
    }

    sx = (x.fail() ? abnorm : norm);
}
