#include <iostream>
#include <fstream>
#include "bag.hpp"

using namespace std;

int main()
{
    ifstream f( "input.txt" );
    if(f.fail())
    {
        cout << "Hiba a fajl nyitasakor!\n";
        return 1;
    }

    Bag<int> h;
    int e;
    while(f >> e)
    {
        h.putIn(e);
    }

    try{
        cout << "A megadott tomb leggyakoribb eleme: "
             << h.maxElem() << endl;
    } catch(Bag<int>::Exceptions ex) {
        if(ex==Bag<int>::EmptyBag){
            cout << "Ures a zsak!\n";
        }
    }
    return 0;
}
