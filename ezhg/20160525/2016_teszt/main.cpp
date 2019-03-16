#include <iostream>
#include"enor.h"
//potencialisan mast is be kellhet include-olni...

using namespace std;

int main()
{
    Enor t("be.txt");
//    for(t.First();!t.End();t.Next())
//    {
//        Adat e = t.Current();
//        cout << e.azon << " " << e.ido << " " << e.jarat << endl;
//        //A rekord adattagjainak kiirkalasa.
//        //Bar ez sose a feladat resze, de addig ne kezdj tetelezni, amig nem gyozodtel meg arrol, hogy a felsorolod jo.
//        //Ha kesz vagy, es minden jo, ezt a ciklusd kommenteld ki / torold ki, mert ha ez felsorolja t.End()-ig a file-t, akkor a teteles ciklus mar nem fog tudni semmit se felsorolni...
//    }

    int c = 0;
    for(t.First();!t.End();t.Next())
    {
        Adat e = t.Current();
        //HÁNY utas utazott csak 7E-val
        bool l = true;
        for(t.First();l && !t.End();t.Next())
        {
            l = e.jarat == "7E";
        }
         cout << "csak 7eeee: " << l << " " << e.azon << endl;
    }
//    cout << "csak 7e: " << l << " " << t.Current.azon << endl;
    //Tetel eredmenyetol fuggo kiiras

    return 0;
}

bool csak7e(Elem e)
{
    bool l = true;
    for(int i = 0; l && !)
}
