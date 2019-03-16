#include "infile.h"
#include <cstdlib>
#include <sstream>
#include <iostream>

using namespace std;

infile::infile(string fname)
{
    if (fname.size()<1)
    {
        cout <<"Filenev: ";
        cin>>fname;
    }
    f.open(fname.c_str());
    if (f.fail())
    {
        cerr<<"Nincs meg az adott file!"<<endl;
        exit(1);
    }
}

void infile::read()
{
    stringstream s;
    string sor;
    getline(f,sor);
    if(!f.fail())
    {
        st=norm;
        s<<sor;
        elem.aruk.resize(0);
        s>>elem.ido;
        s>>elem.kod;
        string arukod;
        s>>arukod;
        while (!s.fail())
        {
            elem.aruk.push_back(arukod);
            s>>arukod;
        }
    }
    else
    {
        st=abnorm;
    }
}
