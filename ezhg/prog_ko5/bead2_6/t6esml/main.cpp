#include <iostream>
#include"enor.h"

using namespace std;

int main()
{
    Enor t("be.txt");
    //ellen�rz� ki�r�st t�r�lj�k v kommentezz�k majd
//    for(t.First();!t.End();t.Next())
//    {
//        Adat e = t.Current();
//        cout << e.be << " " << e.nev << " " << e.azon << " " << e.ki << endl; //structot meg kell �rni hozz�
//    }

    //linker + vmi p�rhuzamosan

    //4. elso olyan akinek Gy-vel kezd�dik a neve
    bool l = false;
    Adat elem;
    int c = 0; //2.-hoz
    //t.First(); //while-hoz
    for(t.First(); !l && !t.End(); t.Next()) //while(!l && !t.End())
    {           // !l egy plusz felt�tel
        Adat e = t.Current();

        //2. sz�molja meg azokat a szem�lyeket akik bel�ptek, de m�g nem j�ttek ki
        if(e.ki == "")
            ++c;

        //4. elso olyan akinek Gy-vel kezd�dik a neve
        l = e.nev.length() > 1 && e.nev.substr(0,2) == "Gy"; //beta(e), substr nem m�dos�tja csak visszaadja, "Gy" a bal oldalon legyen
        //l = e.nev.length() > 1 && e.nev[0] == 'G' && e.nev[1] == 'y'; //uaz
        elem = e;
        //t.Next(); //while-hoz kell csak, for ++ r�sze
    }
    for(; !t.End(); t.Next())
    {
        Adat e = t.Current();

        //2. sz�molja meg azokat a szem�lyeket akik bel�ptek, de m�g nem j�ttek ki
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
//        //2. sz�molja meg azokat a szem�lyeket akik bel�ptek, de m�g nem j�ttek ki
//        if(e.ki == "")
//            ++c;
//
//        //3. h�ny db olyan aki m�g nem ment ki + ki j�tt meg leghamarabb (.be legkisebb)
//        string min = t.Current().be;
//        Adat elem = t.Current(); //elem t�pus az absztrakt t�telben
//        //t.Next(); //ezt a for 1. param�ter�be
//        for(t.Next(); !t.End();t.Next()) //3. miatt first�t kirakom
//        {
//            Adat e = t.Current(); //h ne kelljen sokat �rni
////            //1. hib�s sorok (k�s�bb van a kil�p�s mint a bel�p�s) kilist�z�sa - �sszegz�s //3. n�lk�l j� csak ilyen form�ban
////            if(e.be > e.ki && e.ki != "") //egyenl� nem hib�s, e.ki nem biztos h van
////                cout << e.be << " " << e.nev << " " << e.azon << " " << e.ki << endl;
//
//            //2. sz�molja meg azokat a szem�lyeket akik bel�ptek, de m�g nem j�ttek ki
//            if(e.ki == "")
//                ++c;
//
//            //ha a 2 t�tel nem azonos alak�...
//            //3. h�ny db olyan aki m�g nem ment ki + ki j�tt meg leghamarabb (.be legkisebb)
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
