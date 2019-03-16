#include <iostream>
#include "enor.h"

using namespace std;

int main()
{
    Enor t("be.txt");
    for(t.First();!t.End();t.Next())
    {
        Adat c = t.Current();
        cout<<c.nev<<" "<<c.mezony<<" "<<c.csapat1<<" "<<c.csapat2;
    }
    return 0;
}
