//K�sz�tette:       Gregorics Tibor
//D�tum:            2009.01.24.
//Feladat:          Term�szetes sz�mok adott term�szetes sz�mmal vett oszt�si marad�kainak ki�r�sa

#include <fstream>
#include <iostream>
#include "read.hpp"

using namespace std;

bool not_null(int n) { return n!=0;}

//Feladat: 	        �rjuk ki egy sz�veges f�jlban megadott term�szetes sz�moknak
//                  egy adott term�szetes sz�mmal vett
//                  oszt�si marad�kait a szabv�nyos kimenetre
//Bemen� adatok:    istream f    - term�szetes sz�mokat tartalmaz� sz�veges �llom�ny
//                  int n        - adott term�szetes sz�m oszt�
//Kimen� adatok:    ostream cout - az oszt�si marad�kokat tartalmaz� szabv�nyos kimenet
//Tev�kenys�g:	    Bek�ri a f�jlnev�t �s megnyitja azt. Beolvassa az oszt�t. Bej�rja a sz�veges �llom�nynak,
//                  mint szekvenci�lis inputf�jlnak az elemeit, egyenk�nt kisz�molja azok
//                  oszt�si marad�k�t �s ki�rja �ket a szabv�nyos kimenetre.
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

    int k = read<int>("Adja meg az osztot: ", "Pozitiv egesz szamot kerek!", not_null);

    cout << "A megadott szamok osztasi maradekai: ";
    int e;
    for(x >> e; !x.fail(); x >> e){ //Ha a f�jl helyes �s az utols� sor v�g�n is van sorv�gejel, akkor el�g lenne: !eof()
        cout << e%k << " ";
    }

    return 0;
}
