#include <iostream>
#include<fstream>
#include "enor.h"

using namespace std;

int main()
{
    Felsorolo fels("bemenet.txt");
    fels.first();

    vector<int> hany;
    vector<Vasarlas> vasarlasok;
    while(!fels.end())
    {
        Vasarlas v = fels.current();

        //feladatok:

        //melyikekben nem volt �ruk�d22
        int i = 0;
        int arukod_db = v.arukod.size();

        while (i < arukod_db && v.arukod[i] != "�ruk�d22") //egy sort vizsg�lunk csak
            i++;
        if (i == arukod_db)
        {
            cout << v.ev << ":" << v.ho << ":" << v.nap << ":" << v.ora << ":" << v.perc << " " << v.azon << endl;
        }

        //legkevesebb f�l�t v�s�rl� + h�nyf�le
        int hanyfele = 0;
        vector<string> mar_volt;

        for (int i = 0; i < v.arukod.size(); ++i)
        {
            string vizsgalt_kod = v.arukod[i];

            int j = 0; // opt. lin. ker., a m�rvolt k�dokban keress�k az aktu�lis k�dot
            while (j < mar_volt.size() && mar_volt[j] != vizsgalt_kod)
                ++j;

            if (j == mar_volt.size()) // m�g nem volt a k�d, sz�val ez egy �jf�le �ru
            {
                mar_volt.push_back(vizsgalt_kod);
                ++hanyfele;
            }
        }
        hany.push_back(hanyfele);
        vasarlasok.push_back(v);

        fels.next();
    }

    int min = hany[0];
    int ind = 0;
    for(int i = 1; i < vasarlasok.size(); ++i)
    {
        if(hany[i] < min)
        {
            min = hany[i];
            ind = i;
        }
    }
    cout << vasarlasok[ind].ev << ":" << vasarlasok[ind].ho << ":" << vasarlasok[ind].nap << ":" << vasarlasok[ind].ora << ":" << vasarlasok[ind].perc << " " << vasarlasok[ind].azon << " " << min << endl;

    return 0;
}
