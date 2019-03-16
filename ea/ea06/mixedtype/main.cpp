#include <iostream>
#include <fstream>
#include <string>
#include "bag.h"

using namespace std;

int main()
{
    ifstream f( "input.txt" );
    if(f.fail()){
        cout << "Hiba a fájl nyitásakor!\n";
        return 1;
    }




    Object *o;

    o = new Integer(8);

    o = new String("alma");
    if( (*o).is_String() ) ;

    Bag h;
    char ch;
    while(f >> ch){
        switch(ch) {
            case 'i' :  int n;
                        f >> n;
                        h.putIn(new Integer(n));
                        break;
            case 's' :  string s;
                        f >> s;
                        h.putIn(new String(s));
                        break;
        }
    }

    try{
        cout << "A megadott tomb leggyakoribb eleme: ";
        if( h.maxElem()->is_Integer())
            cout << ((Integer*)h.maxElem())->value() << endl;
        else if( h.maxElem()->is_String())
            cout << ((String*)h.maxElem())->value() << endl;
    }catch(Bag::Exceptions ex){
        if(ex==Bag::EmptyBag) cout << "Ures a zsak!\n";
    }

    return 0;
}

