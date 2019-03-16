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
        cout << e.nev << " " << e.alom << " " << e.szin << endl;
    }

    bool l = false;
    Adat elem;
    int max;
    for(t.First();!t.End();t.Next())
    {
        if(t.Current().szin == "cirmos")
        {
            if(l)
            {
                if(max <t.Current().alom)
                {
                    elem = t.Current();
                    max = t.Current().alom;
                }
            }
            else
            {
                l = true;
                elem = t.Current();
                max = t.Current().alom;
            }
        }
    }
    if(l)
    {
        cout << elem.nev << endl;
    }
    else
    {
        cout << "Nincs cirmos." << endl;
    }

    return 0;
}
