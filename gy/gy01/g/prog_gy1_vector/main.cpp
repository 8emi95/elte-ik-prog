#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int a;
    int t[100];
    vector<int> v(4); //vector �nmag�ban nem t�pus
    //<>-ba t�pus, int-eket tartalmaz� vector
    //kapacit�st meg lehet adni vectorban, de nem k�telezp
    //m�ret�t v.size()-zal le lehet k�rdezni
    //ha vectornak kezd��rt�ket nem adok meg akk �res

    //.empty() .pop_back() .push_back() .resize(8)

    //struct-ot lehet vector t�pusnak adni
    //pl
    //struct Par { int a,b }; ... vector<Par> v(4);

    //konstruktor fv ami ...-n bel�l van, no param�ter no visszat�r�si �rt�k

    return 0;
}
