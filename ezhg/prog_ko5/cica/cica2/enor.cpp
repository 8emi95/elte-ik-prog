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
        ss >> akt.nev >> akt.kor;

        akt.kolkok.clear();
        string sv, sv2; //sv = Kiccica.nev, sv2 = Kiccica.nem

        //ha nincs szín
//        while(ss >> sv)
//        {
//            ss >> sv2;
//            Kiccica c;
//            c.nev = sv;
//            c.nem = sv2;
//            akt.kolkok.push_back(c);
//        }

        //ha van szin
        ss >> sv;
        while(ss >> sv2)
        {
            Kiccica c;
            c.nev = sv;
            c.nem = sv2;
            akt.kolkok.push_back(c);
            ss >> sv;
        }
        akt.szin = sv;
    }
}
