/*
Adottak az �p�t�iparban dolgoz� munk�sok n�vsora �s a munk�sok fizet�seik. A nevek mellet fel van t�ntetve, hogy
melyik munk�s, mikor, �s mennyi fizet�st kapott.
Feladat:
I.: Kilist�zni, az adott munk�sok �sszesen mennyi fizet�st kapott, �s mikor kapott utolj�ra fizet�st!
II. List�zza ki , a munk�sok k�z�l mennyi volt a legkevesebb fizet�s ebben az �vben!
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
        //nevek , �sszegek list�z�sa
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
