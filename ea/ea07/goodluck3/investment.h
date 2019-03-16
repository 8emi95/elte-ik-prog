#ifndef INVESTMENT_H
#define INVESTMENT_H

#include <string>

class Investment
{
protected:
    // oszt�ly adattagok
    static long     _lastAccount;

    // p�ld�ny adattagok
    long   		_account;
    std::string _name;
    int   		_quantity;

public:
    // oszt�lymet�dusok
    static int howManyUnits(double amount, double currentRate);
    static long newAccount();

    // konstruktorok
    Investment(const std::string &str);

    // p�ld�nymet�dusok
    double value() const;
    double purchase(double amount);
    double sell(double amount);
    virtual std::string toString();

    // hozz�f�r�s az adattagokhoz
    long getAccount() const 	{ return _account; }
    std::string getName() const { return _name; }
    int getQuantity() const     { return _quantity; }

    virtual double rate() const         = 0;
    virtual double salesCost() const    = 0;
    virtual double purchaseCost() const = 0;


};

#endif // INVESTMENT_H
