#include<fstream>
#include<iostream>
#include<sstream>
#include<vector>

using namespace std;

const string FAJLNEV = "spanyolok.txt";

struct Spanyol;

bool beolvas(vector<Spanyol> &v);
void kiir(const vector<Spanyol> &v);
int leghosszabbNevuKora(const vector<Spanyol> &v);

struct Spanyol
{
    int kor;
    string nev;
};

int main()
{
	vector<Spanyol> losLocos;

	if(beolvas(losLocos))
    {
        kiir(losLocos);
    }
    else
        cerr<<"Hibas file"<<endl;

    return 0;
}

bool beolvas(vector<Spanyol> &losLocos)
{
    ifstream ifs(FAJLNEV.c_str());
    if(ifs.fail())
	{
		cerr<<"Nincs ilyen file."<<endl;
		return false;
	}

    string sor;
    while (getline(ifs,sor))
    {
        stringstream ss(sor);
        string sv, sv2;
        string nev="";
        ss >> sv;
        if (ss.fail())
            return false;
        while (ss>>sv2)
        {
            ss>>sv2;
            nev +=sv2;
        }
        spanyol s;
        s.nev=nev;
        s.kor=atoi(sv2.c_str());
        if (0 == s.kor && "0"!=sv2)
        losLocos.push_back(s);
    }

    ifs.close();
    return true;
}

void kiir(const vector<Spanyol> &v)
{
    for(size_t i=0;i<v.size();++i)
        cout<<v[i].nev<<" ("<<v[i].kor<<")"<<endl;
}

int leghosszabbNevuKora(const vector<Spanyol> &v) //ef: v.size > 0
{
	return 0;
}
