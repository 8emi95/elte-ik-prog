#include <iostream>
#include <fstream>
#include "bag.h"

using namespace std;


int main()
{
    ifstream f( "input.txt" );
    if(f.fail()){
        cout << "Hiba a fajl nyitasakor!\n";
        return 1;
    }

    Bag h;
    int e;
    while(f >> e){
        h.putIn(e);
    }

    try{
        cout << "A megadott tomb leggyakoribb eleme: " << h.maxElem() << endl;
    }catch(Bag::Exceptions ex){
        if(ex==Bag::EmptyBag){
            cout << "Ures a zsak!\n";
        }
    }

    return 0;
}


