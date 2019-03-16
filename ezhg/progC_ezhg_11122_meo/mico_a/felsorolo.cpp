#include "felsorolo.h"
#include <stdlib.h>
#include <sstream>

using namespace std;


Felsorolo::Felsorolo(string fname)
{
    x.open(fname.c_str());
    if (!x.is_open())
    {
        cerr << "Nem sikerult megnyitni a fajlt.";
        exit(1);
    }
}
Felsorolo::~Felsorolo()
{
    x.close();
}

void Felsorolo::First()
{

    dx.arak.clear();

    bool rossz;
    int szam;
    for (int i=0; i<10; i++)
    {
        do{
            cout << "Adja meg az "<< i+1<< ". udito egysegarat: ";
            cin >> szam;

            rossz= cin.fail() or szam <= 0;
            if (rossz)
            {
                cerr << "Hibas adat. Ujra\n";
                cin.clear();
                cin.ignore();
            }else dx.arak.push_back(szam);

        }while(rossz);
    }
    cout << "amikor .... \n";
    Read(sx, dx, x);
}

void Felsorolo::Next()
{
    Read(sx, dx, x);
}
bool Felsorolo::End() const
{
    return (sx==abnorm);
}

Nap Felsorolo::Current() const
{
    return dx;
}
void Felsorolo::Read(Status & sx, Nap & dx, ifstream & x)
{
    dx.forgalom=0;
    dx.udito.clear();
    dx.sok=false;
    int temp_int;

    x >> dx.datum;

    for (int i=0; i<10; i++)
    {
        x >> temp_int;

        if (temp_int >= 100)dx.sok=true;

        dx.udito.push_back(temp_int);
    }

    for (int i=0; i<10; i++)
    {
        dx.forgalom+= dx.udito[i]* dx.arak[i];
    }

    sx = (x.fail() ? abnorm : norm);
}







