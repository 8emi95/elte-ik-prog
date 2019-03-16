/*
Feladat: 3.beadand�/3.feladat
         Egy horg�szversenyen valah�nyszor egy versenyz� halat fog, feljegyzik egy sz�veges �llom�ny soron k�vetkez� sor�ba
         a versenyz� azonos�t�j�t (n�gyjegy� sz�m), a hal fajt�j�nak nev�t (ponty, keszeg, s�ll�, stb.) �s a hal m�ret�t.
         Feltehetj�k, hogy a sz�veges �llom�ny helyesen van kit�ltve: minden sor�ban h�rom adat van (azonos�t�, halfajta,
         m�ret) sz�k�z�kkel vagy tabul�torjelekkel elv�lasztva. A verseny v�g�n a sz�veges �llom�ny sorait azonos�t� szerint
         sorba rendezik. Adjuk meg annak az azonos�t�j�t, aki a legt�bb 30 cm-n�l hosszabb pontyot fogta?
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
    //felt�teles maximum keres�s t�tel�nek alkalmaz�sa
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
