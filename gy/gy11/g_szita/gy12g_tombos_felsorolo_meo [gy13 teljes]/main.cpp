#include<iostream>
#include<vector>
#include"enor_interval.h"
#include"enor_tomb.h"

using namespace std;

int szamlalas_interval(vector<int> v);			//sz�ml�l�s t�tel intervallum felsorol�s�val
int szamlalas_vect(vector<int> v);				//sz�ml�l�s t�tel vektor felsorol�s�val
bool pozitiv(vector<int> v, size_t i);			//vektor i-edik eleme pozit�v-e (ez egy b�ta(i) az intervallumoshoz)
bool pozitiv(int e);							//sz�m pozit�v-e (ez egy b�ta(e) a vektoroshoz, mert ott a sz�mot mag�t, nem az indexet soroljuk fel)
int abs(int e);									//abszolut�rt�k (vektor felsorol�s�hoz)
//int szamlalas(Enor_interval &t, vector<int> v);	//feladat: k�l�n felsorol� objektummal megval�s�tott intervallumbej�r�s sz�ml�l�s
//int szamlalas(Enor_tomb &t);					//feladat: k�l�n felsorol� objektummal megval�s�tott vektorbej�r�s sz�ml�l�s
//int maxkiv(Enor_tomb &t);						//feladat: k�l�n felsorol� objektummal megval�s�tott vektorbej�r�s maxkiv

//feladat: a k�t bej�r� oszt�ly
//feladat: egy maxkiv �s sz�ml�l�s "p�rhuzamosan" a foprogramba

int main()
{
	vector<int> v;		//a bemenet...
	v.push_back(0);
	v.push_back(3);
	v.push_back(-1);
	v.push_back(-5);
	v.push_back(5);
	v.push_back(-4);
	v.push_back(2);
	v.push_back(-9);
	v.push_back(-4);

	for(size_t i=0;i<v.size();++i)	//ellenorzo kiiras, amugy ez egy osszegzes tetel vegul is
		cout<<v[i]<<" ";
	cout<<endl;

	Enor_interval ti(0,v.size()-1);
	for(ti.First();!ti.End();ti.Next())	//intervallum felsorolo ellenorzese
		cout<<ti.Current()<<" ";
	cout<<endl;

	Enor_tomb tv(v);
	for(tv.First();!tv.End();tv.Next())	//vektor felsorolo ellenorzese
		cout<<tv.Current()<<" ";
	cout<<endl<<endl;

	cout<<szamlalas_interval(v)<<endl;	//a meg�rt, sima sz�ml�l�sok kipr�b�l�sa
	cout<<szamlalas_vect(v)<<endl;

	//Enor_interval t1(0,v.size()-1);		//intervallumfelsorol� - [0..n-1]-et kell neki felsorolnia, a vektorr�l "nem is tud"!
	//cout<<szamlalas(t1,v)<<endl;		//cser�be itt meg kell adni a vektort.

	//Enor_tomb t2(v);					//vektorfelsorol�
	//cout<<szamlalas(t2)<<endl;			//most m�r nem kell megadni, csak a felsorol�t - "cser�be" nem tudunk indexet lek�rni

	//Enor_tomb t3(v);					//az�rt csin�lok minden t�telhez �j felsorol� objektumot, mert majd a f�jlosn�l
	//cout<<maxkiv(t3)<<endl;				//nem lesz garant�lva, hogy �jraindul a f�jl olvas�s, egy haszn�lt felsorol�n�l.
										//itt speciel a first mindig 0-zza i-t, tehat ilyen gond nem lenne.
	//maxkiv �s sz�ml�l�s egy�tt:

	//MEGIRNI

    return 0;
}

int szamlalas_interval(vector<int> v)	//lehet forral is
{
	int c = 0;

	size_t i = 0;
	while(i<v.size())
	{
		if(pozitiv(v,i))	//beta(i)
				++c;
		++i;
	}

	return c;
}

int szamlalas_vect(vector<int> v)	//ezt is lehet persze forral is
{
	int c = 0;

	size_t i = 0;
	while(i<v.size())
	{
		if(pozitiv(v[i]))	//beta(e)
				++c;
		++i;
	}

	return c;
}

int abs(int e)
{
	return e > 0 ? e : -e;
}

bool pozitiv(vector<int> v, size_t i)
{
	return v[i] > 0;
}

bool pozitiv(int e)
{
	return e > 0;
}

/*int szamlalas_absztr(Enor &t)
{
	int c = 0;

	t.First();
	while(!t.End())
	{
		if(pozitiv(t.Current()))
				++c;
		t.Next();
	}

	return c;
}

int szamlalas_absztr_forral(Enor &t)		//csak mert ugyanaz, de igy rovidebb
{
	int c = 0;

	for(t.First();!t.End();t.Next())
		if(pozitiv(t.Current()))
				++c;

	return c;
}*/

/*int szamlalas(Enor_interval &t, vector<int> v)
{
}*/

/*int szamlalas(Enor_tomb &t)
{
}*/

/*int maxkiv(Enor_tomb &t)
{
}*/
