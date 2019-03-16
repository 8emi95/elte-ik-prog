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
#include <cstdlib>

using namespace std;

int convertTime(string s)
{
    ///03:14
    string ora=s.substr(0, 2);
    string perc=s.substr(3, 2);
    int ora_szam= atoi(ora.c_str());
    int perc_szam= atoi(perc.c_str());


    return ((60*ora_szam) + perc_szam);

}
void writeCurrent(current c);

int main() {

    cout << convertTime("09:13")-convertTime("09:11");
    cout << "Add meg a fajl nevet: ";
    string filename;
    cin >> filename;
    Enor t(filename);
    current c;
    int s=0;

    current min_elem;
    bool l=false; //befizette
    for (t.First(); !t.End(); t.Next()) {
        c=t.Current();

        if (!l and c.osszeg>=11000)
        {
            min_elem.nev=c.nev;
            min_elem.db=c.db;
            l=true;
        }
        else if (l and c.osszeg>=11000 and c.db<min_elem.db)
        {
            min_elem.nev=c.nev;
            min_elem.db=c.db;
        }
        //writeCurrent(c);
        //cout << c.nev << " " << c.osszeg << " "<<c.db<<endl;
        s+=c.osszeg;


        }
        cout << "Osszesen: "<< s<< endl;
        if (l)
        {
            cout << "Legkevesebb befizetessel teljesitett: "<< min_elem.nev;
        }
        else
        {
            cout << "Nem volt teljesites.";
        }
    return 0;
}
void writeCurrent(current c)
{
    cout << c.nev << " "<< c.osszeg << " "<<c.db<<endl;
}
