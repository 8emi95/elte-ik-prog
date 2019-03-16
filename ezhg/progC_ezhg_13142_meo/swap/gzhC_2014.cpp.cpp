#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

//swap
using namespace std;

struct Befizetes{
    Befizetes(string datum, int osszeg){ this->datum = datum; this->osszeg = osszeg; }
    string datum;
    int    osszeg;
};

struct Sor{
    string nev;
    vector<Befizetes> befizetesek;
};

// Kis Pista Feri  2013.11.13   2500   2014.01.23   3000   2014.03.11  1500

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
        // név beolvasása, amíg nem dátum következik
        str = "";
        s >> str;
        if (str == "")
        {
            sf = false;
            return;
        }
        sf = true;
        df.nev = str;
        str = "";
        s >> str;
        while (!Datum(str) && str != "")
        {
            df.nev += " " + str;
            str = "";
            s >> str;
        }
        // dátum - összeg párok beolvasása
        df.befizetesek.clear();
        while (str != "")
        {
            int  osszeg;
            s >> osszeg;
            df.befizetesek.push_back(Befizetes(str, osszeg));
            str = "";
            s >> str;
        }
    }
    bool End(){     return !sf; } // true == norm, false == abnorm
    Sor  Current(){ return df; }
private:
    bool Datum(string s)
    {
         if (s.length() != 10) return false;
         return  (s[4] == '.' && s[7] == '.');
    }
    bool     sf;
    Sor      df;
    ifstream f;
};

int BefizetesekOsszege(vector<Befizetes>& bef)
{
    int s = 0;
    for (int i = 0; i < bef.size(); i++) s += bef[i].osszeg;
    return s;
}

bool MindigTobbMintKetezer(vector<Befizetes>& bef)
{
    bool l = true;
    for (int i = 0; l && i < bef.size(); i++) l = (bef[i].osszeg >= 2000);
    return l;
}

int main()
{
    setlocale(LC_ALL, "");
    Felsorolo f("input.txt");
    int     befizetett = 0;
    int     diakok     = 0;
    string  legkorabbi_datum, sietos_diak;
    bool    volt_teljes_befizetes = false;
    bool    l = false;
    string  ketezres_befizeto_neve;

    for (f.First(); !f.End(); f.Next())
    {
        cout << f.Current().nev << endl;
        // összegzés
        Sor s = f.Current();
        int befizetes = BefizetesekOsszege(s.befizetesek);
        befizetett += befizetes;

        // számlálás
        diakok++;

        // felt.max.ker.
        if (befizetes >= 13000)
        {
            if (volt_teljes_befizetes)
            {
                if (s.befizetesek[s.befizetesek.size()-1].datum < legkorabbi_datum)
                {
                    sietos_diak = s.nev;
                    legkorabbi_datum = s.befizetesek[s.befizetesek.size()-1].datum;
                }
            }
            else
            {
                volt_teljes_befizetes = true;
                sietos_diak = s.nev;
                legkorabbi_datum = s.befizetesek[s.befizetesek.size()-1].datum;
            }
        }

        // lin.ker.
        if (!l)
        {
            if (MindigTobbMintKetezer(s.befizetesek))
            {
                ketezres_befizeto_neve = s.nev;
                l = true;
            }
        }
    }

    if (befizetett < diakok * 13000) cout << "Hiányzó befizetés: " << diakok*13000 - befizetett << endl;
    else                             cout << "Az osztály teljesítette a 13000Ft befizetését." << endl;

    if (volt_teljes_befizetes) cout << "Legsietõsebb diák: " << sietos_diak << endl;
    else                       cout << "Senki sem fizette még ki a kirándulás árát." << endl;

    if (l) cout << ketezres_befizeto_neve << " mindig >= 2000-et fizetett." << endl;
    return 0;
}
