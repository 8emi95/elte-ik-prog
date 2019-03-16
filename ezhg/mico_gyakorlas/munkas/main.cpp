/*
Adottak az építõiparban dolgozó munkások névsora és a munkások fizetéseik. A nevek mellet fel van tüntetve, hogy
melyik munkás, mikor, és mennyi fizetést kapott.
Feladat:
I.: Kilistázni, az adott munkások összesen mennyi fizetést kapott, és mikor kapott utoljára fizetést!
II. Listázza ki , a munkások közül mennyi volt a legkevesebb fizetés ebben az évben!
*/
#include <iostream>
#include "felsorolo.h"

using namespace std;
void kiiras(vector <string> v);

int main()
{
    Felsorolo t("input.txt");
    Struktura e;
    int min;
    bool l=false;


    for(t.First();!t.End(); t.Next())
    {
        //nevek , összegek listázása
         e=t.Current();
        if(!l)
        {
            min=e.osszeg;
            l=true;
        }

        kiiras(e.nev);
        cout << e.osszeg <<" HUF"<<" "<<e.last_date <<endl;
            if(min>e.osszeg)
            {
                min=e.osszeg;
            }
    }
    cout<<endl;
    cout<<"------------------EREDMENYEK------------------------"<<endl;
    cout<<"Ennyi volt a legkevesebb keresettel rendelkezo ember osszbere:"<<'\t'<<min<<" HUF"<<endl;

    return 0;
}
void kiiras(vector <string> v)
{
    for (int i=0; i<(int)v.size(); i++)
    {
        cout << v[i] << " ";
    }
}
