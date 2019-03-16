#include "outfile.h"
#include <iomanip>

outfile::outfile(string fname="")
{
    if ( fname.size()<1 ) {
        cout<< "Add meg a t�rzsf�jl nev�t:" ;
        cin>>fname;
    }
    g.open(fname.c_str());
    if ( g.fail() ){
        cout<< "Nincs t�rzs f�jl" <<endl;
        char ch; cin>>ch;
        exit(2);
    }
}

void outfile::write(const konyv dy)
{
    g<<setw(4)<<' '<<dy.azon<<' '<<dy.szerzo<<' '<<dy.cim<<endl;
}

