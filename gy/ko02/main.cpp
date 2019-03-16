#include <iostream>
#include <vector>
#include <fstream>

//2 pont - 2es
//3 - 3as?
//nincs beolvasás - vektroba push_back
//1 fájl- azt kell elküldeni - neptunkód.cpp

/*
Egy osztálykirándulás során a gyerekek betértek egy fagyizóba.
Sorban egymás után rendeltek fagyit. Egy fájlba időrendben feljegyeztük, hogy melyik gyerek hány gombóc fagyit evett.
A gyerekeket a keresztnevükkel azonosítjuk, így nincs két azonos nevű gyerek. Senki se evett negatív számú gombócot... :)
Hogy hívják azt a kölköt, aki a legtöbb, sorban őt megelőző osztálytársánál több gombóc fagyit fogyasztott el?
Azt feltehetjük, hogy legalább 1 gyerek jár az osztályba.
*/

using namespace std;

struct Fagyi
{
    string nev;
    int gomboc; //unsigned-nál nem venné észre a <0 hibát
};

//beolv - ha fv akk vagy vector fagyival tér vissza vagy akármi, CSAK FÁJLBÓL
//vector<Fagyi> beolvas();
//void beolvas(vector<Fagyi> &t); //referencia szerint!
bool beolvas(vector<Fagyi>& t); //hibakezelésnél bool, h sikerült-e
void kiir (const vector<Fagyi>& t);
string maxkiv(const vector<Fagyi>& t);
size_t tobbgomboc(const vector<Fagyi>& t, size_t i);
bool mindenkiegyszer(const vector<Fagyi>& t);
bool egyszer(const vector<Fagyi>& t, size_t i);

int main()
{
    //mer fagyi := rec(blabla)
    vector<Fagyi> t;
    if(beolvas(t)) //átadjuk fvnek a fagyit
    {
        kiir(t);
        cout << "A keresett diak: " << maxkiv(t);
    }
    else
    {
        cerr << "A megadott fajl hibas." << endl;
    }

    return 0;
}

bool beolvas(vector<Fagyi>& t)
{
    cout << "Adj meg egy fajlnevet: "; //helyesen fut zh "feltétel" része az ilyen kiírás, pont jár érte
    string fajlnev;
    cin >> fajlnev; //HIBAELLENÕRZÉS!!!!!!!!!!!!!!!!!!!!!
    ifstream ifs(fajlnev.c_str());

    if(ifs.fail()) //mainben lekezeljük majd
        return false;

    Fagyi a;
    //while mert nem tudjuk h mennyi
    while(ifs >> a.nev >> a.gomboc)
    {
        if(a.gomboc < 0)
        {
            ifs.close();
            return false;
        }
        t.push_back(a);
    }

    ifs.close();

    return !t.empty() && mindenkiegyszer(t);
}

void kiir (const vector<Fagyi>& t)
{
    for(size_t i = 0; i < t.size(); ++i)
    {
        cout << t[i].nev << "\t\t" << t[i].gomboc << endl;
    }
    cout << endl;
}

string maxkiv(const vector<Fagyi>& t) //& 1. módosítjuk beolv több dologgal visszatér 2. ...viszont nem akarom lemásolni
{
    size_t max = tobbgomboc(t,0); //nem fordul ha nem deklaráljuk, felé írhatnánk a defjét de nem kéne, pl rekurzívnál nem mûködne
    size_t ind = 0;

                         //1tõl n-1ig -> 2..n
    for(size_t i = 1; i < t.size(); ++i) //++i hatékonyabb
    {
        size_t m =  tobbgomboc(t,i); //itt deklaráljuk az m-et mert akk csak itt tudjuk használni, legszûkebb helyen
        if(m > max)
        {
            max = m;
            ind = i;
        }
    }

    //size_t maxnev = t[ind].nev; //ha ezzel returnölök akk felesleges létrehozni
    return t[ind].nev;
}

//szigorúan bemenõ, felhasználja de nem csinál vele semmit ->const
//size_t mert tömbindex, lehet int is de így c++osabb
size_t tobbgomboc(const vector<Fagyi>& t, size_t i)
{
    //t,i-t paraméterben, j-t fogjuk csak segédváltozóként deklarálni
    size_t c = 0; //inicializálás_ kezdeti értékadás
        //látszik h j itt segédváltozó
    for(size_t j = 0; j < i; ++j) //nem i-1 mert az még benne van
    {
        if(t[j].gomboc < t[i].gomboc)
            ++c;
        //else ág felesleges - nem kéne leírni
    }

    return c;
}

bool mindenkiegyszer(const vector<Fagyi>& t)
{
    bool l = true;

    //ezt forral másikat while-lal
    for(size_t i = 1; l && i < t.size(); ++i)
    {
        l = egyszer(t,i);
    }

    return l;
}

bool egyszer(const vector<Fagyi>& t, size_t i)
{
    bool l = true;
    size_t j = 0; //tömbindex azért nem 1
    while(l && j < i) //j <= i - 1 ugyanaz
    {
        l = t[i].nev != t[j].nev;
        ++j;
    }

    return l;
}
