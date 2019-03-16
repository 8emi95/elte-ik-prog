//K�sz�tette:       Gregorics Tibor
//D�tum:            2009.01.29.
//Feladat:          K�nyvt�ri nyilv�ntart�s adatainak karbantart�sa

#include <iostream>
#include "kozos.h"
#include "torzs.h"
#include "mod.h"
#include "ujtorzs.h"
#include "hiba.h"

using namespace std;

//Feladat: 	        K�nyvt�ri nyilv�ntart�s adatainak karbantart�sa.
//Bemen� adatok:    Torzs t    - t�rzsadatok f�jlja (k�nyvazonos�t�k szerint szig. n�vekv�)
//                  Mod   m    - m�dos�t� adatok f�jlja (k�nyvazonos�t�k szerint szig. n�vekv�)
//Kimen� adatok:    Ujtorzs u  - az id�szer�s�tett �j t�rzs f�jl
//                  Hiba h     - hiba�zenetek f�jlja
//Tev�kenys�g:	    A k�t bemen� f�jl elemeinek �sszefuttat�sos �sszes�t�se (id�szer�s�t�s).
int main()
{
    //V�ltoz�k defin�ci�i
    Torzs      t ("nyilv.txt");
    Mod        m ("mod.txt");
    Ujtorzs    u ("ujnyilv.txt");
    Hiba       h ("hiba.txt");

    Konyv   dt;
    Valt    dm;
    Status  st,sm;

    //�sszefuttat�sos �sszes�t�s
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
                case 'K' :  h.Write(dm.konyv.azon, "Nem l�tez� k�nyv k�lcs�nz�se");
                            break;
                case 'T' :  h.Write(dm.konyv.azon, "Nem l�tez� k�nyv t�rl�se");
                            break;
                default  :  h.Write(dm.konyv.azon, "Hib�s funkci�");
            }
            m.Read(dm,sm);
        }else if (st==norm && sm==norm && dt.azon==dm.konyv.azon){
            switch(dm.funk){
                case 'B' :  u.Write(dm.konyv);
                            h.Write(dm.konyv.azon, "L�tez� k�nyv besz�r�sa");
                            break;
                case 'K' :  int db = dt.db+dm.konyv.db;
                            if ( db<0 ){
                                u.Write(dt);
                                h.Write(dt.azon,"Hib�s darabsz�m" );
                            }else{
                                dt.db = db;
                                u.Write(dt);
                            }
                            break;
                case 'T' :  break;
                default  :  h.Write(dm.konyv.azon, "Hib�s funkci�");
            }
            t.Read(dt,st);
            m.Read(dm,sm);
        }
    }

    return 0;
}
