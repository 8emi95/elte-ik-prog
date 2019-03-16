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
    string sor;
    getline(x,sor);
    if(x.fail())
        vege = true;
    else
    {
        stringstream ss(sor);
        //ss-bol kiolvassuk rendre az elemeket, es feldolgozzuk.
        //Ennek lehetseges modjait lasd a konkret peldafeladatokban.
    }
}
