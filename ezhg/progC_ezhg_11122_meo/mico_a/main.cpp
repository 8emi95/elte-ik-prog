#include "felsorolo.h"
#include <iostream>

using namespace std;

void writeNap (Nap n);
void writeVectorInt(vector <int> v);

string min_date;
int min_forgalom;
bool volt_e=false;

int main() //mindenbõl több mint 10
{
    Felsorolo t("be.txt");
    Nap n;

    for (t.First();!t.End(); t.Next())
    {
        n=t.Current();

        if (!n.sok)
        {
            cout <<n.datum<<endl;
        }

        if (!n.sok && !volt_e)
        {
            min_date=n.datum;
            min_forgalom=n.forgalom;
            volt_e=true;
        }
        else if(!n.sok && volt_e && min_forgalom> n.forgalom)
        {
            min_date=n.datum;
            min_forgalom=n.forgalom;
        }
    }

    cout << "Ezek kozott a legkevesbe forgalmas: "<< min_date << " ("<< min_forgalom<< ") \n";
}

void writeVectorInt(vector <int> v)
{
    for (int i=0; i<(int)v.size(); i++)
    {
        clog << v[i] <<" ";
    }
}
void writeNap (Nap n)
{
    clog << n.datum << " ";
    writeVectorInt(n.udito);
    clog << endl;
}
