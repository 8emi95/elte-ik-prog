#include <iostream>
#include "enor.h"

using namespace std;

void f(const Vasarlas &v);
size_t db52(const vector<string> &v);
size_t kulonbozoAruk(const vector<string> &v);
bool nemVoltEddig(const vector<string> &v,size_t i);

int main()
{
//    Enor t("be.txt");
//    for(t.First();!t.End();t.Next())
//    {
//        Vasarlas v = t.Current();
//        cout<<v.datum<<" "<<v.vkod;
//        for(size_t i=0;i<v.aruk.size();++i)
//            cout<<" "<<v.aruk[i];
//        cout<<endl;
//    }

    //osszegzes & linker
    bool l = false;
    Vasarlas elem;
    Enor t("be.txt");

    for(t.First();!l && !t.End();t.Next()) //addig megy amíg meg nem találja az elsõ ilyet + 1
    {
        l = kulonbozoAruk(t.Current().aruk) >= 5; //linker belseje
        elem = t.Current();

        f(t.Current()); //osszegzes belseje
    }

    //osszegzes befejezese, miutan a linker mar vegzett
    for(;!t.End();t.Next())
    {
        f(t.Current()); //osszegzes belseje
    }

    if(l)
    {
        cout<<"Az elso olyan vasarlas adatai, ahol legalabb 5 kulonbozo termeket vasaroltak: ";
        cout<<elem.datum<<" "<<elem.vkod<<endl;
    }
    else
        cout<<"Nem volt olyan vasarlas, ahol legalabb 5 kulonbozo termeket vasaroltak."<<endl;

    return 0;
}

//osszegzes belso EDF-je
void f(const Vasarlas &v) //v = t.Current()
{
    size_t db = db52(v.aruk);
    if(db > 0)
        cout<<v.datum<<" "<<v.vkod<<" "<<db<<" "<<endl;
}

//szamlalas
size_t db52(const vector<string> &v)
{
    size_t c = 0;
    for(size_t i=0;i<v.size();++i)
        if(v[i] == "arukod52")
            ++c;
    return c;
}

//ujabb szamlalas
size_t kulonbozoAruk(const vector<string> &v)
{
    size_t c = 0;
    for(size_t i=0;i<v.size();++i)
        if(nemVoltEddig(v,i))
            ++c;
    return c;
}

//opt. linker
bool nemVoltEddig(const vector<string> &v,size_t i)
{
    bool l = true;
    for(size_t j=0;l&&j<i;++j)
        l = v[i] != v[j]; //nem egyezik meg (i) az elõtte lévõk bármelyikével (0-i a j-k)
    return l;
}
