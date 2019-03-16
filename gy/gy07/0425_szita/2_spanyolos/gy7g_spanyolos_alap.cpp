#include<fstream>
#include<iostream>
#include<vector>

using namespace std;

const string FAJLNEV = "spanyolok.txt";	//"beegetett" stringeket illik kiemelni - a masik lehetoseg persze, hogy bekerjuk a fajlnevet

struct Spanyol; //lehet a structot is "elorevetetten" deklaralni (angolul: forward declaration)

bool beolvas(vector<Spanyol> &v);
void kiir(const vector<Spanyol> &v);
int leghosszabbNevuKora(const vector<Spanyol> &v);

struct Spanyol	//persze eleve irhattam volna a fv. deklaracio ele
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
        cerr<<"Hibas file"<<endl;   //cerr: error kimenet, ami amugy itt ugyanaz mint a konzol

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
