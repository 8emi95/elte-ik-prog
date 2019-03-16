#include "enor.h"
#include <iostream>
#include <cstdlib>

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
        akt.versenyzo = dx.versenyzo;
        //megszámlálás tételének alkalmazása
        akt.db = 0;
        for (; sx == norm && dx.versenyzo == akt.versenyzo; Read()) {
            if (dx.halfajta == "ponty" && dx.meret > 30) { ++akt.db; }
            else { continue; }
        }
    }
}

void Enor::Read() {
    x >> dx.versenyzo;
    if (!x.fail()) {
        sx = norm;
        x >> dx.halfajta >> dx.meret;
    } else {
        sx = abnorm;
    }
}
