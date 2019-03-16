//Készítette:    Gregorics Tibor
//Dátum:         2009.01.23.
//eha kód:       EHACODE.ELTE
//mail:          gt@inf.elte.hu
//csoport:       0.csoport
//Feladat:       Van-e minden tanulónak legalább két tantárgyból ötöse


#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>
#include "read.h"

using namespace std;

void Neveket_olvas(int n, const string &str, vector<string> &v);
void Jegyeket_olvas(const vector<string> &tanulo, const vector<string> &targy, vector<vector<int> > &a);

void Fajlbol_olvas(const string &fajlnev, vector<string> &tanulo, vector<string> &targy, vector<vector<int> > &naplo);

bool Mindenkinek_ket_otos(const vector<vector<int> > &naplo);
int OtosDb(const vector<int> &v);

bool Jegy(int k);
bool egykettoharom(int s);

//Feladat: 	A fõprogram gondoskodik a beolvasás, a kiértékelés, kiíratás részek aktivizálásáról.
//Bemenõ adatok:vector<vector<int> > naplo 	- osztályzatokat tartalmazó mátrix
//		        vector<string> tanulo 		- tanulók neveit tartalmazó tömb
//		        vector<string> targy		- tárgyak neveit tartalmazó tömb
//Kimenõ adatok:igen/nem válasz
//Tevékenység:	Eldönti, hogy mi legyen a beolvasás forrása:
//    parancssorban megadott szöveges állomány neve (ez az alapértelmezett, ha megadtuk)
//    vagy menübõl választhatunk a billentyûzet illetve szöveges állomány között.
//    Feltölti a bemenõ változókat: billentyûzetrõl beolvassa a tanulók számát,
//    majd a neveiket, ugyanazt teszi a tantárgyakkal, és beolvassa az egyes osztályzatokat.
//    Ezután meghívja a feladatot megoldó mindenkinek_ket_otos() függvényt.
//    Ennek eredményétõl függõen pozitív vagy negatív választ ír a standard kimenetre.
int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"Hun");

    vector<vector<int> > naplo;
    vector<string>      tanulo;
    vector<string>      targy;
    int n,m;

    // Beolvasás
    int s = 0;
    string fajlnev;
    if (argc<=1) {
        cout << "Válassza ki az adatbevitel módját!\n";
        cout << "1 - adatok beolvasása billentyûzetrõl\n";
        cout << "2 - adatok beolvasása fájlból\n";
        cout << "3 - kilépés\n";
        s = ReadInt("Adatbevitel módja: ","1, 2 vagy 3 lehet", egykettoharom);
    }
    switch (s) {
        case 0:
            fajlnev = argv[1];
            Fajlbol_olvas(fajlnev, tanulo, targy, naplo);
            break;
        case 1:
            n = ReadNat("Hány tanuló van? ", "Természetes számot kérek!");
            cout << "Adja meg a tanulók neveit:" << endl;
            Neveket_olvas(n, "tanuló", tanulo);
            cout << endl;

            m = ReadNat("Hány tantárgy van? ","Természetes számot kérek!");
            cout << "Adja meg a tantárgyakat:"<< endl;
            Neveket_olvas(m, "tantárgy", targy);
            cout << endl;

            cout << "Adja meg az osztályzatokat!"<< endl;
            Jegyeket_olvas(tanulo, targy, naplo);
            cout << endl;
            break;
        case 2:
            cout << "Add meg a fájl nevét: ";
            cin >> fajlnev;
            Fajlbol_olvas(fajlnev, tanulo, targy, naplo);
            break;
        case 3:
            exit(0);
    }

    // Kiértékelés
    if (Mindenkinek_ket_otos(naplo)) {
        cout << "Mindenkinek legalább két ötöse van az osztályban!";
    }
    else {
        cout << "Van olyan az osztályban, akinek nincs két ötöse!";
    }

    cout<<endl;
    return 0;
}

//Feladat: 	Megvizsgálja, hogy mindenkinek van-e legalább két ötöse.
//Bemenõ adatok:vector<vector<int> > naplo  - osztályzatokat tartalmazó mátrix
//Kimenõ adatok:bool 			            - válasz: visszatérési érték
//Tevékenység:	Optimista lineáris keresés: eldönti, hogy a mátrix (osztályzási napló)
//              minden sorának (tanulójának) van-e legalább két ötöse.
//              Ehhez minden sorra meghívja a Jotanulo() függvényt.
bool Mindenkinek_ket_otos(const vector<vector<int> > &naplo)
{
    bool l = true;
    for( int i=0; l && i<(int)naplo.size(); ++i) {
        l = OtosDb(naplo[i])>=2;
    }
    return l;
}

//Feladat: 	Hány ötöse van egy tanulónak.
//Bemenõ adatok:vector<int> v 	- aktuális tanuló osztályzatai
//Kimenõ adatok:int s		    - ötösök száma: visszatérési-érték
//Tevékenység:	Megszámolja az ötösöket.
int OtosDb(const vector<int> &v)
{
    int s = 0;
    for(int j=0; j<(int)v.size(); ++j) {
        if (v[j]==5) ++s;
    }
    return s;
}

//Feladat: 	Nevekkel tölt fel egy tömböt.
//Bemenõ adatok:int n	         - nevek száma
//		        string msg	     - kiírandó üzenet
//Kimenõ adatok:vector<string> v - neveket tartalmazó tömb
//Tevékenység:	Megfelelõ méretûre (n) állítja be a tömböt,
//		majd feltölti az értékeit sztringekkel.
void Neveket_olvas(int n, const string &str, vector<string> &v)
{
    v.resize(n);
    for(int i=0; i<n; ++i)
    {
        cout << i+1 << "." << str << "neve: ";
        cin >> v[i];
    }
}

//Feladat: 	Eldönti egy egész számról, hogy osztályzat-e.
//Bemenõ adatok:int n	- egész szám
//Kimenõ adatok:bool l	- vizsgálat eredménye: visszatérési érték
//Tevékenység:	Eldönti egy egész számról, hogy 1 és 5 közé esik-e.
bool Jegy(int k)
{
    return 1<=k && k<=5;
}

//Feladat: 	1 és 5 közötti számokkal tölt fel egy mátrixot.
//Bemenõ adatok:vector<string> tanulo 		- tanulók neveit tartalmazó tömb
//		        vector<string> targy		- tárgyak neveit tartalmazó tömb
//Kimenõ adatok:vector<vector<int> > naplo 	- osztályzatokat tartalmazó mátrix
//Tevékenység:	Megfelelõ méretûre (tanulo.size×targy.size) állítja be a mátrixot,
//		majd feltölti az értékeit 1 és 5 közötti számokkal úgy, hogy rendre jelzi,
//		hogy ezek a számok melyik tanuló melyik tantárgyára kapott osztályzatok.
void Jegyeket_olvas(const vector<string> &tanulo, const vector<string> &targy, vector<vector<int> > &a)
{
    a.resize((int)tanulo.size());
    for(int i=0; i<(int)tanulo.size(); ++i)
    {
        a[i].resize((int)targy.size());
        cout << tanulo[i] << " eredményei\n";
        for(int j=0; j<(int)targy.size(); ++j)
        {
            cout << "\t" << targy[j] << ": ";
            a[i][j] = ReadInt("","1 és 5 közötti számot kérek!", Jegy);
        }
    }
}

//Feladat: 	Tanuló és tantárgy neveket olvas egy szöveges állományból,
//          majd ugyanonnan 1 és 5 közötti számokkal feltölti a naplót.
//Bemenõ adatok:string fajlnev 		        - inputfájl neve
//Kimenõ adatok:vector<string> tanulo		- tanulok neveit tartalmazó tömb
//              vector<string> targy		- tárgyak neveit tartalmazó tömb
//              vector<vector<int> > naplo 	- osztályzatokat tartalmazó mátrix
//Tevékenység:	Megfelelõ méretûre (n és m) állítja be a tanulo és a targy tömböt,
//		majd feltölti az értékeit sztringekkel. A tanuló neve tartalmazhat szóközt is.
//      Megfelelõ méretûre (n×m) állítja be a naplo mátrixot,
//		majd feltölti az értékeit 1 és 5 közötti számokkal.
//		A beolvasott adatok a konzolablakban is megjelennek.
void Fajlbol_olvas(const string &fajlnev, vector<string> &tanulo, vector<string> &targy, vector<vector<int> > &naplo)
{
    ifstream f(fajlnev.c_str());
    if(f.fail()){
        cout << "Hibás fájlnév!\n";
        exit(1);
    }

    int n, m;
    f >> n >> m;
    string str;
    getline(f, str, '\n');

    cout << "\nTanulók:\n";
    tanulo.resize(n);
    for(int i=0; i<n; ++i)
    {
        getline(f, tanulo[i], '\n');
        cout << tanulo[i] << endl;
    }

    cout << "\nTárgyak:\n";
    targy.resize(m);
    for(int j=0; j<m; ++j)
    {
        f >> targy[j];
        cout << targy[j] << endl;
    }

    cout << "\nNaplo:\n";
    naplo.resize(n);
    for(int i=0; i<(int)tanulo.size(); ++i)
    {
        naplo[i].resize(m);
        cout << tanulo[i] << " eredményei\n";
        for(int j=0; j<(int)targy.size(); ++j)
        {
            f >> naplo[i][j];
            cout << "\t" << targy[j] << ": " << naplo[i][j];
        }
        cout << endl;
    }
}

//Feladat: 	Eldönti egy egész számról, hogy 1, 2 vagy 3 értékû-e.
//Bemenõ adatok:int s	- egész szám
//Kimenõ adatok:bool l	- vizsgálat eredménye: visszatérési érték
//Tevékenység:	Eldönti egy egész számról, hogy 1, 2 vagy 3 értékû-e.
bool egykettoharom(int s)
{
    return s>=1 && s<=3;
}
