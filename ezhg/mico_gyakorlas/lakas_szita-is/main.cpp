#include <iostream>
#include "felsorolo.h"

using namespace std;

int main()
{
    Felsorolo t("input.txt");
     Struktura e;


    int osszes=0;
    int kell=0;
    int max=0;
    string max_azon;

    bool all_payed=true;

    for(t.First();!t.End();t.Next())
    {
        e=t.Current();

        if (!e.becsulet) all_payed=false;

        osszes+=e.osszeg;
        kell+=e.bef_ossz;
        if (max<e.bef_ossz)
        {
            e.bef_ossz=max;
            max_azon=e.azon;
        }
    }

    cout << "Hatralevo befizetendo oszeg: "<< osszes-kell<< endl;
    cout << "Legtobbet fizetett be: "<< max_azon<< endl;
    if(all_payed) cout << "Mindenki befizetett mindent. "; else cout << "Nem fizetettek be mindent. ";
}
