#include<iostream>

using namespace std;

/*
	Az [m..n] intervallumon ertelmezett f fuggveny ertekei kozt szamlaljuk meg
	azokat, amelyek pozitivak, ugy hogy a kozvetlenul elozo elem negativ

	TFH az f fv. kiszamitasa bonyolult, ezert szeretnenk ugy megoldani
	ezt a problemat, hogy egyszer kiszamitjuk az ertekeit, elmentjuk,
	es utana csak azokra hivatkozunk

	ha minel tobb mindent kulon fajlba rakunk, az egesz program modularizaltabb,
	igy atlathatobb lesz
*/

//onallo feladatok
//1. szamBeker() megirasa
//2. szamlalas megirasa

int main()
{
	int m;	//allapotter
	int n;
	int c = 0;

	cin>>m>>n;	//ezt csereljuk le...

	//a fuggvenyek mindig globalis entitasok a tablas gyak vilagaban
	//itt nem szeretjuk a globalis dolgokat, ezert egy objektumkent
	//hozzuk letre
	Fuggveny f(m,n);

	//csak ellenorzeskepp
	f.kiir();

	//ez is egy kiiras! - ugyanazt csinalja, mint a felso. Van index operator is, de tokjo nekunk!
	for(int i=m;i<=n;++i)
		cout<<f(i)<<" ";
	cout<<endl;

	//c = szamlalas(f,m,n);	//es mert f lok. valtozo, ezert at kell adni f-et is parameterkent

	cout<<"Darab: "<<c<<endl;

	return 0;
}
