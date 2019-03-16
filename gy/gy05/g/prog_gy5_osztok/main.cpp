#include<iostream>
#include<cstdlib>
#include<vector>

using namespace std;

int TermSzamBeker();
string f(int n, int i);

struct Halmaz
{
    vector<int> v;
    void berak(int e)
    {
        bool l = true;
        for(size_t i = 0; l && i < v.size(); ++i)
        {
            l = v[i] != e;
        }
        if(l)
        {
            v.push_back(e);
        }
    }
};

int main()
{
    int n = TermSzamBeker();
    cout<<"Az osztok:"<<endl;
    Halmaz halmaz; //int i; deklarálással azonos
    for(int i=1;i<=n;++i)
    {
        if(n % i == 0)
        {
            halmaz.berak(i); //ekviv: v.push_back(i)
            halmaz.berak(i);
        }
    }
    for(int i = 0; i < n; ++i)
    {
        cout << halmaz.v[i] << endl;
    }
    return 0;
}

int TermSzamBeker()
{
    int n;
    bool hiba;
    do
    {
        cout<<"Irj be egy termeszetes szamot!"<<endl;
        cin>>n;

        hiba = cin.fail() || n<0;
        if(hiba)
        {
            cout<<"Ejj."<<endl;
            cin.clear();
            cin.ignore(1000,'\n');
        }
    }
    while(hiba);

    return n;
}

string f(int n, int i)
{
    if(n % i == 0)
    {
        stringstream ss; //konstruktor paraméterben szöveg ...ss("asd");
        ss << i << endl;
        return ss.str();
    }
    else
        return "";
}
