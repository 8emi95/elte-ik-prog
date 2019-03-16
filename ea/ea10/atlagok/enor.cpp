#include "enor.h"

using namespace std;

//Feladat: 	Hallgatók átlagait felsoroló konstruktora
//Bemenõ adatok:string str	- a megnyitandó szöveges állomány neve
//Kimenõ adatok:ifstream f	- hallgatók jegyeit tartalmazó szekvenciális inputfájl
//Tevékenység:	Megnyitja a szöveges állományt, mint szekvenciális input fájlt,
//              amelyből a felsoroló a hallgatói átlagokat veszi.
Enor::Enor(const std::string &str) {
    x.open(str.c_str());
    if(x.fail()){
        std::cout << "Nem lehet olvasásra megnyitni a fájlt\n";
        exit(1);
    }
}

//Feladat: 	Hallgatók átlagait felsoroló konstruktora
//Bemenõ adatok:ifstream f	- hallgatók jegyeit tartalmazó szekvenciális inputfájl
//				Pair df  	- előzőleg beolvasott hallgató és jegye, feltéve, hogy sikerült olvasni
//Kimenõ adatok:bool fin    - "nincs több hallgató" flag
//              Pair cur    - soronkövetkező hallgató átlaga
//              ifstream f	- további hallgatók jegyeit tartalmazó szekvenciális inputfájl
//				Pair df  	- éppen beolvasott hallgató és jegye
//Tevékenység:	Ellenőrzi, hogy van-e még sikeresen beolvasott hallgató. Ha igen, akkor
//		        ennek a hallgatónak kiszámolja az átlagát úgy, hogy beolvassa nevével kezdődő
//              összes sort, közben megszámolja és összegzi a jegyeket. Végül átlagot számol.
void Enor::next()
{
    if( (vege = x.fail()) ) return;
    h.azon = dx.azon;
    h.jegy = 0.0;
    int db = 0;
    while( !x.fail() && dx.azon==h.azon ){
        h.jegy += dx.jegy;
        ++db;
        x >> dx.azon >> dx.jegy;
    }
    h.jegy /= db;
}
