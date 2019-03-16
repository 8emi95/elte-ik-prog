#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <stdlib.h>
using namespace std;

struct Korido{
    Korido(int id, string ido){ this->id = id; this->ido = ido; }
    int    id;
    string ido;
};

// Alonso Ferrari 4 01:22:234 5 01:21:891 6 01:21:234
// M. Schumi McLaren 4 01:22:234 5 01:21:891 6 01:21:000

struct Sor{
    string nev, csapat;
    vector<Korido> idok;
};



class Felsorolo{
public:
    Felsorolo(string fajlnev){ f.open(fajlnev.c_str()); }
    void First(){ Next(); }
    void Next()
    {
        // egy teljes sor beolvasása
        string str;
        getline(f, str);
        stringstream s(str);
        vector<string> nev;

        // név beolvasása, amíg nem dátum következik
        str = "";
        s >> str;
        while (str != "" && !szam(str))
        {
            nev.push_back(str);
            str = "";
            s >> str;
        }

        if (nev.size() < 2) // érvénytelen teszt-eset
        {
            sf = false;
            return;
        }
        sf = true;

        df.csapat = nev[nev.size()-1];
        df.nev = nev[0];
        for (int i = 1; i < nev.size()-1; i++) df.nev += " " + nev[i];

        cout << df.nev << " " << df.csapat << " ";

        // dátum - összeg párok beolvasása
        df.idok.clear();
        while (str != "")
        {
            cout << "\"" << str << "\" ";
            string korid = str;
            string korido;
            s >> korido;
            if (korido != "") df.idok.push_back(Korido(atoi(korid.c_str()), korido));
            str = "";
            s >> str;
        }
        cout << "." << endl;
    }
    bool End(){     return !sf; } // true == norm, false == abnorm
    Sor  Current(){ return df; }
    bool szam(string s){
        if (s == "") return false;
        return (atoi(s.c_str()) != 0);
    }

private:
    bool     sf;
    Sor      df;
    ifstream f;
};

void kiir(Sor s)
{
    cout << s.nev << ", " << s.csapat;
    for (int i = 0; i < s.idok.size(); i++) cout << ", " << s.idok[i].id << ": " << s.idok[i].ido;
    cout << endl;
}

bool CsokkenoKorIdok(Sor s)
{
    bool l = true;
    cout << s.idok.size() << endl;
    for (int i = 0; i < s.idok.size()-1 && l; i++)
    {
        l = (s.idok[i+1].ido < s.idok[i].ido);
        cout << ".";
    }
    return l;
}

string LegkisebbKorIdo(Sor s)
{
    string korido = s.idok[0].ido;
    for (int i = 1; i < s.idok.size(); i++)
        if (s.idok[i].ido < korido)
            korido = s.idok[i].ido;

    return korido;
}

int main()
{
    setlocale(LC_ALL, "");
    Felsorolo f("input.txt");
    bool l = false;
    string korido;
    for (f.First(); !f.End(); f.Next()) // felt.min.ker.: beta ~ van körideje
    {
        if (CsokkenoKorIdok(f.Current())) cout << f.Current().nev << endl;
        kiir(f.Current());/*
        if (f.Current().idok.size() > 0) // beta
        {
            string akt_min_korido = LegkisebbKorIdo(f.Current());
            if (!l)
            {
                l = true;
                korido = akt_min_korido;
            }
            else if (korido > akt_min_korido)
            {
                korido = akt_min_korido;
            }
        }*/
        cout << ".";
    }

    if (l) cout << "Leggyorsabb köridő: " << korido << endl;

    return 0;
}
