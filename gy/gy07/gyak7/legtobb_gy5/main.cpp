
using namespace std;

void beolv_g(vector<int> &v);
void beolv_g2(vector<int> &v);
//void beolv_f(vector<int> &v);
//void beolv_f2(vector<int> &v);
void kiir(const vector<int> &v);

//1. feladat - irjuk meg a teteleket
//2. feladat - irjuk meg a fajlbol bekerest!
//(elore nem ismert meret, az elso helytelenig olvasas)

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

void kiir(const vector<int> &v)
{
	for(size_t i=0;i<v.size();++i)
		cout<<v[i]<<" ";
}
