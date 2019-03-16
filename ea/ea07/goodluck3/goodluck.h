#ifndef GOODLUCK_H
#define GOODLUCK_H

#include "investment.h"
#include <string>

class GoodLuck : public Investment
{
private:

    // oszt�ly adattagok
    static double   _rate;
    static double   _salesCost;
    static double   _purchaseCost;

    // p�ld�ny adattagok
    std::string _beneficiary;

public:
    // konstruktorok
    GoodLuck(const std::string &str1, const std::string &str2);
    GoodLuck(const std::string &str);

    // p�ld�nymet�dusok
    std::string toString();

    // hozz�f�r�s az oszt�ly adattagokhoz
    static double getRate()       { return _rate; }
    static void setRate(double c) { _rate = c; }
    static double getSalesCost()  { return _salesCost; }
    static void setSalesCost(double c)   { _salesCost = c; }
    static double getPurchaseCost()      { return _purchaseCost; }
    static void setPurchaseCost(double c){ _purchaseCost = c; }

    // hozz�f�r�s az adattagokhoz
    std::string getBeneficiary() const   { return _beneficiary; }
    void setBeneficiary(std::string str) { _beneficiary = str; }

    virtual double rate() const          { return _rate; }
    virtual double salesCost() const     { return _salesCost; }
    virtual double purchaseCost() const  { return _purchaseCost; }
};

#endif // GOODLUCK_H
