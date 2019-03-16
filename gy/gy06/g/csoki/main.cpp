#include<iostream>
#include<vector>
#include<fstream>

using namespace std;

void beolvasas_g(vector<vector<int> > &mx);
void torol(const vector<vector<int> > &mx);
bool beolvasas_f(vector<vector<int> > &mx);
void kiiras(const vector<vector<int> > &mx);
bool vantokeletes(const vector<int> sor);
bool tokeletes(int e);

//1. feladat - irjuk meg a teteleket
//2. feladat - irjuk meg a fajlbol bekerest!
//(elore ismert meret, hiba eseten kilepes)

int main()
{
	vector<vector<int> > &mx;
	cout << "Add meg a fajlnevet: ";
	string fnev;
	cin >> fnev;
	if (beolvasas_f("f5.txt", mx)
     {
         kiiras(mx);
         if(mindensorbanvantokeletes(mx))
            cout << "Minden sorban van."
           else
           cout << "Nem minden sorban van."

     }
	int n;

	beolvasas_g(mx);
	//if(beolvasas_f(mx))
	//{
		kiiras(mx);
	//	...tetel hivasa...
	//}
	//else
	//	cout<<"Hibas file"<<endl;



	return 0;
}

void kiiras(const vector<vector<int> > &mx)
{
	for(size_t i=0;i<mx.size();++i)
	{
		for(size_t j=0;j<mx[i].size();++j)
		{
			cout<<mx[i][j]<<" ";
		}
		cout<<endl;
	}
}

void torol (const &)

void beolvasas_g(vector<vector<int> > &mx)
{
	for(size_t i=0;i<mx.size();++i)
		mx[i].resize(0);
	mx.resize(0);

	int n;
	bool hiba;

bool beolvasas_f(string fnev, vector<vector<int> > &mx)
{
    torol (mx);
    ifstream ifs (fnev.c_str());
    if(ifs.fail())
        return false;
    int n;
    ifs >> n;
    if (ifs.fail() || n < 0)
    {
        return false;
    }
    mx.resize(n);
    for (int i=0; i<n; i++)
    {
        mx[i].resize(n);
        for (int j=0; j<n; j++)
        {
            ifs >> mx[i][j];
            if (cin.fail() || mx[i][j]<0)
            {
                ifs.close();
                return false;
            }
        }
    }

    char c;
    ifs >> c;
    bool vege = ifs.fail();
    ifs.close();
    return vege;
}

bool mindensorbanvantokeletes (const vector<vector<int> > &mx)
{
    bool minden = true;
    for (size_t i=0; minden && i<mx.size(); i++)
    {
        minden = vantokeletes(mx[i]);
    }
    return minden;
}

bool vantokeletes(const vector<int> sor)
{
    bool van = false;
    for (size_t i=0; !van && i<sor.size(); i++)
    {
        van = tokeletes(sor[i]);
    }
    return van;
}

bool tokeletes(int e)
{
    int s = 0;
    for (int i=1; i<e; i++)
        if (0 == e % i)
        s +=i;
    return s == e;
}
