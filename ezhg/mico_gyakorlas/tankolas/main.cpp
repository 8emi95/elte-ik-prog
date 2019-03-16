#include <iostream>
#include "felsorolo.h"
using namespace std;

int main()
{
    Felsorolo t("input.txt");

    int max=0;
    string rendszam;
    for (t.First(); !t.End(); t.Next())
    {
            if (t.Current().hanyszor>max)
            {
                max=t.Current().hanyszor;
                rendszam=t.Current().rendszam;
            }
            if (t.Current().osszeg>300)
            {
                cout <<"300 liternel többet tankolt: " << t.Current().rendszam << endl;
            }
    }

    cout <<"Legtobbszor tankolt: " <<rendszam;

    return 0;
}
