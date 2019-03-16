#include <iostream>
#include <vector>

using namespace std;

//1. g�pes zh, stukis

//int pozEgeszBeker();
int termSzamBeker(string uzenet);
vector<int> tombBeker(int n);

int main()
{
/*
n = "asd"   - hiba
n = 0       - hiba
n = -7      - hiba
n = 1       - cout = "1"
n = 71      - cout = "71"
n = 6       - cout = "1,2,3,6"
*/
    //int n = pozEgeszBeker(); //sorban kezdi feldolgozni c++ a k�dot, ha el�tte nem tal�lja meg akk kiab�l
                               //ut�na defini�lva nem fut, 1 eg�sz fv fent 2 dekl fent, fv lent
    int n = termSzamBeker("Tombmeret: ");
    vector<int> t = tombBeker(n);
    int c = 0;
    for(int i = 1; i < n; ++i)
    {
        if(t[i] > 0 && t[i-1] < 0)
        {
            c++;
        }
    }
    cout << c;

   /* for(int i = 1; i <= n; ++i)
    {
        if(n % i == 0)
        {
            cout << i;
        } //egy utas�t�s
       // else
        //{
          //  cout << "";
       // }
    } //for-on bel�l if egy utas�t�s */

    return 0;
}

/*int pozEgeszBeker()
{
    cout << "Adj meg egy pozitiv egesz szamot: ";
    int n;
    bool hiba; //k�v�l kell deklar�lni
    do
    {
        cin >> n;
        hiba = cin.fail() || 0 >= n;
        if(hiba)
        {
            cout << "Ejj, ejj, ejj. Ujra:";
        }
        cin.clear(); //ha cin hib�s akk t�rli
        cin.ignore(1000, '\n'); //maradt vmi szem�t akk kit�rli
    }
    while(hiba);

    return n;
}*/

int termSzamBeker(string uzenet)
{
    cout << "Adj meg egy termeszetes szamot: ";
    int n;
    bool hiba; //k�v�l kell deklar�lni
    do
    {
        cin >> n;
        hiba = cin.fail() || 0 > n;
        if(hiba)
        {
            cout << "Ejj, ejj, ejj. Ujra:";
        }
        cin.clear(); //ha cin hib�s akk t�rli
        cin.ignore(1000, '\n'); //maradt vmi szem�t akk kit�rli
    }
    while(hiba);

    return n;
}

vector<int> tombBeker(int n)
{
    vector<int> v(n);
    for(int i = 0; i < n; ++i)
    {
        cout << "Add meg a tomb " << i + 1 << ". elemet: ";
        //int sz; //elhagyhat� ha v[i]-be olvasunk
        bool hiba;
        do
        {
            cin >> v[i]; //sz helyett
            hiba = cin.fail(); //hiba egy �rt�k lesz, fail akkori �rt�ke t�rol�dik bene
            if(hiba)
            {
                cout << "Ejj, ejj, ejj. Ujra:";
            }
            cin.clear(); //fail-t t�rli
            cin.ignore(1000, '\n');
        }while(hiba);
        //v[i] = sz; //elhagyhat� ha v[i]-be olvasunk
    }

    return v;
}
