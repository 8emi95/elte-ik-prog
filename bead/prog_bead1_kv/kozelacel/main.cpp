#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>

/*
3. Egy kutya kiállításon m kategóriában n kutya vesz részt. Minden kutya minden
kategóriában egy 0 és 10 közötti pontszámot kap. Mekkora a pontszámbeli különbség az
első és az utolsó helyezett kutya között?
*/

using namespace std;

void beolvkonz (vector<vector<int> > &kutya);
void beolvfajl (vector<vector<int> > &kutya);
int osszegzes(vector<vector<int> > &kutya, int m, int n, int sorossz);
int maxkiv(vector<vector<int> > &kutya, int max, int n, int m);
int minkiv(vector<vector<int> > &kutya, int min, int n, int m);

int main()
{
	int beolv;
	vector<vector<int> > kutya;
	bool rossz;
	do{
	cout << "Honnan szeretnel beolvasni? 1-es, ha konzolrol, 2-es, ha fajlbol: "<<endl;
	cin >> beolv;
	rossz = (cin.fail() || (beolv !=1 && beolv !=2) || !cin.peek()=='\n');
	if (rossz)
	{
		cout<<"Egy 1-est vagy egy 2-est adj meg!"<<endl;
		cin.clear();
		cin.ignore(1000,'\n');
	}
	}while (rossz);
	if (beolv==1)
		beolvkonz(kutya);
	if (beolv==2)
		beolvfajl(kutya);

	//összegzés
	//vector<int> sor;
	int sorossz;

	//maxkiv
	int max;
	int nyertes = maxkiv(kutya, max, n, m);

	//minkiv
	int min;
	int vesztes = minkiv(kutya, min, n, m);

	cout << "Az elso es az utolso kulonbsege: " << nyertes-vesztes;

	return 0;
}

void beolvkonz (vector<vector<int> > &kutya)
{
	kutya.resize(0);
	bool bek=false;

	int n;
	int m;

	bool rossz;
	do {
		cout << "Hany kutya lesz? ";
		cin >> n;
		rossz = (cin.fail() || n <= 0); // || !cin.peek()=='\n');
		if (rossz) {
		cout << "Nem jo! " << endl;
		cin.clear();
		cin.ignore(1000, '\n');
		}
	} while (rossz);
	do {
		cout << "Hany kategoria lesz? ";
		cin >> m;
		rossz= (cin.fail() || m<=0);// || !cin.peek()=='\n');
		if (rossz) {
		cout << "Nem jo! " << endl;
		cin.clear();
		cin.ignore(1000, '\n');
		}
	} while (rossz);

	kutya.resize(m);

	for (int i=0; i<n; i++)
	{
		for (int j=0; j<m; j++)
		{
			int szam=0;
			bool hiba;
			do {
					cout << "A(z) " << i+1 << ". kutya " << j+1 << ". kategoriaban szerzett pontszama: ";
					cin >> szam;
					hiba = (cin.fail() || szam>10 || szam<0);
					if (hiba) {
					cout << "Nem jo! " << endl;
					cin.clear();
					cin.ignore(1000, '\n');
					}
			} while (hiba);
			kutya[i].push_back(szam);
		}
	}
	bek=true;

//	for (int i=0; i<n; i++)
//	{
//		for (int j=0; j<m; j++)
//		{
//			cout << kutya[i][j] << " ";
//		}
//		cout << endl;
//	}

}

void beolvfajl (vector<vector<int> > &kutya)
{
	bool bef=true;
	ifstream fajl;
	string fajlnev;
	bool hiba;
	kutya.clear();

	do{
		cout << "Melyik fajl legyen beolvasva? ";
		cin >> fajlnev;
		fajl.open(fajlnev.c_str());
		if(hiba=fajl.fail())
		{
			cout << "Abbol a mappabol valassz fajlt, amelyikben a program van!" << endl;
			fajl.clear();
		}
	} while (hiba);

	int n;
	int m;

	hiba=true;
	hiba=(cin.fail());
	fajl >> n >> m;
	if (hiba)
	{
		fajl.close();
		bef=false;
		//return false;
	}

	cout << "faszagyerek";
	kutya.resize(n);
	for(int i = 0; i<n; ++i){
		kutya[i].resize(m);
		for(int j = 0; j<m; ++j){
			bool hiba;
			fajl >> kutya[i][j];
			hiba = (cin.fail() || kutya[i][j]>10 || kutya[i][j]<0);
			if (hiba)
			{
				fajl.close();
				bef=false;
			}
		}
	}

	cout << "mama way tütütüüü";
	bef=true;
}

int osszegzes(vector<vector<int> > &kutya, int m, int n, int sorossz)
{
	sorossz = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			sorossz += kutya[i][j];
		}
	}
	return sorossz;
}

int maxkiv(vector<vector<int> > &kutya, int max, int n, int m)
{
	max = osszegzes(kutya, 0);
	for (int i = 1; i < n; ++i)
	{
		int elso = osszegzes(kutya, i);
		if (elso > max)
		{
			max = elso;
		}
	}
	return max;
}

int minkiv(vector<vector<int> > &kutya, int min, int n, int m)
{
	min = osszegzes(kutya, 0);
	for (int i = 1; i < n; ++i)
	{
		int utolso = osszegzes(kutya, i);
		if (utolso < min)
		{
			min = utolso;
		}
	}
	return min;
}

// 2nku 3mka
// 1 2 3
// 4 5 6


/*bool beolvfajl (vector<vector<int> > &kutya)
{
	bool hiba;
	ifstream f;
	string fajlnev;
	do
	{
		cout << "Melyik fajlt valasztod?"<<endl;
		cin >> fajlnev;
		f.open(fajlnev.c_str());
		if(hiba = f.fail())
			{
				cout << "Olyan fajlt adj meg, ami benne van abban a mappaban, melyben a program is." << endl;
				f.clear();
			}
	} while(hiba);

	kutya.resize(0);

	bool jo;
	int n;
	do {
		cout << "Add meg hogy hany kutya lesz: ";
		cin >> n;
		jo = (!cin.fail() && n>=0);
		if (!jo) {
		cout << "Nem jo! " << endl;
		cin.clear();
		cin.ignore(1000, '\n');
		}
	} while (!jo);
	int m;
	do {
		cout << "Add meg hogy hany kategoria lesz: ";
		cin >> m;
		jo= (!cin.fail() && m>=0);
		if (!jo) {
		cout << "Nem jo! " << endl;
		cin.clear();
		cin.ignore(1000, '\n');
		}
	} while (!jo);

	for (int i=0; i<=n; i++)
	{
		kutya[i].resize(m);
		for (int j=0; j<=m; j++)
		{
			bool hiba2;
			f >> kutya[i][j];
			hiba2 = (cin.fail() || kutya[i][j]>10 || kutya[i][j]<0);
			if (hiba2)
			{
				f.close();
				return false;
			}
		}
	}
	for(int i = 0; i<n; ++i){
		kutya[i].resize(m);
		cout << i+1 << ". kutya pontszamai: " << endl;
		for(int j = 0; j<m; ++j){
			//f >> kutya[i][j];
			cout << j+1 << ". kategoria: " << kutya[i][j] << " pont " << endl;
		}
		cout << endl;
	}

	f.close();
	cout << "fasza2";
	return true;
}*/

/*bool beolvfajl (vector<vector<int> > &kutya)
{
	ifstream fajl;
	string fajlnev;
	bool hiba;
	kutya.clear();

	do{
		cout << "Melyik fajlt olvassam be? ";
		cin >> jajlnev;
		fajl.open( fajlnev.c_str() );
		if( hiba = fajl.fail() )
		{
			cout << "Olyat adj " << endl;
			file.clear();
		}
	}while ( hiba );
	int n;
	int m;
	file >> n >> m;
	kutya.resize(n);
	for(int i = 0; i<n; ++i){
		kutya[i].resize(m);
		cout << i+1 << ". kutya pontszamai: " << endl;
		for(int j = 0; j<m; ++j){
			file >> kutya[i][j];
			cout << j+1 << ". kategoria: " << kutya[i][j] << " pont " << endl;
		}
		cout << endl;
	}
	return true;
}*/

/*bool szam (string s)
{

	bool l=true;
	for (size_t i=0; l&& i<s.size();i++)
		l=isdigit(s[i]);
	return l;
}

bool beolvfajl(vector<vector<int> > &kutya)
{
	kutya.resize(0);
	string fajlnev;
	ifstream ifs(fajlnev.c_str());
	if (ifs.fail())
		return false;

	string sor;
	while (getline(ifs, sor))
	{
		kutya.resize(kutya.size()+1);
		stringstream ss(sor);
		string elem;
		while (ss >> elem)
		{
			int n = atoi(elem.c_str());
			//if (0==n && "0"!=elem)
			//if (isdigit(elem[0]))
			if (!szam(elem))
			{
				ifs.close();
				return false;
			} else if (elem>=0 && elem <=10) {
				kutya[kutya.size()-1].push_back(atoi(elem.c_str()));
			}
		//m[m.size()-1][].resize... vagy
		}
	}

	ifs.close();

	return true;
}*/
