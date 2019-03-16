#include<iostream>
#include<cstdlib>

using namespace std;

const int MAXN = 100;		//vectorhoz ez mar nem fog kelleni... legalabbis technikai okokbol biztos nem
int n;						//ez se feltetlen, vagy legalabbis max. mint segedv.
//string s;
//ilyen segedvaltozokat aztan vegkepp ne deklaraljunk soha globalisnak;
//eleg csak ott es akkor amikor szukseg van ra, itt pl. a beolvaso fv. egy ilyen pelda.
//felesleges memoriapazarlas, es ami fontosabb: atlathatatlanabb lesz miatta a kod
int t[MAXN];

/*
void beolvasas()
{
	cin>>s;					//ez igy nem szep megvalositas, mert ekkor mind s, mind n, mind t globalis
	n = atoi(s.c_str());
	//* tomb feltoltese *
}
*/

void beolvasas2(int &n, int t[MAXN])
{
	string s;	//ez hogy itt vezetem be az s-t, nem kinn, egyfajta "enkapszulacio"
	cin>>s;
	n = atoi(s.c_str());
	//* tomb feltoltese *
}

int beolvasas3(int t[MAXN])	//kompaktabb megoldas
{
	string s;
	cin>>s;
	int n = atoi(s.c_str());
	//* tomb feltoltese *
	return n;					//n valtozot raerek a hivas helyen letrehozni es ez meg lesz a kezdoerteke
}

int j=-1;		//kulso j
namespace N
{
	int j=0;	//N-beli j
	void asd()
	{
		for(int j=1;j<=5;++j)	//j elfedese
		{
			cout<<::j<<" "<<N::j<<" "<<j<<endl;
//			  -1 0 1
//            -1 0 2
//            -1 0 3
//            -1 0 4
//            -1 0 5
		}
		cout<<::j<<" "<<N::j<<" "<<j<<endl;	//itt most N::j === j
//		-1 0 0
	}
}

//using namespace N;

int main()
{
	N::asd();
	//asd();			//usinggal... hasonlo mint az std::cout...

	{
        int i;			//ez igy egy blokk. i csak a zaro zarojelig el
    }


	//1-5-ig a szamok. i a forban el csak (mert a for maga egy blokk)
    for(int i=1;i<=5;++i)
	{
		cout<<i<<endl;
//		  1
//        2
//        3
//        4
//        5
	}

	/*
	//ugyanez, de ez le se fordul, hiszen a for utan i nem letezik mar, nem is hivatkozhatunk rea
    for(int i=1;i<=5;++i)
	{
		cout<<i<<endl;
	}
	cout<<i<<endl;
	*/

	/*
	//vegen i==6 lesz es ezt irja ki, hiszen i a foron kivul jott letre
	int i=0;
    for(i=1;i<=5;++i)
	{
		cout<<i<<endl;
	}
	cout<<i<<endl;
	*/

	/*
	//ez ket kulon i (elfedes), a belso "meghal" a for vegen, a kulsot kirjuk, erteke 0
	int i=0;
    for(int i=1;i<=5;++i)
	{
		cout<<i<<endl;
	}
	cout<<i<<endl;
	*/

	//ez megy
	{
		int k;
		{
			int k;
		}
	}
	int k;

	/*
	//ez nem
	{
		int k;			//ezt
		{
			int k;
		}
		int k;			//ez feluldeklaralna
	}
	int k;
	*/

    return 0;
}
