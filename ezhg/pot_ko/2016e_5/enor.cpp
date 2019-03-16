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

        string sv;
        ss >> sv;
        vector<string> v;
        while(!datum(sv))
        {
            v.push_back(sv);
            ss >> sv;
        }

        akt.ido = sv;
        akt.terem = v[v.size() - 1];
        akt.cim = "";
        for(int i = 0; i + 1 < v.size(); ++i)
            akt.cim += v[i] + " ";
        akt.cim = akt.cim.substr(0, akt.cim.size()-1); //értékül kell adni akt.cim-nek

        akt.jegyek.clear();
        Par j;
        ss >> j.hely;
        while(!ss.fail())
        {
            ss >> j.tipus;
            akt.jegyek.push_back(j);
            ss >> j.hely;
        }

        //ha nincs terem
        //string sv;
        //akt.nev = "";
        //while(ss >> sv && !datum(sv))
        //    akt.nev += sv + " ";
        //akt.nev = akt.nev.substr(0, akt.nev.size()-1);
        //akt.datum = sv;
    }
}
