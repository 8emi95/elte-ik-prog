#include <iostream>
#include <fstream>
#include <sstream>
#include "enor_string.h" //beilleszti sz�vegszer�en a ff�jlok tartalm�t, ha van status b�rmelyikben akk m�r nem j�
#include "enor_file.h"
#include "enor_mondat.h"
#include "kozos.h"

using namespace std;

//int mondathossz(string mondat);

int main()
{
//	//1. irjuk ki seqoutfile-ba ezt a szoveget csupa nagybetuvel
//	string bemenet = "Du. Du hast. Du hast mich. Du hast mich gefragt. Und ich hab nichts gesagt.";
//
//	//erdemes mindig irni egy gyors ellenorzest, hogy jo-e a felsorolo...
////	Enor_string t(bemenet);
////	for(t.First();!t.End();t.Next())
////        cout<<t.Current();
////    cout<<endl;
//
//    ofstream ofs("ki.txt");
//    Enor_string t(bemenet);
//	for(t.First();!t.End();t.Next())
//        ofs<<(char)toupper(t.Current());    //charra kell konvertalni, kulonben az ASCII-kodjat irna ki
//
//	//2. irjuk ki a konzolra a fajl tartalmat csupa nagybetuvel
//	//Enor_file tf("asd.txt");	//erre hibas, nem csinal semmit -> First utan mar igaz az End
//	Enor_file tf("be.txt");
//
//	for(tf.First();!tf.End();tf.Next())
//        cout<<(char)toupper(tf.Current());    //charra kell konvertalni, kulonben az ASCII-kodjat irna ki
//    cout<<endl;

//	//3/a. mondjuk meg, hany 20 betusnel hosszabb mondat van a fajlban (mondatok felsorolasaval)
//	Enor_mondat tm("be.txt"); //l�tre kell hozni
//
//	for(tm.First(); !tm.End(); tm.Next())
//        if(mondathossz(tm.Current()) > 20)
//            ++c;
//
//	int c = 0;
//	cout<<c<<endl;

	//3/b. mondjuk meg, hany 20 betusnel hosszabb mondat van a fajlban (mondathosszak felsorolasaval)
	//Enor_mondathossz tmh("be.txt");
	int ch = 0;
	cout<<ch<<endl;

    return 0;
}

//int mondathossz(string mondat)
//{
//    int hossz = ;
//
//    stringstream ss(mondat);
//    char ch;
//    ss >> ch;
//    while(ss >> ch)
//    {
//        if(',' != ch)
//            ++hossz;
//    }
//
//    return hossz;
//}
