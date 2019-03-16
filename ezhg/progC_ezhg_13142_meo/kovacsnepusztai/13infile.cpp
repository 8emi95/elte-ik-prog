#include "infile.h"
#include <cstdlib>
#include <sstream>
#include <iostream>

using namespace std;

SeqInfile::SeqInfile(string fname)
{
  if(fname.size()<1){
    cout<<"Filenev:";
    cin>> fname;
  }
  f.open(fname.c_str());
  if (f.fail()) {
    cerr<<"Nincs meg az adott file!\n";
    exit(1);
  }
}

void SeqInfile::read()
{
    stringstream s;
    string sor;
    string v;
    int o;
    getline(f,sor);  //egy sor olvas�sa a f�jlb�l
    if(!f.fail()){
        st=norm;

        s<<sor;   //sor bem�sol�sa stringstream-be a sz�tdarabol�shoz

        //nev beolvasasa
        elem.nev="";
        s>>v;
        do{
            elem.nev=elem.nev+" "+v;
            s>>v;
            o=atoi(v.c_str());
        } while (o==0);
       // D�tum �s �sszeg tombjeinek feltoltese
        elem.datum.resize(0);
        elem.osszeg.resize(0);
        while( !s.fail()){
           elem.datum.push_back(v);
           s>>o;
           elem.osszeg.push_back(o);
           s>>v;
        }
    }
    else st=abnorm;
}
