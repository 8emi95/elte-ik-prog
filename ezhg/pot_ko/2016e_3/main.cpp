/*
mozi, vet�t�s adatai, sz�k�z�k
c�m (sz�k�z�kkel elv�lasztva) teremn�v (nincs sz�k�z) kezdete (HH:MM) hely jegyt�pus (p�rok) hely jegyt�pus...
G (gyerek 500)
D (di�k 800)
F (feln�tt 1000)
Bla Bla Bla Jancs� 10:15 9 G 3 G 5 F

3as:
c�m 1 db hatjegy� azonos�t� (string)
egyes vet�t�sek �sszebev�tele "id�pont terem bev�tel" form�ban

5�s:
c�m t�bbszavas
+ volt-e olyan vet�t�s amire csak di�kok v�ltottak helyet
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
