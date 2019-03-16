#include <iostream>
#include "set.h"
#include "enumerator.h"

using namespace std;

void write(Set h);

int main()
{
    Set h;
    int n;
    cout << "Adjon meg kulonbozo termeszetes szamokat!\n";

    while(cin>>n) {
        if(n<0) continue;
        try{h.insert(n);}catch(Set::Exceptions ex){}
    }

    cout << "A halmaz elemei: ";
    write(h);

    bool l = false;
    int e;
    Enumerator* en1 = h.createEnumerator();
    for(en1->first(); !l && !en1->end(); en1->next()){
        e = en1->current();
        int c = 0;
        Enumerator* en2 = h.createEnumerator();
        for(en2->first(); !en2->end(); en2->next()){
            if(e>en2->current()) ++c;
        }
        l = c>=3;
    }

    if (l) cout << "A keresett szam: " << e << endl;
    else cout << "Nincs keresett szam.\n";

    return 0;
}


/*
int main()
{
    try{
        Set h1(5);

        h1.insert(2);
        h1.insert(4);
        h1.insert(0);
        cout << "1. halmaz: "; write(&h1);

        cout << h1.select() << endl;
        h1.remove(h1.select());
        cout << h1.select() << endl;

        Set h2;

        h2.insert(2);
        h2.insert(4);
        h2.insert(0);
        cout << "2. halmaz: "; write(&h2);

        cout << h2.select() << endl;
        h2.remove(h2.select());
        cout << h2.select() << endl;


    }catch(Set::Exceptions e){
        if(e==Set::ILLEGAL_ELEMENT) cout << "hiba\n";
    }


    return 0;
}
*/
void write(Set h)
{
    Enumerator* en = h.createEnumerator();
    for(en->first(); !en->end(); en->next()){
        cout << en->current() << " ";
    }
    cout << endl;
}
