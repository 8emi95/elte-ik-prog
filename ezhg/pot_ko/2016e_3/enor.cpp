#include"enor.h"
#include<cstdlib>
#include<sstream>
#include<vector>

using namespace std;

Enor::Enor(string fnev)
{
    x.open(fnev.c_str());
    if(x.fail())
    {
        cerr<<"A megadott fajl nem letezik."<<endl;
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
        vege = true;
    else
    {
        stringstream ss(sor);
        ss >> akt.azon >> akt.terem >> akt.ido;
        akt.jegyek.clear();
        Par j;
        ss >> j.hely;
        while(!ss.fail())
        {
            ss >> j.tipus;
            akt.jegyek.push_back(j);
            ss >> j.hely;
        }
    }
}
