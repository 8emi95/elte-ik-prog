#include <iostream>
#include"enor.h"
//potencialisan mast is be kellhet include-olni...

using namespace std;

int main()
{
    Enor t("be.txt");
    for(t.First();!t.End();t.Next())
    {
        Adat e = t.Current();
        cout << e.nev << " " << e.kor << " ";
        for(size_t i = 0; i < e.kolkok.size(); ++i)
        {
            cout << "(" << e.kolkok[i].nev << ", " << e.kolkok[i].nem << ") ";
        }
        cout << e.szin << endl;
    }

//    bool l = false;
//    Adat elem;
//    int max;
//    for(t.First();!t.End();t.Next())
//    {
//        if(t.Current().szin == "cirmos")
//        {
//            if(l)
//            {
//                if(max <t.Current().alom)
//                {
//                    elem = t.Current();
//                    max = t.Current().alom;
//                }
//            }
//            else
//            {
//                l = true;
//                elem = t.Current();
//                max = t.Current().alom;
//            }
//        }
//    }
//    if(l)
//    {
//        cout << elem.nev << endl;
//    }
//    else
//    {
//        cout << "Nincs cirmos." << endl;
//    }

    return 0;
}
