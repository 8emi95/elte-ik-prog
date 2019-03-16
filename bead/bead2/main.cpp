#include <iostream>
#include"enor.h"
#include<vector>

using namespace std;

int osszTank(const Adat &e);

int main()
{
    Enor t("bejnjk.txt");
//    for(t.First();!t.End();t.Next())
//    {
//        Adat e = t.Current();
//        cout << e.rsz << " ";
//        for(int i = 0; i < e.tank.size(); ++i)
//            cout << e.tank[i] << " ";
//        cout << endl;
//    }

/*
1 .hány olyan jármű van, amelybe egyáltalán nem tankoltak
2. listázza ki azon járművek rendszámát, amelybe átlagosan 20 liternél több került
*/

    int noTank = 0;
    int avg = 0;
    for(t.First();!t.End();t.Next())
    {
        Adat e = t.Current();

        if(e.tank.size() > 0)
        {
            int ossz = osszTank(e);
            avg = ossz/e.tank.size();
            if(avg > 20)
                cout << e.rsz << endl;
        }
        else
            ++noTank;
    }
    cout << noTank << endl;

    return 0;
}

int osszTank(const Adat &e)
{
    int s = 0;
    for(int i = 0; i < e.tank.size(); ++i)
        s += e.tank[i];
    return s;
}
