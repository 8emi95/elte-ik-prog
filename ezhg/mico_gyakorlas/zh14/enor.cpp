#include "enor.h"
#include <iostream>
#include <cstdlib>
#include <sstream>

using namespace std;




Enor::Enor(const string &fajlnev) {
	x.open(fajlnev.c_str());
	if (x.fail()) {
		cout << "Nem lehet megnyitni az inputfajlt!" << endl;
		exit(1);
	}
}

void Enor::First()
{
    Read();
    if (sx==abnorm)
    {
        cerr << "Ures fajl;";
        exit(1);
    }
    Next();
}

void Enor::Next() {
    vege = sx == abnorm;
    if (!vege) {
        akt.nev = dx.nev;
        //megszámlálás tételének alkalmazása
        akt.db = 0;
        akt.osszeg=0;
        for (; sx == norm && dx.nev == akt.nev; Read()) {
            akt.db++;
            akt.osszeg+=dx.osszeg;
            }
        }

}

void Enor::Read() {
    x >> dx.nev;

    if (!x.fail()) {
        sx = norm;
        x >> dx.datum;
        //uj osszeg
        int osszeg=0;
        string temp;
        getline(x, temp);
        stringstream ss(temp);
        while (ss>>temp)
        {
            if (isdigit(temp[0]))
            {
                osszeg+= atoi(temp.c_str());
            }
        }
        dx.osszeg=osszeg;
    } else {
        sx = abnorm;
    }
}
