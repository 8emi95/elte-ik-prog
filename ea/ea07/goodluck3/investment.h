#ifndef INVESTMENT_H
#define INVESTMENT_H

#include <string>

class Investment
{
protected:
    // osztály adattagok
    static long     _lastAccount;

    // példány adattagok
    long   		_account;
    std::string _name;
    int   		_quantity;

public:
    // osztálymetódusok
    static int howManyUnits(double amount, double currentRate);
    static long newAccount();

    // konstruktorok
    Investment(const std::string &str);

    // példánymetódusok
    double value() const;
    double purchase(double amount);
    double sell(double amount);
    virtual std::string toString();

    // hozzáférés az adattagokhoz
    long getAccount() const 	{ return _account; }
    std::string getName() const { return _name; }
    int getQuantity() const     { return _quantity; }

    virtual double rate() const         = 0;
    virtual double salesCost() const    = 0;
    virtual double purchaseCost() const = 0;


};

#endif // INVESTMENT_H
