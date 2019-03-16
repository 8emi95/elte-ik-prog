//Név:              Kovácsné Pusztai Kinga
//Neptun kód:
//MAIL:             kinga@inf.elte.hu
//Feladat:          … itt a szöveg …
//                  … itt a szöveg folytatása, akár több soron keresztül…
//Specifikáció:
//Bemenet:          … itt a specifikáció bemeneti része…
//Kimenet:          … itt a specifikáció kimeneti része…
//Elõfeltétel:      … itt a specifikáció elõfeltételi része…
//Utófeltétel:      … itt a specifikáció utófeltételéli része…
//Definíció:        … itt a specifikáció definíció része…
#include <iostream>
#include "infile.h"
#include <cstdlib>
#include <sstream>

using namespace std;

struct datum
{
    int e,h,n;
};

void kiir(const ember e, const int c)
{
    cout <<e.nev<<"\t";
    for(int i=0;i<(int)e.datum.size();i++) cout <<e.datum[i]<<"\t"<<e.osszeg[i]<<"\t";
    cout<<"osszesen:"<<c<<"\t"<<"meg hianyzik:"<<13000-c<<endl;
}

int szamol(const ember e)
{
    int c=0;
    for(int i=0;i<(int)e.osszeg.size();i++) c=c+e.osszeg[i];
    return c;
}

bool keres (const ember e)
{
    bool l=true;
    int i=0;
    while(i<(int)e.osszeg.size() && l)
    {
      l=e.osszeg[i]>2000;
      i++;
    }
    return l;
}

bool kisebb(datum x, datum y)
{
    if (x.e<y.e) return true;
    if (x.e>y.e) return false;
    if (x.h<y.h) return true;
    if (x.h>y.h) return false;
    if (x.n<y.n) return true;
    if (x.n>y.n) return false;
    return false;
}
datum vag(string sz )
{
    stringstream s;
    datum a;
    char k;
    s<<sz;
    s>>a.e;
    s>>k;
    s>>a.h;
    s>>k;
    s>>a.n;
    return a;
}

int main()
{
    SeqInfile x("teszt1.txt");
    ember ex,vx,mine;
    bool minb=false;
    bool van=false;
    int c,n;
    datum m, a;
    char k;
    x.First();
    if (x.End()){
        cout <<"Ures a fajl!\n";
        exit(2);
    }
    while (!x.End()){
        ex=x.Current();
       //megszamolja, hogy mennyit fizetett eddig
        c=szamol(ex);
        kiir(ex,c);
       //ha befizette:
        if (c==13000) {
            //utolsó dátumot átkonvertálja számmá
            n=ex.datum.size()-1;
            a=vag(ex.datum[n]);
            //Felt. max. ker.
            if (minb){
                 if (kisebb (a,m)){
                 mine=ex;
                 m=a;
            }}
            else {
                minb=true;
                mine=ex;
                m=a;
            }
        }
        // van-e olyan tan. aki mindig >2000-et fizetett
        if (!van) {
            van=keres(ex);
            if (van) vx=ex;
        }
        x.Next();
    }
    if (van) cout<<"Az elso tanulo, aki mindig >2000-et fizetett: "<<vx.nev;
        else cout<<"Nincs olyan tanulo, aki mindig >2000-et fizetett be";
    if (minb) cout << endl<<"A leghamarabb befizeto tanulo: "<<mine.nev;
        else cout<<"\n Nincs olyan tanulo, aki befizette a teljes osszeget";
    return 0;
}

/*int main()
{


    ex=x.Current(); ey=y.Current();
    while (!x.End() && !y.End()){
            if (ex.nev<ey.nev){
                if (ex.volt) z1.write(ex);
                kiir(2107, ex);
                x.Next();
                ex=x.Current();
            } else
            if (ex.nev>ey.nev){
                if (ey.volt) z1.write(ey);
                kiir(2208, ey);
                y.Next();
                ey=y.Current();
            } else
            {
                if (ex.volt && ey.volt) z2.write(ex); else if (ex.volt || ey.volt) z1.write(ex);
                kiir(2307, ex);x.Next(); ex=x.Current();
                kiir(2308, ey);y.Next(); ey=y.Current();
            }
    };
    while (!x.End()){
            if (ex.volt) z1.write(ex);
            kiir(2407, ex);
            x.Next();
            ex=x.Current();
    };
    while (!y.End()){
            if (ey.volt) z1.write(ey);
            kiir(2408, ey);
            y.Next();
            ey=y.Current();
    };

    cout << "Hello world!" << endl;
    return 0;
}

void kiir(int q, ember e){
    cout<<q<<". fajl emberének neve: "<<e.nev<<'\t';
    if (e.volt){
        cout<<"udulesi helyei: ";
        for(int i=0;i<e.hol.size();i++) cout<<e.hol[i]<<", ";
    } else cout<<"nem udult ebben az évben.";
cout<<endl;
}
*/
