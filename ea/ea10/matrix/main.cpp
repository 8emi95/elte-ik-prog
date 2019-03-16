//Készítette:    Gregorics Tibor
//Dátum:         2015.02.22.
//Feladat:       Kiválasztás egy végtelen "mátrix" bejárásával

#include <iostream>
#include "read.hpp"

using namespace std;

double f(int i) { return i*i;}
double g(int j) { return j*j;}

// Típusérték:      egész számpárok sorozata
// Reprezentáció:   egész számpárok (i,j) és az összegük (k)
// Mûveletek:       first(), next(), current()  - felsoroló mûveletek
class Enor{
public:
    struct Pair{ int i; int j;};

    void first(){ cur.i = cur.j = 0; }
    void next() { if (cur.i>0) {--cur.i; ++cur.j;} else {cur.i=cur.j+1; cur.j=0;} }
    Pair current() const { return cur;}
private:
    Pair cur;
};

bool all(double r){ return true; }

//Feladat: 	        Adottak az f,g : N -> R függvények és az e valós szám.
//                  Tudjuk, hogy van olyen i,j egész, amelyre f(i)+g(j)==e.
//                  Keressünk ilyen i,j egészt!
//Bemenõ adatok:    double e - keresett érték
//Kimenõ adatok:    int i, j - azon indexek, ahol f(i)+g(j)==e
//Tevékenység:	    Beolvassa a keresett valós számot,
//                  kétféleképpen felsorolja a lehetséges i, j index párokat,
//		            vizsgálja az f(i)+g(j)==e összefüggést, és az elsõ egyezésnél megáll.
int main()
{
    double e = read<double>("Keresett ertek: ", "Valos szamot varok!", all);

// első változat

    Enor t;
    for( t.first() ; f(t.current().i)+g(t.current().j)!=e; t.next() );

    cout << "A keresett elem az f(" << t.current().i << ")+g(" << t.current().j << ") osszeggel azonos\n";

// második változat

    int i, j;
    for(i = j = 0; f(i)+g(j)!=e; ){
        if(i>0) { --i; ++j;} else { i = j+1; j = 0;}
    }

    cout << "A keresett elem az f(" << i << ")+g(" << j << ") osszeggel azonos\n";

    return 0;
}

