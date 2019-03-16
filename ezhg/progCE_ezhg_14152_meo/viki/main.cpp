#include <iostream>
#include <cstdlib>
#include "infile.h"

using namespace std;

void kiir(vasarlas elem);
void osszegzes(vasarlas elem);
bool optlinker(vasarlas elem);
int szamol(vasarlas elem);
int agyszam(vasarlas elem,const int i);

int main()
{
    infile x("");
    vasarlas elem;
    //min.kerhez
    int minimum;
    string i,k;

    x.First();

    minimum=szamol(x.Current());
    i=x.Current().ido;
    k=x.Current().kod;

    if(x.End())
    {
        cout <<"Ures fajl!"<<endl;
        exit(2);
    }
    cout << "1.feladat: "<<endl;
    while (!x.End())
    {
        elem=x.Current();
        //kiir(elem);
        osszegzes(elem);
        if(szamol(elem)<minimum)
        {
            minimum=szamol(elem);
            i=elem.ido;
            k=elem.kod;
        }
        x.Next();
    }
    cout << "2.feladat: "<<endl;
    cout<<i<<"\t"<<k<<"\t"<<minimum<<endl;
    return 0;
}

void kiir(vasarlas elem)
{
    cout<<elem.ido<<"\t"<<elem.kod<<"\t";
    for(int i=0;i<(int)elem.aruk.size();i++)
    {
        cout << elem.aruk[i]<<" ";
    }
    cout<<endl;
}

void osszegzes(vasarlas elem)
{
    if (optlinker(elem))
    {
        cout <<elem.ido<<"\t"<<elem.kod<<endl;
    }
}

bool optlinker(vasarlas elem)
{
    bool l=true;
    for(int i=0;l&&i<(int)elem.aruk.size();i++)
    {
        l=elem.aruk[i]!="arukod22";
    }
    return l;
}

int szamol(vasarlas elem)
{
   int hanyfele=0;
   for(int i=0;i<(int)elem.aruk.size();i++)
   {

       if(agyszam(elem,i)==0) hanyfele++;
   }
   return hanyfele;
}


int agyszam(vasarlas elem,const int i)
{
    int dbakt=0;
       for(int j=0;j<i;j++)
       {
           if(elem.aruk[i]==elem.aruk[j])
           {
               dbakt++;
           }
       }
    return dbakt;
}
