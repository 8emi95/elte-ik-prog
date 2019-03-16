#include <iostream>
#include "enor.h"

using namespace std;



int main()
{
    Enor t("be.txt");
    int osszes=0;
    for(t.First();!t.End();t.Next())
    {
        Adat c = t.Current();
        /*cout<<c.asztalszam<<" "<<c.ido<<" ";
        for(size_t i=0; i<c.p.size(); ++i)
        {
            cout<<c.p[i].adag<<" "<<c.p[i].tipus<<" ";
        }
        cout<<endl;*/
        for(size_t i=0; i<c.p.size();++i)
        {
            if(c.p[i].tipus == "CSIR" && c.ido>"20:01" )
            {
                osszes=osszes+c.p[i].adag;
            }
        }

    }
    cout<<"Ennyi csirke adag fogyott: "<<osszes;
    return 0;
}


