#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int a;
    int t[100];
    vector<int> v(4); //vector önmagában nem típus
    //<>-ba típus, int-eket tartalmazó vector
    //kapacitást meg lehet adni vectorban, de nem kötelezp
    //méretét v.size()-zal le lehet kérdezni
    //ha vectornak kezdõértéket nem adok meg akk üres

    //.empty() .pop_back() .push_back() .resize(8)

    //struct-ot lehet vector típusnak adni
    //pl
    //struct Par { int a,b }; ... vector<Par> v(4);

    //konstruktor fv ami ...-n belül van, no paraméter no visszatérési érték

    return 0;
}
