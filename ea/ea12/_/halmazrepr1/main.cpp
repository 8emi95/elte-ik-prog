#include <iostream>
#include "set.h"

using namespace std;

int main()
{
    try{
        Set h1(5);

        h1.insert(2);
        h1.insert(4);
        h1.insert(0);

        cout << h1.select() << endl;
        h1.remove(h1.select());
        cout << h1.select() << endl;

        Set h2;

        h2.insert(2);
        h2.insert(4);
        h2.insert(0);

        cout << h2.select() << endl;
        h2.remove(h2.select());
        cout << h2.select() << endl;


    }catch(Set::Exceptions e){
        if(e==Set::ILLEGAL_ELEMENT) cout << "hiba\n";
    }


    return 0;
}
