#include "enor.h"
#include<vector>
#include<sstream>
#include<cstdlib>
#include<iostream>
#include<fstream>

Felsorolo::Felsorolo(string fajlnev)
{
    this -> fajl.open(fajlnev.c_str());
    if (this->fajl.fail())
    {
        cout << "Nem letezik ilyen fajl." << endl;
        exit(1);
    }
    this -> st = norm;
}

void Felsorolo::read() //egy sor beolvas�sa
{
    if (this -> fajl.eof())
    {
        this -> st = abnorm;
        return;
    }

    string sor;
    getline(this -> fajl, sor);
    stringstream sorStream(sor);
    char kuka;
    sorStream >> this -> vasarl.ev >> kuka >> this -> vasarl.ho >> kuka >> this -> vasarl.nap >> kuka >> this -> vasarl.ora >> kuka >> this -> vasarl.perc >> this -> vasarl.azon;

    this -> vasarl.arukod.clear(); //k�l n�veln� mindig a vektort a k�vi sor �ruval
    while(!sorStream.eof())
    {
        string kod;
        sorStream >>  kod;
        this -> vasarl.arukod.push_back(kod);
    }
}
