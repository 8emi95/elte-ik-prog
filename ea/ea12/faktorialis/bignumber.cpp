//Készítette:   Gregorics Tibor
//Dátum:        2009.01.24.
//Feladat:      BigNumber típus

#include "bignumber.h"
#include <iostream>
using namespace std;

//Feladat: 		integer számjegyekre bontása és a sztringhez fűzése
//Bemenõ adatok:int k	    - természetes szám
//              this	    - string
//Kimenõ adatok:this	    - string
//Tevékenység:  A k természetes szám számjegyeiből álló sztring
//              karaktereit készítjük el fordított sorrendben
//              (elől a legkisebb helyiértékű számjegy)
//              a nagy számot reprezentáló sztringhez fűzzük.
void BigNumber::digits(const int k)
{
    int c = k;
    while(c!=0){
        str.push_back((char)(c%10 + '0'));
        c = c/10;
    }
}

//Feladat: 		nagy szám kiírása operátorként
//Bemenõ adatok:this    - a nagy szám
//Tevékenység:  Ha a nagy számot reprezentáló sztring üres, akkor a nullát, egyébkét
//              a sztring karaktereit írjuk ki fordított sorrendben.
ostream& operator<<(ostream &out, const BigNumber &bn)
{
    if(bn.str.size()>0){
        for(int i=bn.str.size()-1; i>=0; --i) {
            cout << bn.str[i];
        }
    }else cout << 0;
    return cout;
}

//Feladat: 		integer értékül adása nagy számnak operátorként
//Bemenõ adatok:int k	    - természetes szám
//Kimenõ adatok:this	    - a nagy szám
//Tevékenység:  A k természetes szám számjegyeiből a nagy számot reprezentáló sztring
//              karaktereit készítjük el fordított sorrendben.
//              (elől a legkisebb helyiértékű számjegy)
int BigNumber::operator=(const int k)
{
    if(k<0) throw NonNegative;
    str = "";
    digits(k);
    return k;
}

//Feladat: 		nagy szám integer-rel való szorzása operátorként
//Bemenõ adatok:this	    - a nagy szám
//				int k	    - integer szorzó
//Kimenõ adatok:this	    - a nagy szám
//Tevékenység:  A nagy számot helyiértékenként (legkisebb, azaz az első helyiértéktől
//              indulva) végig szorozzuk a k természetes számmal
//              ügyelve az esetleges átvitelekre és figyelve arra, hogy
//              a nagy szám számjegyeit karakterként tároljuk.
BigNumber BigNumber::operator*(const int k)
{
    if(k<0) throw NonNegative;
    if(0==k) str = "";
    else {
        int c = 0;
        for(int i=0; i<(int)str.size(); ++i){
            c = k*(str[i]-'0') + c/10;
            str[i] = (char)(c%10 + '0');
        }
        digits(c/10);
    }
    return *this;
}
