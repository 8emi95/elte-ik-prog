#include "menu.h"

#include <iostream>

using namespace std;

void Menu::run()
{
    int n = 0;
    do{
        menuWrite();
        cin >> n;

        switch(n){
        case 1:
            point1_putIn();
            break;
        case 2:
            point2_maxElem();
            break;
        }
    }while(n!=0);
}

void Menu::menuWrite()
{
    cout << "0 - kilepes" << endl;
    cout << "1 - elem behelyezese" << endl;
    cout << "2 - leggyakoribb elem" << endl;
}

void Menu:: point1_putIn()
{
    int e;
    cout << "Elem: ";
    cin >> e;
    h.putIn(e);
}

void Menu:: point2_maxElem()
{
    try{
        cout << "A leggyakoribb elem: " << h.maxElem() << endl;
    }catch(Bag::Exceptions ex){
        if(ex==Bag::EmptyBag){
            cout << "Ures a zsak!\n";
        }
    }
}

