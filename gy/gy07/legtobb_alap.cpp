#include<iostream>
#include<vector>

using namespace std;

void beolv_g(vector<int> &v);
void beolv_g2(vector<int> &v);
void beolv_f(vector<int> &v);
void beolv_f2(vector<int> &v);
void kiir(const vector<int> &v);

//feladat: irjuk meg a teteleket

int main()
{
	vector<int> v;
	beolv_g(v);
	//beolv_g2(v);
	kiir(v);
	//...tetel hivasa...

	return 0;
}

void beolv_g(vector<int> &v)
{
	cout<<"Ird be a szamokat! Az elso helytelennel kilepek."<<endl;
	v.resize(0);
	int n;
	while(cin>>n && n % 2 == 0)
		v.push_back(n);
	cout<<"Hibas ertek, beolvasas vege"<<endl;
}

void beolv_f(vector<int> &v)
{
	string fnev;
	ifstream ifs;
	cout<<"Add meg a file nevet!"<<endl;
	cin>>fnev;
	ifs.open(fnev.c_str());

	v.resize(0);
	int n;
	while(ifs>>n && n % 2 == 0)
		v.push_back(n);
	ifs.close();
}

void beolv_g2(vector<int> &v)
{
	cout<<"Ird be a szamokat! Az elso helytelennel kilepek."<<endl;
	v.resize(0);
	int n;
	bool hiba;

	do
	{
		cin>>n;
		hiba = cin.fail() || n % 2 != 0;
		if(hiba)
		{
			cin.ignore(1000,'\n');
			//vagy: string str; getline(cin,str);
			cin.clear();
			cout<<"Hibas ertek, beolvasas vege"<<endl;
		}
		else
			v.push_back(n);
	}
	while(!hiba);
}

void beolv_f2(vector<int> &v)
{
	string fnev;
	ifstream ifs;
	cout<<"Add meg a file nevet!"<<endl;
	cin>>fnev;
	ifs.open(fnev.c_str());

	v.resize(0);

	int n;
	bool hiba;
	do
	{
		ifs>>n;
		hiba = ifs.fail() || n % 2 != 0;
		if(!hiba)
			v.push_back(n);
	}
	while(!hiba);

	ifs.close();
}

void kiir(const vector<int> &v)
{
	for(size_t i=0;i<v.size();++i)
		cout<<v[i]<<" ";
}
