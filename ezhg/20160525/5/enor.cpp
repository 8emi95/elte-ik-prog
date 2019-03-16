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
        ss >> akt.azon;

        akt.idojarat.clear();
        string sv, sv2;
        while(ss >> sv)
        {
            Utas u;
            u.ido = sv;
            ss >> sv2;
            u.jarat = sv2;
            akt.idojarat.push_back(u);
        }
    }
}
