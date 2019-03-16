#ifndef BADLUCK_H
#define BADLUCK_H

#include "investment.h"
#include <string>

class BadLuck : public Investment
{
public:
    // osztály adattagok
    static double   _rate;
    static double   _salesCost;
    static double   _purchaseCost;

    // konstruktor
    BadLuck(const std::string &str);

    // hozzáférés az osztály adattagokhoz
    static double getRate()              { return _rate; }
    static void setRate(double c)        { _rate = c; }
    static double getSalesCost()         { return _salesCost; }
    static void setSalesCost(double c)   { _salesCost = c; }
    static double getPurchaseCost()      { return _purchaseCost; }
    static void setPurchaseCost(double c){ _purchaseCost = c; }

    // hozzáférés az adattagokhoz
    virtual double rate() const          { return _rate; }
    virtual double salesCost() const     { return _salesCost; }
    virtual double purchaseCost() const  { return _purchaseCost; }
};

#endif // BADLUCK_H
