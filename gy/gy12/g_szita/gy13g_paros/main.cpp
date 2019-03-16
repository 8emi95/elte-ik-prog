#include <iostream>
#include"enor.h"

using namespace std;

int main()
{
    const string fnev = "be.txt";

	//enor tesztelese:
	Enor t1(fnev);
	for(t1.First();!t1.End();t1.Next())
		cout<<t1.Current()<<" ";
	cout<<endl<<"- - -"<<endl;

	//osszegzes
	/*
		H ~ L
		+ ~ es
		0 ~ true
		f ~ t.Current() mod 2 = 0
	*/
	Enor t2(fnev);
	bool s = true;
	for(t2.First();!t2.End();t2.Next())
		s &= t2.Current() % 2 == 0;
	if(s)
		cout<<"Igen."<<endl;
	else
		cout<<"Nem."<<endl;
	cout<<"- - -"<<endl;

	//pesszimista linker
	/*
		beta ~ t.Current() mod 2 != 0
	*/
	Enor t3(fnev);
	bool l3 = false;
	for(t3.First();!l3 && !t3.End();t3.Next())
		l3 = t3.Current() % 2 != 0;
	if(l3)	//ha talalt ellenpeldat
		cout<<"Nem."<<endl;
	else
		cout<<"Igen."<<endl;
	cout<<"- - -"<<endl;

	//opt. linker
	/*
		beta ~ t.Current() mod 2 == 0
	*/
	Enor t4(fnev);
	bool l4 = true;
	for(t4.First();l4 && !t4.End();t4.Next())
		l4 = t4.Current() % 2 == 0;
	if(l4)	//ha mind paros volt
		cout<<"Igen."<<endl;
	else
		cout<<"Nem."<<endl;
	cout<<"- - -"<<endl;

	//szamlalas
	/*
		c szamlalo: beta ~ t.Current() mod 2 == 0
		db szamlalo: beta ~ true
	*/
	int c = 0;
	int db = 0;
	Enor t5(fnev);
	for(t5.First();!t5.End();t5.Next())
	{
		if(t5.Current() % 2 == 0)
			++c;
		++db;
	}
	if(c == db)	//ha mind paros volt
		cout<<"Igen."<<endl;
	else
		cout<<"Nem."<<endl;
	cout<<"- - -"<<endl;

    return 0;
}
