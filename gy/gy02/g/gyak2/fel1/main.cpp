#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    int a;
    cout << "Add meg a hatvanyalapot: ";
    cin >> a;
    if (cin.fail())
        {
            exit(1);
        } //return a;
    int k;
    cout << "Add meg a kitevot: ";
    cin >> k;
    if (cin.fail() || k<0)
        {
            exit(2);
        } //return k;
        // a 2 együtt void
    int h=1;
    for (int i=1; i<=k; i++)
    {
        h=h*a; //h*=a;
    }
    cout << "Tehat a hatvany: " << h;
    return 0;
}
