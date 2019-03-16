#include <iostream>
#include"enor.h"
//potencialisan mast is be kellhet include-olni...

//HÁRMAS SZINT
//5: két tétel párhuzamos, felsoroló máshogy mûködjön (12. gyak),

using namespace std;

bool nincs10milka(const vector<int> &v);

int main()
{
    Enor t("be.txt");
//    for(t.First();!t.End();t.Next())
//    {
//        cout << t.Current().iparag << " ";
//        for(size_t i = 0; i < t.Current().keruletek.size(); ++i)
//            cout << t.Current().keruletek[i] << " ";
//        cout << t.Current().konk << endl;
//
//        //A rekord adattagjainak kiirkalasa.
//        //Bar ez sose a feladat resze, de addig ne kezdj tetelezni, amig nem gyozodtel meg arrol, hogy a felsorolod jo.
//        //Ha kesz vagy, es minden jo, ezt a ciklusd kommenteld ki / torold ki, mert ha ez felsorolja t.End()-ig a file-t, akkor a teteles ciklus mar nem fog tudni semmit se felsorolni...
//    }
//KOMMENTELJÜK KI MINDENKÉPP - nevezetes felsorolósnál(?)

    //linker
    //van-e no konk + nyereség < 10 mindenhol, ha igen akk melyik
    bool van = false;
    Adat elem; //elemet is vissza kell adni
    for(t.First(); !van && !t.End(); t.Next())
    {
        //Tetel(ek) elvegzese, esetleges belso fuggvenyek meghivasaval, amit ebben a fajlban definialhatunk
        elem = t.Current();
        van = t.Current().konk == "nincs" && nincs10milka(t.Current().keruletek);
    }

    //Tetel eredmenyetol fuggo kiiras
    if(van)
        cout << t.Current().iparag << endl;
    else
        cout << "Nincs." << endl;

    return 0;
}

bool nincs10milka(const vector<int> &v)
{
    bool nincs = true;
    for(size_t i = 0; nincs && i <v.size(); ++i) //nincs && nélkül végigmegy az intervallumon, amit utoljára ad az lesz
        nincs = v[i] < 10;
    return nincs;
}
