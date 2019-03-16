//Fordítási direktívák
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

//Típus definíciói
typedef struct {
          unsigned int azon;
          string szerzo;
          string cim;
          string kiado;
          string ev;
          unsigned int darab;
          string isbn;
}                     konyv;
typedef struct{
    unsigned int azon;
    unsigned int darab;
}                     forg;
typedef enum{abnorm, norm} status;

// Függvény deklarációk
void tread(ifstream  &t, konyv    &dt, status &st);
void mread(ifstream  &m, forg &dm, status &sm);
void uhiext(ofstream &u, const konyv du);
void hhiext(ofstream &h, const unsigned int azon,const string uzen);

int main()
{
  //Szöveges állományok elõkészítése
    ifstream  t("nyilv.txt");
    if (t.fail() ) {
       cerr<<"Nincs törzs fájl"<<endl;
       char barmi;
       cin>>barmi;
       return 2;
    }
    ifstream  m("mod.txt");
    if (t.fail() ) {
       cerr<<"Nincs módosíto fájl"<<endl;
       char barmi;
       cin>>barmi;
       return 2;
    }
    ofstream  u("ujnyilv.txt");
    ofstream  h("hiba.txt");

  //Változó definíciók
    konyv dt;
    forg dm;
    status st,sm;
    int db;

  //Elemenkénti feldolgozás
    tread(t,dt,st);
    mread(m,dm,sm);
    while (st==norm || sm==norm) {
        if (sm==abnorm || (st==norm && dt.azon<dm.azon) ) {
            uhiext(u,dt);
            tread(t,dt,st);
        }
        else if (st==abnorm || (sm==norm && dt.azon>dm.azon) ) {
            cout<<"Hiba: ismeretlen azonosítójú ("
                <<dm.azon<< ") könyv a módosító fájlban"<<endl;
            mread(m,dm,sm);
        }
        else if (st==norm && sm==norm && dt.azon==dm.azon ) {
            dt.darab+=dm.darab;
            uhiext(u,dt);
            tread(t,dt,st);
            mread(m,dm,sm);
        }
    }
  // Szöveges állományok lezárása
    t.close();
    m.close();
    u.close();
}

// Függvény definíciók
void tread(ifstream &t, konyv &dt, status &st)
{
  string sor;
  getline(t,sor,'\n');
  if (!t.eof()) {
    st=norm;
    dt.azon   =atoi(sor.substr( 0, 4).c_str());
    dt.szerzo =     sor.substr( 5,14);
    dt.cim    =     sor.substr(21,19);
    dt.kiado  =     sor.substr(42,14);
    dt.ev     =     sor.substr(58, 4);
    dt.darab  =atoi(sor.substr(63, 3).c_str());
    dt.isbn   =     sor.substr(67,14);
  }
  else st=abnorm;
}

void mread(ifstream &m, forg &dm, status &sm)
{
  m>>dm.azon;
  if (!m.eof()) {
    sm=norm;
    m>>dm.darab;
  }
  else sm=abnorm;
}

void uhiext(ofstream &u, const konyv du)
{
    u<<setw(4) <<du.azon  <<' '<<
       setw(15)<<du.szerzo<<' '<<
       setw(20)<<du.cim   <<' '<<
       setw(15)<<du.kiado <<' '<<
       setw(4)<<du.ev     <<' '<<
       setw(3)<<du.darab  <<
       setw(15)<<du.isbn<<endl;
}

void hhiext(ofstream &h, const unsigned int azon, const string uzen)
{
    h<<setw(4)<<azon <<' '<< uzen <<endl;
}
