#include "Enor.h"
#include<cstdlib>
#include<sstream>

using namespace std;

Enor::Enor(string fnev)
{
    x.open(fnev.c_str());
    if(x.fail())
    {
        cerr<<"hibas vagy nem letezo fajl";
        exit(1);
    }
}

Enor::~Enor()
{
    x.close();
}

void Enor::First()
{
    vege = false;
    string sor;
    getline(x,sor);
    stringstream ss(sor);
    string seged;
    while(ss>>seged)
    {
        akt.rovidetes.push_back(seged);
    }
    Next();
}

void Enor::Next()
{
        string sor;
        getline(x,sor);
        stringstream ss(sor);
        if(x.fail())
        {
            vege = true;
        }
        else
        {
            ss>>akt.asztalszam>>akt.ido;
            Par p;
            ss>>p.adag;
            akt.p.resize(0);
            while(!ss.fail())
            {
                ss>>p.tipus;
                akt.p.push_back(p);
                ss>>p.adag;
            }

        }
}
