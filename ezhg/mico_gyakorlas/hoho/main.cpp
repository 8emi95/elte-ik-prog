/*
Feladat: 3.beadandó/3.feladat
         Egy horgászversenyen valahányszor egy versenyzõ halat fog, feljegyzik egy szöveges állomány soron következõ sorába
         a versenyzõ azonosítóját (négyjegyû szám), a hal fajtájának nevét (ponty, keszeg, süllõ, stb.) és a hal méretét.
         Feltehetjük, hogy a szöveges állomány helyesen van kitöltve: minden sorában három adat van (azonosító, halfajta,
         méret) szóközökkel vagy tabulátorjelekkel elválasztva. A verseny végén a szöveges állomány sorait azonosító szerint
         sorba rendezik. Adjuk meg annak az azonosítóját, aki a legtöbb 30 cm-nél hosszabb pontyot fogta?
*/

#include <iostream>
#include "enor.h"

using namespace std;

int main() {
    cout << "Add meg a fajl nevet: ";
    string filename;
    cin >> filename;
    Enor t(filename);

    int max;
    ponty30nagy elem;
    //feltételes maximum keresés tételének alkalmazása
    bool l = false;
    for (t.First(); !t.End(); t.Next()) {
        if (t.Current().db == 0) { continue; }
        else if (t.Current().db != 0 && l) {
            if (t.Current().db > max) {
                max = t.Current().db;
                elem = t.Current();
            } else { continue; }
        } else {
            l = true;
            max = t.Current().db;
            elem = t.Current();
        }
    }
    if (l) {
        cout << "A legtobb 30 cm-nel nagyobb pontyot " << elem.versenyzo << " azonositoju versenyzo fogta." << endl;
        cout << "A kifogott mennyiseg: " << elem.db << " db." << endl;
    } else {
        cout << "Nem fogtak 30 cm-nel nagyobb pontyokat." << endl;
    }
    return 0;
}
