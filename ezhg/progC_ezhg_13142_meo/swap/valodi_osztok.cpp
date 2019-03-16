#include <iostream>

using namespace std;

class Felsorolo{
public:
    Felsorolo(int n){ this->n = n; }
    void First()
    {
         d = 0;
         Next();
    }
    void Next()
    {
         d += 2;
         while (!End() && n % d != 0) d += 2;
    }
    bool End(){ return (d >= (n / 2) + 1); }
    int  Current(){ return d; }
private:
    int  d, n;
};


int main()
{
    int n, c = 0;
    cin >> n;
    Felsorolo f(n);
    for (f.First(); !f.End(); f.Next()) c++; // if (n % f.Current() == 0) c++;

    cout << c << endl;
    return 0;
}
