#include <iostream>
#include "enor.h"

using namespace std;

size_t db52(const vector<string> &v);

int main()
{
    Enor t("be.txt");
//    for(t.First();!t.End();t.Next())
//    {
//        Vasarlas v = t.Current();
//        cout<<v.datum<<" "<<v.vkod;
//        for(size_t i=0;i<v.aruk.size();++i)
//            cout<<" "<<v.aruk[i];
//        cout<<endl;
//    }

    for(t.First();!t.End();t.Next())
    {
        Vasarlas v = t.Current();
        size_t db = db52(v.aruk);
        if(db > 0)
            cout<<v.datum<<" "<<v.vkod<<" "<<db<<" "<<endl;
    }

    return 0;
}

size_t db52(const vector<string> &v) //szamlalas
{
    size_t c = 0;
    for(size_t i=0;i<v.size();++i)
        if(v[i] == "arukod52")
            ++c;
    return c;
}
