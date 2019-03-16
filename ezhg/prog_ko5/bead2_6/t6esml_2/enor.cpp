#include"enor.h"
#include<cstdlib>
#include<sstream>

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
        ss >> akt.be >> akt.nev >> akt.azon >> akt.ki; //ki nem biztos h létezik de megpróbáljuk beolvasni
        if(ss.fail())
            akt.ki = ""; //ss az üreset átugorja, magától nem rakja bele
        //ékezetek: setlocale(ALL)...
    }
}
