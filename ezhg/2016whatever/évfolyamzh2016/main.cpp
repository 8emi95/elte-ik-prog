#include <iostream>
#include <cstdlib>
#include "felsorolo.h"

using namespace std;

/*
Az input fájlban kutyanevek (több stringbõl áll), chipszám(integer), aztán szorzó és pontszám párok(integer).
Az összpontszám kiszámolása: a szorzók és pontszámok szorzatának összege.
Példa:
    Simafülû Kis Pacsi 12345678 4 1 4 3 4 2 4 4 4 5 (összpontszám: 60)
    Vadász Néró 87654321 4 3 4 2 4 0 4 1 4 3 (összpontszám: 0)
    Szimat Blöki 22222222 4 5 4 5 4 5 4 5 4 5 (összpontszám: 100)
---------------------------------------------------------------------------------------------------------------------------
A feladat:
    3-masért:
        Az inputban nincsen benne a kutya neve, csak az azonosító és a szorzó, pontszám pár.
        Listázd ki azokat a kutyákat és chipszámukat, akik átmentek a vizsgán, vagyis az összpontszámuk nem 0.
    5-ösért:
        Az inputban benne van a kutya neve, az azonosító és a szorzó, pontszám pár.

----------------------------------------------------------------------------------------------------------------------------------------------

B feladat:
    3-masért:
        Az inputban nincsen benne a kutya neve, csak az azonosító és a szorzó, pontszám pár.
        Listázd ki azokat a kutyákat és chipszámukat, akik megbuktak a vizsgán, vagyis az összpontszámuk 0.
    5-ösért
        Az inputban benne van a kutya neve, az azonosító és a szorzó, pontszám pár.
        Hány kutya ért el I. helyet (összponja több, mint 85), és hány kutya ért el II. helyet (összpontja több mint 70).

A program elégítse ki az alábbi követelményeket:
-	az érvényes tesztesetekre helyesen mûködik a programja (itt felteheti, hogy az állomány minden sora a megadott módon van kitöltve,
    valamint a nem létezõ fájl esetét is lekezeli;
-	a program ciklusai tanult programozási tételekbõl származnak;
-	a szöveges állományt csak egyszer nyitja meg olvasásra;
-	nem használhat a szöveges állomány sorainak számától függõ méretû adatot (tömböt, sztringet);
-	egy osztályt készít a szöveges állomány sorainak olvasásához.

*/

int main()
{
    //setlocale(LC_ALL, ""); a konzolra kiírja az ékezetes karaktereket (nem mindig működik sajnos)
    string fajlnev;
    felsorolo t(fajlnev);

    int elsohely = 0;
    int masodikhely = 0;

    t.First();
    while(!t.End())
    {
        //A feladatsor, 3-masért
        //ha nem a nextben csinálod meg az összpontszámot akkor itt kell
        if(t.Current().osszpontszam > 0) //kiválogatás
        {
            cout << "Atment a vizsgan: " << t.Current().nev << " " << t.Current().chipszam << endl;
        }


//---------------------------------------------------------------------------------------------------------------------------------------------------

        //B feladatsor, 3-masért
        //ha nem a nextben csinálod meg az összpontszámot akkor itt kell
        if(t.Current().osszpontszam == 0) //kiválogatás
        {
            cout << "Megbukott a vizsgan: " << t.Current().nev << " " << t.Current().chipszam << endl;
        }

        //B feladatsor, 5-ösért
        //ki kell kötni hogy az első hely pontszámánál kisebb, mert pl a 100 pontot mindkettőbe beleszámolja, mert mindkét feltételt teljesíti
        if(t.Current().osszpontszam > 70 && t.Current().osszpontszam < 85) //számlálás
        {
            masodikhely += 1;
        }
        if(t.Current().osszpontszam > 85) //számlálás2
        {
            elsohely += 1;
        }

        t.Next();
    }
    cout << endl;
    cout << "Elso helyezest ert el: " << elsohely << " kutya" << endl;
    cout << "Masodik helyezest ert el: " << masodikhely << " kutya" << endl;

    return 0;

}
