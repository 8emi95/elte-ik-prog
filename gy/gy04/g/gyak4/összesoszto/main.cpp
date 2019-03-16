#include <iostream>

using namespace std;

int termSzamBeker();

int main()
{
    int n = termSzamBeker();

    for (int i=1; i<=n; i++)
        if (n % i == 0)
            cout << i << endl;

    return 0;
}

int termSzamBeker()
{
    int n;
    bool hiba;
    cout << "Adj meg egy pozitiv egesz szamot: ";
    do
    {
        cin >> n;
        hiba = cin.fail() || n <= 0;
        if (hiba)
        {
            cout << "Elrontottad. Ujra: ";
            cin.clear();
            cin.ignore(1000, '\n');
        }
    }
    while (hiba);
    return n;
}
