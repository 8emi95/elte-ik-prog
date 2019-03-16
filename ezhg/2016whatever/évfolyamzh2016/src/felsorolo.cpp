#include "felsorolo.h"
#include <sstream>
#include <iostream>
#include <cstdlib>

using namespace std;

felsorolo::felsorolo(string fajlnev)
{
    do{
        cout << "Kerem a fajl nevet!" << endl;
        cin >> fajlnev;
        x.open(fajlnev.c_str());
        if(x.fail())
        {
            cout << "Nincs ilyen fajl!" << endl;
        }
    }while(x.fail());
}

bool felsorolo::End()
{
    return !sx;
}

void felsorolo::First()
{
    Next();
}

kutya felsorolo::Current()
{
    return dx;
}

void felsorolo::Next()
{
//adatok beolvasása (több striges név, chipszám, szorzó, pontszám)---------------------------------------------------------------------------------
    string sor;
    stringstream s;
    string tmpnev;
    getline(x, sor);

    //---------------------------------------------------------------------------------------------------------------------------------------------
    //ha végig megy a getline, akkor a végén még nem váltott az sx abnormra, és a getline bevesz egy üres sort. ezzel nem is lenne gond,
    //de az atoi az ""-re 0-t dob vissza, tehát lesz egy fölösleges 0 a beolvasás végén, ami esetleg ha azonosítót kell vizsgálni, gondot okozhat.
    //így viszont ha üres sort kap a getline, akkor az sx-et abnorm-ra(false) teszi, és nem lesz benne a fölös 0
    if(sor.empty()) {
        sx = false;
        return;
    }
    //---------------------------------------------------------------------------------------------------------------------------------------------
    s.str("");
    s.clear();
    s << sor;
    dx.nev = "";
    tmpnev = "";
    s >> tmpnev;

    while(!s.eof() && !s.fail() && ((atoi(tmpnev.c_str()) == 0) && (tmpnev != "0")))
    {
        dx.nev += tmpnev + " ";
        s >> tmpnev; //az utolsó stringnél még a while feltétele igaz, így az s-be olvas még egyet, viszont arra már nem igaz a feltétel
    }

    dx.chipszam = atoi(tmpnev.c_str()); //ezért kell így beletenni a megfelelő változóba

    dx.szorzo.clear();
    dx.pontszam.clear();

    while(!s.fail() && !s.eof())
    {
        int tmpszorzo, tmppontszam;
        s >> tmpszorzo;
        s >> tmppontszam;
        dx.szorzo.push_back(tmpszorzo);
        dx.pontszam.push_back(tmppontszam);
    }

//összpontszám kiszámolása(ha bármely részpontszám 0, akkor az összpontszám 0) -----------------------------------------------------------------------
    bool l = false;
    dx.osszpontszam = 0;
    for(int i = 0; !l && i < dx.pontszam.size(); i++) //ez egy linker, ami 0-t keres a vektorban.
    {
        l = dx.pontszam[i] == 0; //if(dx.pontszam[i] == 0) {l = true;}
        dx.osszpontszam += dx.szorzo[i] * dx.pontszam[i]; //ha nincsen 0 a vektorban akkor ez az összegzés végig fog menni
    }

    if(l) //vagy l == true, volt olyan részpontszám ami 0
    {
        dx.osszpontszam = 0;
    }

    sx = !x.fail();

    //!ilyen ellenőrzést mindig írj bele, az egy adatból állókat az első sornak megfelelően, a vektorokat for ciklussal irasd ki
      //!ha a fájlból beolvasott adatok helyesek, akkor akár ki is kommentelheted, ha számoltál valamit(mint itt az összpontot) akkor az a legfontosabb
      //!hogy ki legyen írva, így látod hogy helyes-e (legyen az összeg, számlálás, minker, maxker, bármi)
/*
    cout << dx.nev << " " << dx.chipszam << " ";
    for(int a = 0; a < dx.szorzo.size(); a++)
    {
        cout << dx.szorzo[a] << " " << dx.pontszam[a] << " ";
    }

    cout << dx.osszpontszam << endl;
*/
}
