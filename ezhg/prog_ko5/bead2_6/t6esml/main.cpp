#include <iostream>
#include"enor.h"

using namespace std;

int main()
{
    Enor t("be.txt");
    //ellenõrzõ kiírást töröljük v kommentezzük majd
//    for(t.First();!t.End();t.Next())
//    {
//        Adat e = t.Current();
//        cout << e.be << " " << e.nev << " " << e.azon << " " << e.ki << endl; //structot meg kell írni hozzá
//    }

    //linker + vmi párhuzamosan

    //4. elso olyan akinek Gy-vel kezdõdik a neve
    bool l = false;
    Adat elem;
    int c = 0; //2.-hoz
    //t.First(); //while-hoz
    for(t.First(); !l && !t.End(); t.Next()) //while(!l && !t.End())
    {           // !l egy plusz feltétel
        Adat e = t.Current();

        //2. számolja meg azokat a személyeket akik beléptek, de még nem jöttek ki
        if(e.ki == "")
            ++c;

        //4. elso olyan akinek Gy-vel kezdõdik a neve
        l = e.nev.length() > 1 && e.nev.substr(0,2) == "Gy"; //beta(e), substr nem módosítja csak visszaadja, "Gy" a bal oldalon legyen
        //l = e.nev.length() > 1 && e.nev[0] == 'G' && e.nev[1] == 'y'; //uaz
        elem = e;
        //t.Next(); //while-hoz kell csak, for ++ része
    }
    for(; !t.End(); t.Next())
    {
        Adat e = t.Current();

        //2. számolja meg azokat a személyeket akik beléptek, de még nem jöttek ki
        if(e.ki == "")
            ++c;
    }
    cout << c << endl;
    if(l)
    {
        cout << elem.nev << " az elso Gy-vel kezdodo." << endl;
    }
    else
        cout << "Nincs ilyen nev." << endl;


//    t.First();
//    if(!t.End())
//    {
//        Adat e = t.Current();
//
//        //2. számolja meg azokat a személyeket akik beléptek, de még nem jöttek ki
//        if(e.ki == "")
//            ++c;
//
//        //3. hány db olyan aki még nem ment ki + ki jött meg leghamarabb (.be legkisebb)
//        string min = t.Current().be;
//        Adat elem = t.Current(); //elem típus az absztrakt tételben
//        //t.Next(); //ezt a for 1. paraméterébe
//        for(t.Next(); !t.End();t.Next()) //3. miatt firstöt kirakom
//        {
//            Adat e = t.Current(); //h ne kelljen sokat írni
////            //1. hibás sorok (késõbb van a kilépés mint a belépés) kilistázása - összegzés //3. nélkül jó csak ilyen formában
////            if(e.be > e.ki && e.ki != "") //egyenlõ nem hibás, e.ki nem biztos h van
////                cout << e.be << " " << e.nev << " " << e.azon << " " << e.ki << endl;
//
//            //2. számolja meg azokat a személyeket akik beléptek, de még nem jöttek ki
//            if(e.ki == "")
//                ++c;
//
//            //ha a 2 tétel nem azonos alakú...
//            //3. hány db olyan aki még nem ment ki + ki jött meg leghamarabb (.be legkisebb)
//            if(t.Current().be < min)
//            {
//                min = t.Current().be;
//                elem = t.Current();
//            }
//        }
//        cout << elem.nev << " jott leghamarabb." << endl;
//    }
//    else
//    {
//        cout << "Ures fajl. Nincs ertelme minimumot kivalasztani" << endl;
//    }
//    cout << c;

    return 0;
}
