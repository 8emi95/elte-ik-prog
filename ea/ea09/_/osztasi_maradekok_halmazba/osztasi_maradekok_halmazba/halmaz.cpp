//Készítette:    Gregorics Tibor
//Dátum:         2009.01.24.
//Feladat:       Halmaz típus

#include "halmaz.h"

using namespace std;

//Feladat: 	    Üres halmaz létrehozása
//Kimenõ adat:  vector<bool> v  - halmazt reprezentáló tömb
//              int db          - halmaz elemszámát reprezentáló darabszám
//Tevékenység:	csupa hamis értékkel tölti fel a halmazt reprezentáló n méretû logikai tömböt (v),
//              és nullázza a darabszámot (db)
Halmaz::Halmaz()
{
    for (int i=0; i<n; i++) v[i] = false;
    db=0;
}

//Feladat: 	    Elemet tesz a halmazba
//Bemenõ adatok:int e           - halmazba betett elem
//Tevékenység:	Kivételt dob, ha a betenni kívánt elem nem esik a 0..n-1 intervallumba.
//              Ha a betenni kívánt elem már van a halmazban, akkor semmit nem csinál, egyébként v[e]-t true-ra
//              állítja és növeli a darabszámot (db)
void Halmaz::Be(int e) throw (Exception)
{
    if (e<0 || e>n-1) {
        Exception ex;
        ex.WrongInput = e;
        throw ex;
    }
    if (!v[e]){
        v[e] = true;
        db++;
    }
}

//Feladat: 	    Halmaz számosságának lekérdezése
//Kimenõ adatok:int    - halmaz elemeinek száma (visszatérési érték)
//Tevékenység:  A válasz a halmaz elemszámát reprezentáló darabszám
int Halmaz::Darab() const
{
    return db;
}

//Feladat: 	    Halmaz elemeinek kiírása
//Bemenő adatok:ostream    - kimeneti folyam
//              Halmaz     - egy halmaz
//Kimenõ adatok:ostream    - halmaz elemeinek sorozatával kiegészített kimeneti folyam
//Tevékenység:  Egy halmaz elemit jeleníti meg egy kimeneti folyamon
ostream& operator<<(ostream& o, const Halmaz &h)
{
    o << "{ ";
    for(int i=0; i<h.n; ++i){
        if(h.v[i]) o << i << " ";
    }
    o << "}";
    return o;
}

