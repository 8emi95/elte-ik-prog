#include "felsorolo.h"
#include <iostream>

using namespace std;

void writeVectorKor(vector <Korido> v);

int main()
{
    Felsorolo t("be.txt");
    Struktura tmp;

    string min="99:99:999";

    clog<< "Gyorsulok:\n";
    for (t.First(); !t.End(); t.Next())
    {
       tmp=t.Current();
       /*clog << tmp.nev << " "<< tmp.csapat<< " ";
       writeVectorKor(tmp.korido);*/

       if (tmp.gyorsul)
        cout << tmp.nev<< endl;

       for (int i=0; i<(int)tmp.korido.size(); i++)
        {
           if (tmp.korido[i].ido<=min)
           {
               min=tmp.korido[i].ido;
           }
        }

    }
    cout << "Leggyorsabb korido: "<< min;

}

void writeVectorKor(vector <Korido> v)
{
    for (int i=0; i<(int)v.size(); i++)
    {
        clog << v[i].kor << " " << v[i].ido;
    }clog << endl;
}
