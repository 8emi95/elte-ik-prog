#include "goodluck.h"
#include <sstream>

// osztály adattagok
long   GoodLuck::_lastAccount = 1000;
double GoodLuck::_rate = 1.3;
double GoodLuck::_salesCost = 400.0;
double GoodLuck::_purchaseCost = 200.0;

// osztálymetódusok
int GoodLuck::howManyUnits(double amount)
{
    return (int)( amount/_rate );
}

long GoodLuck::newAccount()
{
    return ++_lastAccount;
}

// konstruktorok
GoodLuck::GoodLuck(std::string str1, std::string str2)
{
    _account = newAccount();
    _name = str1;
    _beneficiary = str2;
    _quantity = 0;

}

GoodLuck::GoodLuck(std::string str)
{
    _account = newAccount();
    _name = str;
    _beneficiary = "";
    _quantity = 0;
}

// példánymetódusok
double GoodLuck::value()
{
    return _quantity*_rate;
}

double GoodLuck::purchase(double amount)
{
    int db = howManyUnits(amount-_purchaseCost);
    _quantity += db;
    return db*_rate+_purchaseCost;
}

double GoodLuck::sell(double amount)
{
    int db = howManyUnits(amount+_salesCost);
    if(_quantity>=db) _quantity -= db;
    else { db = _quantity; _quantity = 0;}
    return db*_rate-_salesCost;
}

std::string GoodLuck::toString()
{
    std::ostringstream ss;
    ss << "Szamlaszam: "       << _account     <<
          " Nev: "             << _name        <<
          " Kedvezmenyezett: " << _beneficiary <<
          " jegyek szama: "    << _quantity;
    return ss.str();
}

