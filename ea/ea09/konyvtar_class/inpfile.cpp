#include "inpfile.h"

inpfile::inpfile(string fname="")
{
    if ( fname.size()<1 ) {
        cout<< "Add meg a törzsfájl nevét:" ;
        cin>>fname;
    }
    f.open(fname.c_str());
    if ( f.fail() ){
        cout<< "Nincs törzs fájl" <<endl;
        char ch; cin>>ch;
        exit(2);
    }
}

void inpfile::read(konyv &dx, status &sx)
{
  string sor;

  getline(f,sor,'\n');
  if (!f.eof()) {
    sx=norm;
    dx.azon   =atoi(sor.substr( 0, 4).c_str());
    dx.szerzo =     sor.substr( 5,14);
    dx.cim    =     sor.substr(20,19);
    dx.kiado  =     sor.substr(40,14);
    dx.ev     =     sor.substr(55, 4);
    dx.darab  =atoi(sor.substr(60, 3).c_str());
    dx.isbn   =     sor.substr(64,14);
  }
  else sx=abnorm;
}

