#include<iostream>
#include<vector>

using namespace std;

struct Par
{
	int a;
	int b;
};

struct Par2
{
	int a;
	int b;
	Par2(int sz) {a = sz; b = sz; }
};

int main()
{
	vector<int> v1;		//ures, szamokat tartalmazo vektor
	vector<Par> v2;		//ures, szamparokat tartalmazo vektor
	vector<int> v3(5);	//5 db 0-t tartalmazo vektor
	int v4[5];			//5 darab veletlenszamot tartalmazo tomb!
	vector<Par2> v5;	//ures, Par2-ket tartalmazo vektor
	//vector<Par2> v6(5);	//nincs neki un. default konstruktora -> nem tud "nullara inicializalni", le se fordul

	for(int i=0;i<5;++i)
		cout<<"v3["<<i<<"]: "<<v3[i]<<" | v4["<<i<<"]: "<<v4[i]<<endl;	//tomb random, vector 0-ra van inicializalva
        //v3[0]: 0 | v4[0]: 4199040
        //v3[1]: 0 | v4[1]: 4288368
        //v3[2]: 0 | v4[2]: 0
        //v3[3]: 0 | v4[3]: 7012012
        //v3[4]: 0 | v4[4]: 1975547013

	cout<<"- - -"<<endl;
	cout<<v2.size()<<endl;	//most 0 elemu
	//0
	//v2[0].a = 5;			//ezert nem is indexelhetem, elszall
	v2.resize(1);			//most mar van benne egy elem
	cout<<v2[0].a<<" "<<v2[0].b<<endl;	//megpedig a (0,0) par (mert 0-ra inicializal mindent)
	//0 0

	cout<<"- - -"<<endl;
	v2.resize(5);
	for(int i=0;i<5;++i)	//mondjuk igy lehet feltolteni, ha eleve tudom a meretet
	{
		v2[i].a = i;
		v2[i].b = 4-i;
	}
	for(int i=0;i<v2.size();++i)	//nem kell kulon valtozoban tarolni a meretet!
		cout<<v2[i].a<<" "<<v2[i].b<<endl;
        //0 4
        //1 3
        //2 2
        //3 1
        //4 0

	cout<<"- - -"<<endl;
	int sz;				//rugalmasabb feltoltesi fajta:
	while(cin>>sz)		//amig sikeres a beolvasas (amig szamot irok be),
	{					//addig toltom fel -> nem kell elore ismerni a meretet!!!
		v1.resize(v1.size()+1);		//elobb novelem eggyel
		v1[v1.size()-1] = sz;		//majd az akt. utolso elemre berakom
	}
	//konzolra be�rtak:
    //4
    //5
    //dsdksskd
	for(int i=0;i<v1.size();++i)
		cout<<v1[i]<<endl;
        //4
        //5

	cout<<"- - -"<<endl;		//most jon az elozo elvnek megfelelo, de egyszerubb megoldas:
	v1.resize(0);				//(ne felejtsuk el vektorunkat kiuriteni elobb!
	cin.clear();				//meg a cint is "megjavitani")
	cin.ignore(1000,'\n');

	while(cin>>sz)
	{
		v1.push_back(sz);		//ettol noveli is a meretet es a vegere is rak
	}
	//konzolra be�rtak:
    //6
    //7
    //sddsk
	for(int i=0;i<v1.size();++i)	//annyi lesz a meret, ahany szamot beirtunk
		cout<<v1[i]<<endl;
        //6
        //7
	cout<<"- - -"<<endl;

	if(v1.empty())					//ugyanaz mint a v.size()==0 csak rovidebb :)
		cout<<"v1 ures"<<endl;
	else
		cout<<"v1 nem ures"<<endl; //ezt �rja ki
	v1.clear();						//mint a resize(0)
	if(v1.empty())
		cout<<"most mar a v1 ures"<<endl; //ki�rja
	cout<<"- - -"<<endl;

	for(int i=0;i<v3.size();++i)	//most osszegezzuk a szamokat 0-tol 4-ig
		v3[i] = i;

	int s=0;
	while(!v3.empty())	//amig nem ures
	{
		s += v3.back();	//addig az akt. utolsot beleirjuk
		v3.pop_back();	//majd kiszedjuk az akt. utolsot (ez csokkenti a meretet is
	}
	cout<<"osszeg: "<<s<<endl;	//a vegen itt lesz 0+1+2+3+4
	//osszeg: 10

	cout<<"- - -"<<endl;
	//v5.resize(1);	//ezt tovabbra se szeretjuk mert Par2-t nem lehet 0-ra inicializalni
	Par2 p(1);
	v5.push_back(p);	//viszont ha rendesen letrehozom, akkor megy a beillesztes
	cout<<v5[0].a<<" "<<v5[0].b<<endl;	//(1,1) par van benne
	//1 1

	return 0;
}
