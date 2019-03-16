#include"enor.h"
#include<cstdlib>
#include<sstream>
//potencialisan mast is be kellhet include-olni...

using namespace std;

Enor::Enor(string fnev)
{
    x.open(fnev.c_str());
    if(x.fail())
    {
        cerr<<"A megadott fajl nem letezik."<<endl;
        //esetleg csak igazra allitom a vege-t, es a foprogramban kezelem le
        //esetleg dobok egy exceptiont
        exit(1);
    }
}

Enor::~Enor()
{
    x.close();
}

void Enor::First()
{
    vege = false;
    Next();
}

void Enor::Next()
{
//    //sablon
//    x >> akt; //operátor nicns aminek a bal oldalán ifstrem lenne
//    if(x.fail())
//        vege = true;
//    //sablon end

    string sor;
    getline(x,sor);
    if(x.fail())
        vege = true;
    else
    {
        stringstream ss(sor);
        //ss-bol kiolvassuk rendre az elemeket, es feldolgozzuk.
        //Ennek lehetseges modjait lasd a konkret peldafeladatokban.

        //cout << sor; //ell, kiírja a sorokat
        ss >> akt.iparag; //ki tudja írni az egyik adattagot
        akt.keruletek.clear(); //le kell nullázni kül az elsõ sor kerületei mögé írja
        for(int i = 0; i < 10; ++i)
        {
            int sv;
            ss >> sv;
            akt.keruletek.push_back(sv);
        }
        ss >> akt.konk;
    }
}

//istream& operator>>(istream & ifs, Adat & a);
//{
//    string sor;
//    getline(ifs,sor);
//    if(ifs.fail())
//        vege = true;
//    else
//    {
//        stringstream ss(sor);
//        ss >> akt.iparag;
//        akt.keruletek.clear();
//        for(int i = 0; i < 10; ++i)
//        {
//            int sv;
//            ss >> sv;
//            akt.keruletek.push_back(sv);
//        }
//        ss >> akt.konk;
//    }
//    return ifs;
//}
//ostream& operator<<(ostream & ofs, const Adat & a);
//{
//    for(t.First();!t.End();t.Next())
//    {
//        cout << t.Current().iparag << " ";
//        for(size_t i = 0; i < t.Current().keruletek.size(); ++i)
//            cout << t.Current().keruletek[i] << " ";
//        cout << t.Current().konk << endl;
//}

//int-párok
//Nadal Ferrer 6 3 7 6 6 7 6
//
//vector<Par> v;
//struct Par { int p1; int p2 };
//
////olvasol egy sv-t
//while(!ss.fail())
//{
//	//olvasol sv2-t
//	Par p;
//	p.p1 = sv;
//	p.p2 = sv2;
//	v.push_back(p);
//	//olvasol sv-t
//}
