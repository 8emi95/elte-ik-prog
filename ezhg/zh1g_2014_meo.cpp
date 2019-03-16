#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

/*
Poncius Pil�tus ezen a h�ten is besz�det mond. A besz�det szavank�nt egy t�mbben t�roljuk. A besz�d hossza az �a�, �az� szavakat nem sz�molva is legal�bb 5 sz�. R bet�t egy szava sem tartalmaz.
Kommunik�ci�s szakembere javaslat�ra a selymesebb hangz�s �rdek�ben igyekezett a szavakban el�fordul� l bet�ket min�l ink�bb a szavak els� fel�be s�r�teni.
�llap�tsuk meg, hogy melyik sz� els� fel�ben (azaz a �k�zepe el�tti bet�ig�) van a legt�bb l bet� azon szavak k�z�l, melyeknek a m�sodik fel�ben (k�zep�t�l kezdve) m�r nincs l bet�.
*/

char beolvasasModja();
void beolvasas_g(vector<string> &t);
bool beolvasas_f(vector<string> &t);
bool vanr(string s);
int darab(const vector<string> &t);
bool maxker(const vector<string> &t, string &szo);
int ldb(string s);
bool nincsl(string s);

int main()
{
	vector<string> t;
	char c = beolvasasModja();
    bool hiba;
    do
    {
        t.resize(0);    //Azert torlom, mert lehet, hogy egy do-while-ban mar sokadszorra olvasom be, es "maradt" valami szemet az elozo korbol
        if(c == 'f')
        {
            hiba = !beolvasas_f(t) || darab(t) < 5;	//lusta kiertekeles!
        }
        else if(c == 'k')
        {
            beolvasas_g(t);
            hiba = darab(t) < 5;
        }
        if(hiba)
            cerr<<"Olvasd be ujra!"<<endl;
    }
    while(hiba);

	string szo;
	cout<<"Sikeres beolvasas! A beszed:"<<endl;
	for(size_t i=0;i<t.size();++i)
		cout<<t[i]<<" ";
	cout<<endl;

	if(maxker(t,szo))
		cout<<"A keresett szo: "<<szo<<"."<<endl;
	else
		cout<<"Nincs ilyen szo."<<endl;

	return 0;
}

char beolvasasModja()
{
    char c;
	cout<<"(f)ajl vagy (k)onzol?"<<endl;

	bool hiba;
	do
    {
        cin>>c;
        hiba = 'f' != c && 'k' != c;
        cin.clear();
        cin.ignore(1000,'\n');
    }
    while(hiba);
    return c;
}

void beolvasas_g(vector<string> &t)
{
	cout<<"Add meg a beszedet!"<<endl;
	bool vege;
	do
	{
		string akt;
		cin>>akt;
		vege = vanr(akt);
		if(!vege)
			t.push_back(akt);
	}
	while(!vege);

	cin.ignore(1000,'\n');	//Hogy ha nem volt helyes (darab<5 miatt), akkor se maradjon a konzolon amit beirtam
}

bool beolvasas_f(vector<string> &t)
{
	cout<<"Ird be a fajlnevet!"<<endl;
	string fnev;
	cin>>fnev;

	ifstream f(fnev.c_str());
	if(f.fail())
		return false;

	bool vege;
	do
	{
		string akt;
		f>>akt;
		vege = f.fail() || vanr(akt);	//lusta kiertekeles!
		if(!vege)
			t.push_back(akt);
	}
	while(!vege);

	f.close();

	return true;
}

bool vanr(string s)
{
	bool l = false;
	for(size_t i=0;!l && i<s.size();++i)
		l = s[i] == 'r' || s[i] == 'R';
	return l;
}

int darab(const vector<string> &t)
{
	int db = 0;
	for(size_t i=0;i<t.size();++i)
		if(t[i] != "a" && t[i] != "az")
			++db;
	return db;
}

bool maxker(const vector<string> &t, string &szo)
{
	int max;
	size_t ind;
	bool van = false;
	for(size_t i=0;i<t.size();++i)
	{
		int db = ldb(t[i]);
		bool nincs = nincsl(t[i]);
		if(nincs && !van)
		{
			van = true;
			max = db;
			ind = i;
		}
		else if(nincs && van)
		{
			if(max < db)
			{
				max = db;
				ind = i;
			}
		}
	}

	if(van) //Osszetett fv. masodik fele
		szo = t[ind];   //referencia szerint adtam at, igy voltakeppen ezzel is visszaterek (lasd allapotter!)

	return van;
}

int ldb(string s)	//[0 .. s.size()/2 - 1] intervallum
{
	int db = 0;
	for(size_t i = 0; i<s.size()/2;++i)
		if(s[i] == 'l' || s[i] == 'L')
			++db;
	return db;
}

bool nincsl(string s)	//[s.size()/2 .. s.size()-1] intervallum
{
	bool l = true;
	for(size_t i=s.size()/2;l && i<s.size();++i)
		l = s[i] != 'l' && s[i] != 'L';
	return l;
}
