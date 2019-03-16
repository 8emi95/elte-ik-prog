#include <iostream>
#include"enor.h"
//potencialisan mast is be kellhet include-olni...

using namespace std;

int main()
{
    Enor t("be.txt");
    for(t.First();!t.End();t.Next())
    {
        Adat a=t.Current();
        cout << a.abc << " ";
        for (size_t i=0; i<a.bcd.size(); i++)
        {
            cout << a.bcd[i] << " ";
        }
        cout << endl;
        for (size_t i=0; i<t.Current().cde.size(); i++)
        {
            cout << t.Current().cde[i] << " ";
        }
        cout << endl;
//        //cout<<t.Current().valami ... stb.
//        //A rekord adattagjainak kiirkalasa.
//        //Bar ez sose a feladat resze, de addig ne kezdj tetelezni, amig nem gyozodtel meg arrol, hogy a felsorolod jo.
//        //Ha kesz vagy, es minden jo, ezt a ciklusd kommenteld ki / torold ki, mert ha ez felsorolja t.End()-ig a file-t, akkor a teteles ciklus mar nem fog tudni semmit se felsorolni...
    }

    for(t.First();!t.End();t.Next())
    {
        //Tetel(ek) elvegzese, esetleges belso fuggvenyek meghivasaval, amit ebben a fajlban definialhatunk
    }

    //Tetel eredmenyetol fuggo kiiras

    return 0;
}
