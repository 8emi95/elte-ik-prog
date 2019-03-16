#include <iostream>

using namespace std;

int main()
{
    //cout << "Hello world!" << endl;

    bool van = false
    for (int i = 0; i < n; ++i)
    {
        int db = ldb[i];
        bool nincs = nincsl[i];
        //max
        if (nincs == true && van)
        {
            if(db > max)
            {
                max = db;
                ind = i;
            }
        }
        else if (nincs == true && !van)
        {
            van = true;
            max = db;
            ind = i;
        }
    }

    if (van == true)
    {
        szo = t[ind];
    }

    //nincsl
    bool l = true;
    int i = s.size()/2 + 1;
    for (int i = 0; l && i < s.size(); ++i)
    {
        l = (s[i] != 'l' && s[i] != 'L');
    }

    //ldb
    int db = 0;
    for (int i = 0; i < s.size()/2; ++i)
    {
        if (s[i] == 'l' || s[i] == 'L')
        {
            ++db;
        }
    }

    //vanr - beolvasás
    bool l = false;
    int i = 1; //többi!!!!!!!!
    for (int i = 0; !l && i < s.size(); ++i)
    {
        l = (s[i] == 'r' || s[i] == 'R');
    }

    return 0;
}
