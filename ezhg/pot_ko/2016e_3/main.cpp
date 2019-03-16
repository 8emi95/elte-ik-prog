/*
mozi, vetítés adatai, szóközök
cím (szóközökkel elválasztva) teremnév (nincs szóköz) kezdete (HH:MM) hely jegytípus (párok) hely jegytípus...
G (gyerek 500)
D (diák 800)
F (felnõtt 1000)
Bla Bla Bla Jancsó 10:15 9 G 3 G 5 F

3as:
cím 1 db hatjegyû azonosító (string)
egyes vetítések összebevétele "idõpont terem bevétel" formában

5ös:
cím többszavas
+ volt-e olyan vetítés amire csak diákok váltottak helyet
*/


#include <iostream>
#include"enor.h"
#include<vector>

using namespace std;

int main()
{
    Enor t("be.txt");
//    for(t.First();!t.End();t.Next())
//    {
//        Adat e = t.Current();
//        cout << e.azon << " " << e.terem << " " << e.ido << " ";
//        for(int i = 0; i < e.jegyek.size(); ++i)
//            cout << e.jegyek[i].hely << " " << e.jegyek[i].tipus << " ";
//        cout << endl;
//    }

    for(t.First();!t.End();t.Next()) //osszegzes
    {
        Adat e = t.Current();
        int ossz = 0;
        for(int i = 0; i < e.jegyek.size(); ++i) //osszegzes
        {
            if(e.jegyek[i].tipus == 'G')
                ossz += 500;
            else if(e.jegyek[i].tipus == 'D')
                ossz += 800;
            else if(e.jegyek[i].tipus == 'F')
                ossz += 1000;
        }
        cout << e.ido << " " << e.terem << " " << ossz << endl;
    }

    return 0;
}
