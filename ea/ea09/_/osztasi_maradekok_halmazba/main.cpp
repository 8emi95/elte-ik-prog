//K�sz�tette:       Gregorics Tibor
//D�tum:            2009.01.24.
//Feladat:          Term�szetes sz�mok adott term�szetes sz�mmal vett oszt�si marad�kainak halmazba �r�sa

#include <fstream>
#include <iostream>
#include "halmaz.h"
#include "read.h"

using namespace std;

bool positive(int n) { return n>0;}

//Feladat: 	        �rjuk ki egy sz�veges f�jlban megadott term�szetes sz�moknak
//                  egy adott term�szetes sz�mmal vett
//                  oszt�si marad�kait egy halmazba
//Bemen� adatok:    istream f    - term�szetes sz�mokat tartalmaz� sz�veges �llom�ny
//                  int n        - adott term�szetes oszt�
//Kimen� adatok:    ostream cout - az oszt�si marad�kokat tartalmaz� szabv�nyos kimenet
//Tev�kenys�g:	    Bek�ri a f�jlnev�t �s megnyitja azt. Beolvassa az oszt�t. L�trehoz egy �res halmazt.
//                  Bej�rja a sz�veges �llom�nynak, mint szekvenci�lis inputf�jlnak az elemeit,
//                  egyenk�nt kisz�molja azok oszt�si marad�k�t �s beteszi �ket a halmazba.
//                  V�g�l ki�rja a halmaz elemeit.
int main()
{
    ifstream x;

    bool hiba = true;
    do{
        string fname;
        cout << "Mi a fajl neve: ";
        cin >> fname;
        x.open(fname.c_str());
        if( (hiba=x.fail()) ) {
            cout << "Hibas fajlnev!\n";
            x.clear();
        }
    }while(hiba);

    int k = read_int("Adja meg az osztot: ", "Pozitiv egesz szamot kerek!", positive);

    Halmaz h(k);
    int e;
    for(x >> e; !x.fail(); x >> e){ //Ha a f�jl helyes �s az utols� sor v�g�n is van sorv�gejel, akkor el�g lenne: !eof()
        try{
            h.Be(e%k);
        }catch(Halmaz::Exception ex){
            cout << "Nem lehet a fajlban negativ szam!\n";
        }
    }
    cout << "Az osztasi maradekok: " << h << endl;

    return 0;
}
