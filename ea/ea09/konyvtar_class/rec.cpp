/*
  Könyvtári nyilvántartást tartalmazó szekvenciális fájlból
  kiválogatjuk a nulla példányszámú könyveket.
  A nyilvántartásban szereplõ könyvek adatai
  egy szöveges fájlban helyezkednek el soronként
*/

#include <fstream>
#include <iomanip>
#include <string>

typedef struct {
          unsigned int azon;
          string szerzo;
          string cim;
          string kiado;
          string ev;
          unsigned int darab;
          string isbn;
        }                  konyv;

typedef enum{abnorm, norm} status;

void olv(ifstream &x, konyv &dx, status &sx);
void ir(ofstream &x, const konyv dx);

// 1-1 Elemenkénti feldolgozás

int main()
{
  ifstream x("inp.txt");
  if (x.fail() ) {
    cerr<<"Nincs input file"<<endl;
    char barmi;
    cin>>barmi;
    return 2;
  }

  ofstream y("out.txt");
  konyv dx;
  status sx;

  olv(x,dx,sx);
  while (sx==norm) {
    if (dx.darab==0) {
      ir(y,dx);
    }
    olv(x,dx,sx);
  }

  x.close();
  y.close();

  return 0;
}

// Olvasó és író eljárások

void olv(ifstream &x, konyv &dx, status &sx)
{
  string sor;

  getline(x,sor,'\n');
  if (!x.eof()) {
    sx=norm;
    dx.azon   =atoi(sor.substr( 0, 4).c_str());
    dx.szerzo =     sor.substr( 5,14);
    dx.cim    =     sor.substr(20,19);
    dx.kiado  =     sor.substr(40,14);
    dx.ev     =     sor.substr(55, 4);
    dx.darab  =atoi(sor.substr(60, 3).c_str());
    dx.isbn   =     sor.substr(64,14);
  }
  else sx=abnorm;
}

void ir(ofstream &y, const konyv dy)
{
    y<<setw(4)<<' '<<dy.azon<<' '<<dy.szerzo<<' '<<dy.cim<<endl;
}

