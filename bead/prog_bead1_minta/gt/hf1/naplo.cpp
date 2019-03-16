//K�sz�tette:    Gregorics Tibor
//D�tum:         2009.01.23.
//eha k�d:       EHACODE.ELTE
//mail:          gt@inf.elte.hu
//csoport:       0.csoport
//Feladat:       Van-e minden tanul�nak legal�bb k�t tant�rgyb�l �t�se


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

//Feladat: 	A f�program gondoskodik a beolvas�s, a ki�rt�kel�s, ki�rat�s r�szek aktiviz�l�s�r�l.
//Bemen� adatok:vector<vector<int> > naplo 	- oszt�lyzatokat tartalmaz� m�trix
//		        vector<string> tanulo 		- tanul�k neveit tartalmaz� t�mb
//		        vector<string> targy		- t�rgyak neveit tartalmaz� t�mb
//Kimen� adatok:igen/nem v�lasz
//Tev�kenys�g:	Eld�nti, hogy mi legyen a beolvas�s forr�sa:
//    parancssorban megadott sz�veges �llom�ny neve (ez az alap�rtelmezett, ha megadtuk)
//    vagy men�b�l v�laszthatunk a billenty�zet illetve sz�veges �llom�ny k�z�tt.
//    Felt�lti a bemen� v�ltoz�kat: billenty�zetr�l beolvassa a tanul�k sz�m�t,
//    majd a neveiket, ugyanazt teszi a tant�rgyakkal, �s beolvassa az egyes oszt�lyzatokat.
//    Ezut�n megh�vja a feladatot megold� mindenkinek_ket_otos() f�ggv�nyt.
//    Ennek eredm�ny�t�l f�gg�en pozit�v vagy negat�v v�laszt �r a standard kimenetre.
int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"Hun");

    vector<vector<int> > naplo;
    vector<string>      tanulo;
    vector<string>      targy;
    int n,m;

    // Beolvas�s
    int s = 0;
    string fajlnev;
    if (argc<=1) {
        cout << "V�lassza ki az adatbevitel m�dj�t!\n";
        cout << "1 - adatok beolvas�sa billenty�zetr�l\n";
        cout << "2 - adatok beolvas�sa f�jlb�l\n";
        cout << "3 - kil�p�s\n";
        s = ReadInt("Adatbevitel m�dja: ","1, 2 vagy 3 lehet", egykettoharom);
    }
    switch (s) {
        case 0:
            fajlnev = argv[1];
            Fajlbol_olvas(fajlnev, tanulo, targy, naplo);
            break;
        case 1:
            n = ReadNat("H�ny tanul� van? ", "Term�szetes sz�mot k�rek!");
            cout << "Adja meg a tanul�k neveit:" << endl;
            Neveket_olvas(n, "tanul�", tanulo);
            cout << endl;

            m = ReadNat("H�ny tant�rgy van? ","Term�szetes sz�mot k�rek!");
            cout << "Adja meg a tant�rgyakat:"<< endl;
            Neveket_olvas(m, "tant�rgy", targy);
            cout << endl;

            cout << "Adja meg az oszt�lyzatokat!"<< endl;
            Jegyeket_olvas(tanulo, targy, naplo);
            cout << endl;
            break;
        case 2:
            cout << "Add meg a f�jl nev�t: ";
            cin >> fajlnev;
            Fajlbol_olvas(fajlnev, tanulo, targy, naplo);
            break;
        case 3:
            exit(0);
    }

    // Ki�rt�kel�s
    if (Mindenkinek_ket_otos(naplo)) {
        cout << "Mindenkinek legal�bb k�t �t�se van az oszt�lyban!";
    }
    else {
        cout << "Van olyan az oszt�lyban, akinek nincs k�t �t�se!";
    }

    cout<<endl;
    return 0;
}

//Feladat: 	Megvizsg�lja, hogy mindenkinek van-e legal�bb k�t �t�se.
//Bemen� adatok:vector<vector<int> > naplo  - oszt�lyzatokat tartalmaz� m�trix
//Kimen� adatok:bool 			            - v�lasz: visszat�r�si �rt�k
//Tev�kenys�g:	Optimista line�ris keres�s: eld�nti, hogy a m�trix (oszt�lyz�si napl�)
//              minden sor�nak (tanul�j�nak) van-e legal�bb k�t �t�se.
//              Ehhez minden sorra megh�vja a Jotanulo() f�ggv�nyt.
bool Mindenkinek_ket_otos(const vector<vector<int> > &naplo)
{
    bool l = true;
    for( int i=0; l && i<(int)naplo.size(); ++i) {
        l = OtosDb(naplo[i])>=2;
    }
    return l;
}

//Feladat: 	H�ny �t�se van egy tanul�nak.
//Bemen� adatok:vector<int> v 	- aktu�lis tanul� oszt�lyzatai
//Kimen� adatok:int s		    - �t�s�k sz�ma: visszat�r�si-�rt�k
//Tev�kenys�g:	Megsz�molja az �t�s�ket.
int OtosDb(const vector<int> &v)
{
    int s = 0;
    for(int j=0; j<(int)v.size(); ++j) {
        if (v[j]==5) ++s;
    }
    return s;
}

//Feladat: 	Nevekkel t�lt fel egy t�mb�t.
//Bemen� adatok:int n	         - nevek sz�ma
//		        string msg	     - ki�rand� �zenet
//Kimen� adatok:vector<string> v - neveket tartalmaz� t�mb
//Tev�kenys�g:	Megfelel� m�ret�re (n) �ll�tja be a t�mb�t,
//		majd felt�lti az �rt�keit sztringekkel.
void Neveket_olvas(int n, const string &str, vector<string> &v)
{
    v.resize(n);
    for(int i=0; i<n; ++i)
    {
        cout << i+1 << "." << str << "neve: ";
        cin >> v[i];
    }
}

//Feladat: 	Eld�nti egy eg�sz sz�mr�l, hogy oszt�lyzat-e.
//Bemen� adatok:int n	- eg�sz sz�m
//Kimen� adatok:bool l	- vizsg�lat eredm�nye: visszat�r�si �rt�k
//Tev�kenys�g:	Eld�nti egy eg�sz sz�mr�l, hogy 1 �s 5 k�z� esik-e.
bool Jegy(int k)
{
    return 1<=k && k<=5;
}

//Feladat: 	1 �s 5 k�z�tti sz�mokkal t�lt fel egy m�trixot.
//Bemen� adatok:vector<string> tanulo 		- tanul�k neveit tartalmaz� t�mb
//		        vector<string> targy		- t�rgyak neveit tartalmaz� t�mb
//Kimen� adatok:vector<vector<int> > naplo 	- oszt�lyzatokat tartalmaz� m�trix
//Tev�kenys�g:	Megfelel� m�ret�re (tanulo.size�targy.size) �ll�tja be a m�trixot,
//		majd felt�lti az �rt�keit 1 �s 5 k�z�tti sz�mokkal �gy, hogy rendre jelzi,
//		hogy ezek a sz�mok melyik tanul� melyik tant�rgy�ra kapott oszt�lyzatok.
void Jegyeket_olvas(const vector<string> &tanulo, const vector<string> &targy, vector<vector<int> > &a)
{
    a.resize((int)tanulo.size());
    for(int i=0; i<(int)tanulo.size(); ++i)
    {
        a[i].resize((int)targy.size());
        cout << tanulo[i] << " eredm�nyei\n";
        for(int j=0; j<(int)targy.size(); ++j)
        {
            cout << "\t" << targy[j] << ": ";
            a[i][j] = ReadInt("","1 �s 5 k�z�tti sz�mot k�rek!", Jegy);
        }
    }
}

//Feladat: 	Tanul� �s tant�rgy neveket olvas egy sz�veges �llom�nyb�l,
//          majd ugyanonnan 1 �s 5 k�z�tti sz�mokkal felt�lti a napl�t.
//Bemen� adatok:string fajlnev 		        - inputf�jl neve
//Kimen� adatok:vector<string> tanulo		- tanulok neveit tartalmaz� t�mb
//              vector<string> targy		- t�rgyak neveit tartalmaz� t�mb
//              vector<vector<int> > naplo 	- oszt�lyzatokat tartalmaz� m�trix
//Tev�kenys�g:	Megfelel� m�ret�re (n �s m) �ll�tja be a tanulo �s a targy t�mb�t,
//		majd felt�lti az �rt�keit sztringekkel. A tanul� neve tartalmazhat sz�k�zt is.
//      Megfelel� m�ret�re (n�m) �ll�tja be a naplo m�trixot,
//		majd felt�lti az �rt�keit 1 �s 5 k�z�tti sz�mokkal.
//		A beolvasott adatok a konzolablakban is megjelennek.
void Fajlbol_olvas(const string &fajlnev, vector<string> &tanulo, vector<string> &targy, vector<vector<int> > &naplo)
{
    ifstream f(fajlnev.c_str());
    if(f.fail()){
        cout << "Hib�s f�jln�v!\n";
        exit(1);
    }

    int n, m;
    f >> n >> m;
    string str;
    getline(f, str, '\n');

    cout << "\nTanul�k:\n";
    tanulo.resize(n);
    for(int i=0; i<n; ++i)
    {
        getline(f, tanulo[i], '\n');
        cout << tanulo[i] << endl;
    }

    cout << "\nT�rgyak:\n";
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
        cout << tanulo[i] << " eredm�nyei\n";
        for(int j=0; j<(int)targy.size(); ++j)
        {
            f >> naplo[i][j];
            cout << "\t" << targy[j] << ": " << naplo[i][j];
        }
        cout << endl;
    }
}

//Feladat: 	Eld�nti egy eg�sz sz�mr�l, hogy 1, 2 vagy 3 �rt�k�-e.
//Bemen� adatok:int s	- eg�sz sz�m
//Kimen� adatok:bool l	- vizsg�lat eredm�nye: visszat�r�si �rt�k
//Tev�kenys�g:	Eld�nti egy eg�sz sz�mr�l, hogy 1, 2 vagy 3 �rt�k�-e.
bool egykettoharom(int s)
{
    return s>=1 && s<=3;
}
