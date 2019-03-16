#include <iostream>
#include <vector>

using namespace std;
int termSzamBeker(string uzenet);
vector<int> tombBeker(int n);

int main()
{
    //int n;
    int n=termSzamBeker("Tombmeret: ");
    vector<int> t = tombBeker(n);
    int s=0;
    for (int i=1; i<n; i++) //2.t�l utols�ig (az els� el�tt nincs semmi, �s az utols� elemet is vizsg�lni kell)
    {
        if (t[i]>0 && t[i-1]<0)
            s=s+1; //s++;
    }
    cout << s;
    return 0;
}

int termSzamBeker(string uzenet)
{
    int n;
    bool hiba;
    cout << "Add meg hany elemu legyen a tomb (pozitiv egesz): ";
    do
    {
        cin >> n;
        hiba = cin.fail() || n <= 0;
        if (hiba)
        {
            cin.clear();
            cin.ignore(1000, '\n');
        }
    }while (hiba);
    return n;
}

vector<int> tombBeker(int n)
{
    vector<int> v(n);
    for (int i=0; i<n; i++)
    {
        bool hiba;
        do
        {
            cout << "Add meg a tomb " << i + 1 << ". elemet: ";
            cin >> v[i];
            hiba=cin.fail() || n <= 0;
            if (hiba)
            {
                cin.clear();
                cin.ignore(1000, '\n');
            } //nem kell az else �g sz-szel
        }while (hiba);
    }
    return v;
}
