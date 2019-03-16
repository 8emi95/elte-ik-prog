#include<iostream>
#include<fstream>
#include<vector>
#include<sstream>
#include<cstdlib>

using namespace std;

struct Vasarlas
{
    int ev; //a redvás nullák miatt 5 int
    int ho;
    int nap;
    int ora;
    int perc;
    string azon; //0 az elején
    vector<string> arukod;
};

enum Statusz { norm, abnorm };

class Felsorolo
{
private:
    ifstream fajl;
    Vasarlas vasarl;
    Statusz st;

    void read() //egy sor beolvasása
    {
        if (this -> fajl.eof())
            this -> st = abnorm;

        string sor;
        getline(this -> fajl, sor);
        stringstream sorStream(sor);
        char kuka;
        sorStream >> this -> vasarl.ev >> kuka >> this -> vasarl.ho >> kuka >> this -> vasarl.nap >> kuka >> this -> vasarl.ora >> kuka >> this -> vasarl.perc >> this -> vasarl.azon;

        this -> vasarl.arukod.clear(); //kül növelné mindig a vektort a kövi sor áruval
        while(!sorStream.eof())
        {
            string kod;
            sorStream >>  kod;
            this -> vasarl.arukod.push_back(kod);
        }
    }
public:
    void first() { read(); }

    Vasarlas current() { return this -> vasarl; }

    void next() { read(); }

    bool end() { return (this -> st == abnorm); }

    Felsorolo(string fajlnev)
    {
        this -> fajl.open(fajlnev.c_str());
        if (this->fajl.fail())
        {
            cout << "Nem letezik ilyen fajl." << endl;
            exit(1);
        }
        this -> st = norm;
    }

    ~Felsorolo() { this -> fajl.close(); }
};

int main()
{
    Felsorolo fels("bemenet.txt");
    fels.first();
    while(!fels.end())
    {
        Vasarlas v = fels.current();

        //feladatok:

        //melyikekben nem volt árukód22
        int i = 0;
        int arukod_db = v.arukod.size();

        while (i < arukod_db && v.arukod[i] != "árukód22") //egy sort vizsgálunk csak
            i++;
        if (i == arukod_db)
        {
            cout << v.ev << ":" << v.ho << ":" << v.nap << ":" << v.ora << ":" << v.perc << " " << v.azon << endl;
        }
        fels.next();

        //legkevesebbet vásárló + hányféle
//        int c = 0;
//        vector<int> hanyfele(v.arukod[0]);
//        for(int i = 0; i < arukod_db-1; ++i)
//        {
//            if(v.arukod[i+1] != hanyfele[0])
//            {
//                int j = 0;
//                while(j <= c && v.arukod[i+1] != hanyfele[j])
//                    j++;
//                if(j > c)
//                {
//                    hanyfele[c+1] = v.arukod[i+1];
//                    c++;
//                }
//            }
//        }
//        vector<int> arudb;
//        arudb.push_back(c);
    }
    return 0;
}
