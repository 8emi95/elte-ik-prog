#include <iostream>
#include <vector>

using namespace std;

/*
	4. Madarak életének kutatásával foglalkozó szakemberek n különbözõ településen m
	különbözõ madárfaj elõfordulását tanulmányozzák. Egy adott idõszakban megszámolták,
	hogy az egyes településen egy madárfajnak hány egyedével találkoztak. Melyik az a
	madárfaj, amelyik a leggyakrabban (azaz a legtöbb településen) fordult elõ?
*/

void szamlal(vector<vector<int> > v, vector<int> &hany, int n, int m);
int maxkiv(vector<int> &hany, int m);

int main()
{
	//beolvasás
	int n, m;
	vector<vector<int> > v;
	bool hiba1;
	cout << "Add meg a telepulesek szamat (n): ";
	do
	{
		cin >> n;
		hiba1 = cin.fail() || n <= 0;
		if (hiba1)
		{
			cout << "Nem jo. Add meg ujra telepulesek szamat: ";
			cin.clear();
			cin.ignore(1000, '\n');
		}
	}while(hiba1);

	cout << "Add meg a madarfajok szamat (m): ";
	do
	{
		cin >> m;
		hiba1 = cin.fail() || m <= 0;
		if (hiba1)
		{
			cout << "Nem jo. Add meg ujra madarfajok szamat: ";
			cin.clear();
			cin.ignore(1000, '\n');
		}
	}while(hiba1);
	cout << "-----" << endl;

	v.resize(m);
	for (int i = 0; i < v.size(); ++i)
	{
		v[i].resize(n);
	}

	//vektorméret ellenőrzése
	cout << "Vektormeret ellenorzese:\n" << v.size() << endl;
	for (int i = 0; i < m; ++i)
	{
		cout << v[i].size() << " ";
	}
	cout << "\n-----" << endl;

	cout << "Az alabbiakban termeszetes szamokat adj meg!" << endl;
	for (int i = 0; i < m; ++i)
	{
		cout << "A(z) " << i + 1 << ". madarfaj elofordulasai:" << endl;
		for (int j = 0; j < n; ++j)
		{
			bool hiba2;
			do
			{
			    cout << "Add meg a(z) " << j + 1 << ". telepulesen valo elofordulast: ";
				cin >> v[i][j];
				hiba2 = cin.fail() || v[i][j] < 0;
				if (hiba2)
				{
					cout << "Nem jo. ";
					cin.clear();
					cin.ignore(1000, '\n');
				}
			}while(hiba2);
		}
		cout << "-----" << endl;
	}

	//beolvasás ellenőrzése
	cout << "Beolvasas ellenorzese:" << endl;
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
	cout << "-----" << endl;

	//madarfajok hány településen fordultak elő - SZÁMLÁLÁS
	vector<int> hany(m);
	szamlal(v, hany, n, m);

	//számlálás ellenőrzése
	cout << "Szamlalas ellenorzese:" << endl;
	for (int i = 0; i < m; ++i)
	{
		cout << hany[i] << " ";
	}
	cout << "\n-----" << endl;

	//leggyakoribb madárfaj - MAXIMUMKIVÁLASZTÁS
	int leggyakoribb = maxkiv(hany, m);
	cout << "A leggyakoribb madarfaj sorszama: " << leggyakoribb + 1 << endl;

	return 0;
}

void szamlal(vector<vector<int> > v, vector<int> &hany, int n, int m)
{
	for(int i = 0; i < m; ++i)
	{
		int db = 0;
		for(int j = 0; j < n; ++j)
		{
			if(v[i][j] > 0)
			{
				db++;
			}
		}
		hany[i] = db;
	}
}

int maxkiv(vector<int> &hany, int m)
{
	int max = hany[0];
	int leggyakoribb = 0;
	for(int i = 1; i < m; ++i)
	{
		if(hany[i] > max)
		{
			leggyakoribb = i;
			max = hany[i];
		}
	}
	return leggyakoribb;
}
