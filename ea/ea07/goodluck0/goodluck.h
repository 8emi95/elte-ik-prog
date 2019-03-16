#ifndef GOODLUCK_H
#define GOODLUCK_H

#include <string>

class GoodLuck
{
private:
    // osztály adattagok
    static long     _lastAccount;
    static double   _rate;
    static double   _salesCost;
    static double   _purchaseCost;

    // példány adattagok
    long   		_account;
    std::string _name,
                _beneficiary;
    int   		_quantity;

public:
    // osztálymetódusok
    static int howManyUnits(double amount);
    static long newAccount();

    // konstruktorok
    GoodLuck(std::string str1, std::string str2);
    GoodLuck(std::string str);

    // példánymetódusok
    double value();
    double purchase(double amount);
    double sell(double amount);
    std::string toString();

    // hozzáférés az adattagokhoz
    static long getLastAccount()  { return _lastAccount; }
    static double getRate()       { return _rate; }
    static void setRate(double c) { _rate = c; }
    static double getSalesCost()  { return _salesCost; }
    static void setSalesCost(double c)   { _salesCost = c; }
    static double getPurchaseCost()      { return _purchaseCost; }
    static void setPurchaseCost(double c){ _purchaseCost = c; }

    long getAccount() const 		{ return _account; }
    std::string getName() const 	{ return _name; }
    int getQuantity() const { return _quantity; }
    std::string getBeneficiary() const   { return _beneficiary; }
    void setBeneficiary(std::string str) { _beneficiary = str; }
};

#endif // GOODLUCK_H
