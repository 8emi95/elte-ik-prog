#ifndef INVESTMENT_H
#define INVESTMENT_H

#include "condition.h"
#include <string>

class Investment
{
protected:
    long   		_account;
    std::string _name;
    int   		_quantity;

    virtual Condition condition() const = 0;
public:
    // konstruktor
    Investment(const std::string &str);

    // példánymetódusok
    double value() const;
    double purchase(double amount);
    double sell(double amount);
    virtual std::string toString() const;


    // hozzáférés az adattagokhoz
    long getAccount() const 	{ return _account; }
    std::string getName() const { return _name; }
    int getQuantity() const     { return _quantity; }
};

#endif // INVESTMENT_H
