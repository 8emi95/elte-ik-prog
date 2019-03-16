#include "Enor.h"
#include<sstream>
#include<cstdlib>

using namespace std;

Enor::Enor(string fnev)
{
    x.open(fnev.c_str());
    if(x.fail())
    {
        cerr<<"hibas vagy nem letezo fajl"<<endl;
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
    Next();
}
void Enor::Next()
{
    string sor;
    getline(x,sor);
    if(x.fail())
    {
        vege = true;
    }
    else
    {
        stringstream ss(sor);
        ss>>akt.nev>>akt.mezony;
    }
    string sor2;
    getline(x,sor2);
    if(x.fail())
    {
        vege = true;
    }
    else
    {
        stringstream ss(sor2);
        ss>>akt.csapat1>>akt.csapat2;
    }
}
