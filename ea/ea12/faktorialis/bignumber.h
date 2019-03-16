//Készítette:   Gregorics Tibor
//Dátum:        2009.01.24.
//Feladat:      BigNumber típus

#ifndef BIGNUMBER_H
#define BIGNUMBER_H

#include <iostream>

//Típusértékek: nagy számok
//Reprezentáció:számjegyek sorozata sztringben tárolva
//Mûveletek:    operator=  - integer értékül adása nagy számnak
//              operator*  - nagy szám integer-rel való szorzása
//              operator<< - nagy szám kiírása
class BigNumber{
    private:
        std::string str;
        void digits(const int k);

    public:
        enum Exceptions {NonNegative };

        int operator=(const int k);
        BigNumber operator*(const int k);
        friend std::ostream& operator<<(std::ostream &out, const BigNumber &bn);
};

#endif
