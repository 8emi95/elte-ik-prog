#include<iostream>
#include<cstdlib>

using namespace std;

int main()
{
    int n,k,h;	//deklaralom az allapotter elemeit, rendre alap, kitevo, hatvany
				//nem kotelezo persze itt es most, raer az elso hasznalat elott kozvetlenul is

    cout<<"Kerem adja meg a hatvanyalapot! (tetszoleges egesz szam)"<<endl;
    cin>>n;
    if(cin.fail())	//hiba: tipus
    {
        cout<<"Nem szam... a program most kilep mielott nagyobb baj lenne :("<<endl;
        exit(1);	//erdemes minden hibalehetoseghez egyedi "hibakodot" kitalalni
    }

    cout<<"Kerem adja meg a hatvany kitevojet! (nem negativ egesz szam)"<<endl;
    cin>>k;
    if(cin.fail() || k<0)	//hiba: tipus (nem int vagy nem nemnegativ)
    {
        cout<<"Nem jo a szam... pedig mar nagyon kozel voltunk a celhoz... :'("<<endl;
        exit(2);
    }

	//a struktogram, egy osszegzes tetel
    h = 1;
    for(int i=1; i<=k; ++i)	//most tenyleg 1-tol k-ig megyunk, mert nem tombindexekrol van szo
        h *= n;

	//kulturaltan kiiratom a megoldast
    cout<<"Ijja! Sikerult kiszamolni a hatvanyt. Es ez az: "<<h<<endl;

    return 0;
}
