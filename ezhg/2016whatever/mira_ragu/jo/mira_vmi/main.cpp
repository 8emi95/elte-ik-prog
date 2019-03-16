#include <iostream>
#include "enor.h"

using namespace std;

int main()
{
    Enor t("be.txt");

    for(t.First();!t.End();t.Next())
    {
        Adat c = t.Current();
        cout<<c.asztalszam<<" "<<c.ido<<" ";
        for(size_t i=0; i<c.p.size(); ++i)
        {
            cout<<c.p[i].adag<<" "<<c.p[i].tipus<<" ";
        }
        cout<<endl;
    }
    return 0;
}
