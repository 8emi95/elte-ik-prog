#ifndef CONDITION_H
#define CONDITION_H

class Condition
{
private:
    // osztály adattagok
    static long _lastAccount;

    // példány adattagok
    double   _rate;
    double   _salesCost;
    double   _purchaseCost;

public:
    // osztálymetódusok
    static long newAccount() { return ++_lastAccount; };

    // konstruktor
    Condition(double a, double b, double c)
        : _rate(a), _salesCost(b), _purchaseCost(c) {}

    // példánymetódus
    int howManyUnits(double amount) const { return (int)( amount/_rate ); }

    // hozzáférés az adattagokhoz
    double getRate() const          { return _rate; }
    void setRate(double c)          { _rate = c; }
    double getSalesCost() const     { return _salesCost; }
    void setSalesCost(double c)     { _salesCost = c; }
    double getPurchaseCost() const  { return _purchaseCost; }
    void setPurchaseCost(double c)  { _purchaseCost = c; }
};



#endif // CONDITION_H
