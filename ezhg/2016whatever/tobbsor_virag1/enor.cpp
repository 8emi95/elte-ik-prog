#include"enor.h"
#include<cstdlib>
#include<sstream>
//potencialisan mast is be kellhet include-olni...

using namespace std;

Enor::Enor(string fnev)
{
    x.open(fnev.c_str());
    if(x.fail())
    {
        cerr<<"A megadott fajl nem letezik."<<endl;
        //esetleg csak igazra allitom a vege-t, es a foprogramban kezelem le
        //esetleg dobok egy exceptiont
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
    string a;
    getline(x,a); //ha nem >>-lel olvasom be, akkor lenyeli az utána levõ entert
    if (x.fail())
    {
        vege=true;
    }
    else
    {
        stringstream ss(a);
        string sv;
        ss >> akt.abc;
        while (ss >> sv)
        {
            akt.bcd.push_back(sv);
        }
    }
    string sor;
    getline(x,sor);
    if (x.fail())
    {
        vege=true;
    }
    else
    {
        stringstream ss(sor);
        string sv;
        while (ss >> sv)
        {
            akt.cde.push_back(sv);
        }
    }
}
