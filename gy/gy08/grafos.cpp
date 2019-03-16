#include<iostream>
#include<vector>

using namespace std;

struct Ellista
{
    Ellista(string forras, vector<string> celcsucsok) : forras(forras), celcsucsok(celcsucsok) { }
    string forras;
    vector<string> celcsucsok;
};

vector<Ellista> peldatEloallit();
void kiir(const vector<Ellista>& ellistak);
size_t csucsokSzama(const vector<Ellista>& ellistak);
size_t elekSzama(const vector<Ellista>& ellistak);
bool vanParhuzamosEl(const vector<Ellista>& ellistak);
bool vanHurokEl(const vector<Ellista>& ellistak);

int main()
{
    vector<Ellista> peldaGraf = peldatEloallit();
    kiir(peldaGraf);
    cout<<"- - -"<<endl;
    cout<<csucsokSzama(peldaGraf)<<endl;    //5
    cout<<elekSzama(peldaGraf)<<endl;   //7
    cout<<vanParhuzamosEl(peldaGraf)<<endl;   //0 - hamis
    cout<<vanHurokEl(peldaGraf)<<endl;   //1 - igaz

    return 0;
}

vector<Ellista> peldatEloallit()
{
    vector<Ellista> ellistak;

    vector<string> alista;
    alista.push_back("A");
    alista.push_back("B");
    alista.push_back("D");
    Ellista a("A",alista);
    ellistak.push_back(a);

    vector<string> blista;
    blista.push_back("E");
    Ellista b("B",blista);
    ellistak.push_back(b);

    vector<string> clista;
    clista.push_back("A");
    clista.push_back("B");
    Ellista c("C",clista);
    ellistak.push_back(c);

    vector<string> dlista;
    dlista.push_back("C");
    Ellista d("D",dlista);
    ellistak.push_back(d);

    vector<string> elista;
    Ellista e("E",elista);
    ellistak.push_back(e);

    return ellistak;
}

void kiir(const vector<Ellista>& ellistak)
{
    for(size_t i=0;i<ellistak.size();++i)
    {
        cout<<ellistak[i].forras;
        size_t kifok = ellistak[i].celcsucsok.size();
        if(0 != kifok)
            cout<<";";
        for(size_t j=0;j+1<kifok;++j)
            cout<<ellistak[i].celcsucsok[j]<<":";
        if(kifok > 0)
            cout<<ellistak[i].celcsucsok[kifok-1];
        cout<<endl;
    }
}

size_t csucsokSzama(const vector<Ellista>& ellistak)
{
    //feladat
    return 0;
}

size_t elekSzama(const vector<Ellista>& ellistak)
{
    //feladat
    return 0;
}

bool vanParhuzamosEl(const vector<Ellista>& ellistak)
{
    //feladat
    return false;
}

bool vanHurokEl(const vector<Ellista>& ellistak)
{
    //feladat
    return false;
}