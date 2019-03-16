//Készítette:       Gregorics Tibor
//Dátum:            2009.01.29.
//Feladat:          Könyvtári nyilvántartás adatainak karbantartása

#include <iostream>
#include "kozos.h"
#include "torzs.h"
#include "mod.h"
#include "ujtorzs.h"
#include "hiba.h"

using namespace std;

//Feladat: 	        Könyvtári nyilvántartás adatainak karbantartása.
//Bemenõ adatok:    Torzs t    - törzsadatok fájlja (könyvazonosítók szerint szig. növekvõ)
//                  Mod   m    - módosító adatok fájlja (könyvazonosítók szerint szig. növekvõ)
//Kimenõ adatok:    Ujtorzs u  - az idõszerûsített új törzs fájl
//                  Hiba h     - hibaüzenetek fájlja
//Tevékenység:	    A két bemenõ fájl elemeinek összefuttatásos összesítése (idõszerûsítés).
int main()
{
    //Változók definíciói
    Torzs      t ("nyilv.txt");
    Mod        m ("mod.txt");
    Ujtorzs    u ("ujnyilv.txt");
    Hiba       h ("hiba.txt");

    Konyv   dt;
    Valt    dm;
    Status  st,sm;

    //Összefuttatásos összesítés
    t.Read(dt,st);
    m.Read(dm,sm);
    while (st==norm || sm==norm)
    {
        if (sm==abnorm ||(st==norm && dt.azon<dm.konyv.azon) ){
            u.Write(dt);
            t.Read(dt,st);
        }else if (st==abnorm || (sm==norm && dt.azon>dm.konyv.azon) ){
            switch(dm.funk ){
                case 'B' :  u.Write(dm.konyv);
                            break;
                case 'K' :  h.Write(dm.konyv.azon, "Nem létezõ könyv kölcsönzése");
                            break;
                case 'T' :  h.Write(dm.konyv.azon, "Nem létezõ könyv törlése");
                            break;
                default  :  h.Write(dm.konyv.azon, "Hibás funkció");
            }
            m.Read(dm,sm);
        }else if (st==norm && sm==norm && dt.azon==dm.konyv.azon){
            switch(dm.funk){
                case 'B' :  u.Write(dm.konyv);
                            h.Write(dm.konyv.azon, "Létezõ könyv beszúrása");
                            break;
                case 'K' :  int db = dt.db+dm.konyv.db;
                            if ( db<0 ){
                                u.Write(dt);
                                h.Write(dt.azon,"Hibás darabszám" );
                            }else{
                                dt.db = db;
                                u.Write(dt);
                            }
                            break;
                case 'T' :  break;
                default  :  h.Write(dm.konyv.azon, "Hibás funkció");
            }
            t.Read(dt,st);
            m.Read(dm,sm);
        }
    }

    return 0;
}
