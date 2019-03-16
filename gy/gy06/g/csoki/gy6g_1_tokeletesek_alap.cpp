#include<iostream>
#include<vector>
#include<fstream>

using namespace std;

void beolvasas_g(vector<vector<int> > &mx);
//bool beolvasas_f(vector<vector<int> > &mx);
void kiiras(const vector<vector<int> > &mx);

//1. feladat - irjuk meg a teteleket
//2. feladat - irjuk meg a fajlbol bekerest!
//(elore ismert meret, hiba eseten kilepes)

int main()
{
	vector<vector<int> > mx;
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

void beolvasas_g(vector<vector<int> > &mx)
{
	for(size_t i=0;i<mx.size();++i)
		mx[i].resize(0);
	mx.resize(0);

	int n;
	bool hiba;
	cout<<"Hanyszor hanyas?"<<endl;
	do
	{
		cin>>n;
		hiba = cin.fail() || n<0;
		if(hiba)
		{
			cin.clear();
			cin.ignore(1000,'\n');
			cout<<"Nem jo. Ujra!"<<endl;
		}
	}
	while(hiba);

	mx.resize(n);

	for(int i=0;i<n;++i)
	{
		mx[i].resize(n);
		for(int j=0;j<n;++j)
		{
			do
			{
				cin>>mx[i][j];
				hiba = cin.fail() || mx[i][j]<0;
				if(hiba)
				{
					cin.clear();
					cin.ignore(1000,'\n');
					cout<<"Nem jo. Ujra!"<<endl;
				}
			}
			while(hiba);
		}
	}
}
