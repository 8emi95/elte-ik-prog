#include <iostream>
#include <vector>

using namespace std;

int abs(int a)
{
    if (a<=0)
    {
        return a;
    }
    else
    {
        return -a;
    }
}

int abs1(int a)
{
    return a>=0 ? a: -a;
}

int main()
{
    vector<int> t;
    int s;
    //beolvasás
    t.push_back(0);
    t.push_back(-2);
    t.push_back(0);
    t.push_back(2);
    t.push_back(-4);

    s=0;
    for (int i=0; i<t.size();i++)
    {
        if (t[i]>=0)
        {
            s=s+t[i]
        }
        else
            {
            s=s-t[i]
            }
    }
    s=0;
    for (int i=0; i<t.size();i++)
    {
        int a = abs(t[i]);
        s=s+a;
        //s=s+abs(t[i]);
    }
    cout << s;
    return 0;
}
