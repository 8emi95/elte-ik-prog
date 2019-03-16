#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

/*int abs(int a) //EDF
{
    return a >= 0 ? a : -a;
    if (a >= 0)
    {
        return a;
    }
    else
    {
        return -a;
    }
}*/

int main()
{
//kevés teszteset, minél kifejezõbbek

/*
Tesztelési terv
a       k       h
-       -       -
2       3       8
0       0       1
3       0       1
0       1       0
5       1       5
*       -5      HIBA
asd     *       HIBA
*       asd     HIBA
11a ->  11
2.9 ->  2
*/
/*    int a,k; //érdemes használathoz minél közelebb deklarálni
    cout << "Add meg a hatvanyalapot: " << endl;
    cin >> a;
    if (cin.fail()) //ha hülyeséget ír
    {
        exit(1); //
    }

    cout << "Add meg a kitevot: " << endl;
    cin >> k;
    if (cin.fail() || k < 0)
    {
        exit(2);
    }

    int h = 1;
    for (int i = 1; i <= k; ++i)
    {
        h *= i;
    }
    cout << h;               */

    //cégnél ötfõs projektcsapat, egymás kódját nézzük/kritizáljuk - több szem többet lát

//2.
    vector<int> v;
    v.push_back(0);
    v.push_back(-2);
    v.push_back(0);
    v.push_back(2);
    v.push_back(4);
    v.push_back(-2);

    int s = 0;
    for (int i =; i < v.size(); ++i)
    {
        int p = a >= 0 ? a : -a;
        s += p;
    }
    cout << s;

    return 0;
}
