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

    //5. VAN-E olyan akinek Gy-vel kezd�dik a neve
    bool l = false;
    int c = 0;
    for(t.First(); !t.End(); t.Next())
    {           // !l egy plusz felt�tel
        Adat e = t.Current();
        if(e.ki == "")
            ++c;
        l |= e.nev.length() > 1 && e.nev.substr(0,2) == "Gy";
    }
    cout << l << endl;
    cout << c << endl;

    return 0;
}
