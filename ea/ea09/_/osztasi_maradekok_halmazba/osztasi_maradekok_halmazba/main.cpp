//K�sz�tette:       Gregorics Tibor
//D�tum:            2009.01.24.
//Feladat:          Eg�sz sz�mok adott sz�mmal vett oszt�si marad�kainak halmazba �r�sa

#include <fstream>
#include <iostream>
#include "halmaz.h"
#include "read.h"

using namespace std;

bool notnull(int n) { return n!=0;}

//Feladat: 	        �rjuk ki egy sz�veges f�jlban megadott eg�sz sz�moknak egy adott eg�sz sz�mmal vett
//                  oszt�si marad�kait egy halmazba
//Bemen� adatok:    istream f    - eg�sz sz�mokat tartalmaz� sz�veges �llom�ny
//                  int n        - adott oszt�
//Kimen� adatok:    ostream cout - az oszt�si marad�kokat tartalmaz� szabv�nyos kimenet
//Tev�kenys�g:	    Bek�ri a f�jlnev�t �s megnyitja azt. Beolvassa az oszt�t. L�trehoz egy �res halmazt.
//                  Bej�rja a sz�veges �llom�nynak, mint szekvenci�lis inputf�jlnak az elemeit,
//                  egyenk�nt kisz�molja azok oszt�si marad�k�t �s beteszi �ket a halmazba.
//                  V�g�l ki�rja a halmaz elemeit.
int main()
{
    ifstream f;

    bool hiba = true;
    do{
        string fname;
        cout << "Mi a fajl neve: ";
        cin >> fname;
        f.open(fname.c_str());
        if(hiba=f.fail()) {
            cout << "Hibas fajlnev!\n";
            f.clear();
        }
    }while(hiba);

    int k = ReadInt("Adja meg az osztot: ", "Nem nulla egesz szamot kerek!", notnull);
    Halmaz h;

    int e;
    for(f >> e; !f.fail(); f >> e){ //Ha a f�jl helyes �s az utols� sor v�g�n is van sorv�gejel, akkor el�g lenne: !eof()
        h.Be(e%k);
    }

    cout << "Az osztasi maradekok: " << h << endl;

    char ch; cin >> ch;
    return 0;
}
