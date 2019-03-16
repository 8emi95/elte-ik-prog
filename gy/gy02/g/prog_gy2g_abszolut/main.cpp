#include<iostream>
#include<cstdlib>
#include<vector>

using namespace std;

//elorevetett deklaracio
int myAbs(int);
//int myAbs2(vector<int>, int);

int main()
{
    int n;		//vektor merete, magat a vektort majd dinamikusan, n ismereteben deklaralom.
    cout<<"Add meg a tomb meretet (termeszetes szam): ";
    bool hiba = false;	//segedvaltozo a beolvasashoz
    do	//hatultesztelos ciklus: egy alkalommal mindenkeppen lefut a belseje
    {
        cin>>n;
        hiba = cin.fail() || n<0;	//itt a hibas eset
        if(hiba)
        {
            cout<<"Elrontottad, add meg ujra!: ";	//ellentetben az elozovel,
            cin.clear();								//most nem hanyatt-homlok kilepunk,
            cin.ignore(1000,'\n');						//hanem lehetoseget biztositunk a javitasra
        }
    }
    while(hiba);

    vector<int> v(n);		//na itt a vektor, hurra
    for(int i=0;i<n;++i)	//minden elemere kulon-kulon egy-egy do-while.
    {						//ha a for es a do forditva lenne, akkor minden hibas beolvasasnal
        cout<<"Add meg a tomb "<<i+1<<". elemet! (egesz szam): ";	//ujrakezdene az egesz
        do					//tomb beolvasasat. az is egy megoldas, de talan igy baratsagosabb
        {
            cin>>v[i];
            hiba = cin.fail();
            if(hiba)
            {
                cout<<"Elrontottad, add meg ujra!: ";	//lathato, nagyon hasonlo ez a kod, meg az elozo.
                cin.clear();							//ossze lehetne ezeket vonni egy fuggvenybe
                cin.ignore(1000,'\n');
            }
        }
        while(hiba);
    }

    //mindig celszeru ellenorizni a beolvasas utan, mert akkor legalabb az biztos, hogy az a resz jo.
    //es ha amugy nem jo a program, akkor innen biztosan tudod, hogy a struktogramot kodoltad le rosszul,
    //nem a jarulekos dolgokat
	cout<<"A beolvasott tomb: ";
	for(int i=0;i<n;++i)
		cout<<v[i]<<" ";
	cout<<endl;

    //struktogram
    int o = 0;
    for(int i=0;i<n;++i)
    {
		//1. ha hasznalhatjuk a gyari |.| fuggvenyt, akkor ez egy "megengedett" utasitas, azaz fordul, fut
		/*
		o += abs(v[i]);	//cstdlib
		*/

		//2. mivel myAbs egy esetszetvalasztassal volt definialva, ezt az esetszetvalasztast helyben elvegezhetjuk:
		//ez ebben az esetben egy meltanyolhato megoldas, csak ilyenkor meglehet, sok lesz a kodismetles.
		//ezen kivul altalaban egy ciklus melyseg folott mar atlathatosag (strukturaltsag) miatt erdemes a belso szamitasokat fuggvenybe kirakni
		/*
        if(v[i] >= 0)
            o += v[i];
        else
            o -= v[i];
		*/

		//3. a teljes ertekadas "nem megengedett" (nem definialt) reszet jelento kifejezes kiszamitasat kirakhatjuk egy fuggvenybe,
		//ennek erteket elmentjuk egy valtozoba, es igy a nem megengedett kifejezes most mar csak azt tartalmazza, amitol nem megengedett
		//ezt a "transzformaciot" hivjak "fuggveny helyettesitese valtozoval"-nak
		/*
		int a = myAbs(v[i]);
		o += a;
		*/

		//4. mivel most eletszeru - csak egy helyen van hasznalva - a valtozokepzest el is hagyhatjuk,
		//hasznalhatjuk inline is a kitranszformalt fuggveny eredmenyet
		o += myAbs(v[i]);

		//5. ez az elozohoz hasonlo, csak a fuggveny szignaturaja mas - a 4. megoldas a legjobb, itt feltelelezzuk azt, hogy egy
		//tomb (vektor) i-edik elemerol van szo, mig az elozo altalanosabb: az tetszoleges szamra mukodik, amikor amugy tudjuk, hogy
		//egy vektor eleme, de massal is mukodne
    	/*
		o += myAbs2(v,i);
		*/
    }

    cout<<"Az abszoluteretek osszegei: "<<o<<endl;

    return 0;
}

/*
	segedfuggveny, mely egy n elemu vektor i-edik ertekenek absz. erteket adja vissza
	elofeltetel: i eleme [1..n] (papiron) i eleme [0..w.size()-1] (itt)
	ha ez nem teljesul, akkor barmilyen hiba is tortenhet
	kesobb majd ilyenkor "dobunk kivetelt"
*/

/*
int myAbs2(vector<int> w, int i)
{
    return w[i] >= 0 ? w[i] : -w[i];	//?: operator, ami az egyetlen ternaris (haromoperandusu) muvelet
}										//alakja: logikai allitas ? ertek, ha igaz : ertek, ha hamis (a ket ertek tipusa azonos kell legyen)
*/

/*
	hasonlo, mint a fenti, de joval altalanosabb, mert nem egy vektor i-edik
	elemenek absz. erteket adja vissza, hanem tetsz. szamet, ami lehet akar
	vektor eleme, akar "csak egy" szam.
	tobbnyire ilyen segedfuggvenyeket fogunk hasznalni, mert egyszerubb
*/

int myAbs(int szam)
{
    return szam >= 0 ? szam : -szam;
}
