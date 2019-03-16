//Készítette:    Gregorics Tibor
//Dátum:         2010.02.14.
//Feladat:       Legtöbb fogú rossz fogazatú páciens keresése

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

void fill(vector<int> &t);
bool condMaxSearch(const vector<int> &t, int &min, int &ind);

//Feladat:       Szöveges fájlból feltöltött egész számokat tartalmazó tömb
//               legnagyobb 12-nél kisebb számának keresése
//Bemenõ adatok: szöveges állomány	- nyilvántartás (darabszám, majd a páciensek fogainak száma)
//Kimenõ adatok: bool l             - van-e 12-nél kevesebb fogú páciens
//               int min            - legnagyobb 12-nél kisebb fogszám
//               int ind            - legnagyobb 12-nél kisebb fogszámú páciens sorszáma
//Tevékenység:	 Cikliskusan ismételve
//               megnyitja a szöveges fájlt,
//               onnan beolvassa a páciensek darabszámát,
//               majd a fogaik számával feltölt egy tömböt,
//               kiírja, hogy van-e 12-nél kevesebb fogú páciens, és
//               ha igen, akkor a legtöbb ilyen fogú páciens sorszámát és fogszámát is.

int  main()
{
    cout << "Megkeresem egy szoveges fajlbeli fogorvosi nyilvantartasban \n\
(ahol a paciensek fogainak szamat taroljuk) a legnagyobb 12-nel kisebb szamot.\n\n";

    char ch;
    do{
    //Adatok beolvasása
        vector<int> t;
        fill(t);

    // Kiértékelés
        int max, ind;
        if(condMaxSearch(t,max,ind)) cout << "A legtobb,de 12-nel kevesebb, fogu paciens sorszama: "<< ind+1 << endl
                 << "akinek " << max <<" darab foga van"<< endl;
        else  cout <<"Nincs rossz (12-nél kevesebb) fogu  paciens!";

        cout << endl << "Futtassam ujra? (I/N)"; cin >> ch;
    }while( ch!='n' && ch!='N');

    return 0;
}

//Feladat: 	     tömb feltöltése szöveges állományból
//Bemenõ adatok:
//Kimenõ adatok: vector<int> t	- egész számok tömbje
//Tevékenység:   Megkérdezi a szöveges állomány nevét, megnyitja olvasásra
//               beolvassa az elsõ adatot (tömb elemszáma), beállítja a tömb hosszát,
//               majd beolvassa a tömb elemeit
void fill(vector<int> &t)
{
    ifstream f;
    bool hiba;
    string str;
    do{
        cout << "Fajl neve:";
        cin >> str;
        f.open( str.c_str() );
        if ( (hiba = f.fail()) ){
            cout << "Nincs ilyen nevu fajl" << endl;
            f.clear();
        }
    }while (hiba);

    int n;
    f >> n;

    t.resize(n);
    for(int i=0; i<n; ++i){
        f >> t[i];
    }
    f.close();
}

//Feladat: 	     Legnagyobb, de 12-nél kisebb szám keresése egész számok tömbjében
//Bemenõ adatok: vector<int> t	- egész számok tömbje
//Kimenõ adatok: bool l         - van-e 12-nél kisebb szám a tömbben : visszatérési érték
//               int min        - legnagyobb 12-nél kisebb szám a tömbben
//               int ind        - legnagyobb 12-nél kisebb szám indexe a tömbben
//Tevékenység:   Megkeresi, hogy van-e 12-nél kisebb szám a tömbben, és ha igen, akkor megadja
//               a legnagyobb ilyet az indexével.
bool condMaxSearch(const vector<int> &t, int& max, int& ind)
{
    bool l = false;
    for(int i=0; i<(int)t.size(); ++i){
        if (t[i]>=12) continue;
        if(l){
            if(t[i]>max){
               max = t[i]; ind = i;
            }
        }else {
            l = true; max = t[i]; ind = i;
        }
    }
    return l;
}

