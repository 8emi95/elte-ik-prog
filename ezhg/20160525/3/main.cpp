#include <iostream>
#include"enor.h"
#include<vector>

using namespace std;

/* ProgC ÉZH 2016.05.25. D csoport
utazás: azonosító (8 jegyû szám), idõ (HH:MM) - járat (string) pár
üres + nem létezõ fájl kezelése
egyszer nyissa meg
progtétel - feltüntetni kommentben
fájl sorainak számától függõ méretû adatot NEM lehet !!!!!
osztály olvasáshoz
*/

string minPerUtas(Adat e);

int main()
{
    Enor t("be.txt");
//    for(t.First();!t.End();t.Next())
//    {
//        Adat e = t.Current();
//        cout << e.azon << " ";
//        for(int i = 0; i < e.idojarat.size(); ++i)
//            cout << e.idojarat[i].ido << " " << e.idojarat[i].jarat << " ";
//        cout << endl;
//    }

    //megfelelt: legkorábbi - ki, mikor
    t.First();
    if(!t.End())
    {
        string minIdo = minPerUtas(t.Current());
        Adat minKi = t.Current();
        for(t.Next();!t.End();t.Next())
        {
            Adat e = t.Current();
            if(minPerUtas(e) < minIdo) //maxkiv minimumra
            {
                minIdo = minPerUtas(e);
                minKi = e;
            }
        }
        cout << minKi.azon << " " << minIdo << endl;
    }
    else
        cout << "Ures fajl." << endl;


    return 0;
}

string minPerUtas(Adat e)//maxkiv minimumra
{
    string min = e.idojarat[0].ido;
    for(int i = 1; i < e.idojarat.size(); ++i)
    {
        if(e.idojarat[i].ido < min)
            min = e.idojarat[i].ido;
    }
    return min;
}
