#include "investment.h"
#include <sstream>

// oszt�ly adattagok
long   Investment::_lastAccount = 1000;

// oszt�lymet�dusok

long Investment::newAccount()
{
    return ++_lastAccount;
}

int Investment::howManyUnits(double amount, double currentRate)
{
    return (int) amount/currentRate;
}

// konstruktorok
Investment::Investment(const std::string &str)
{
    _account = newAccount();
    _name = str;
    _quantity = 0;
}

// p�ld�nymet�dusok
double Investment::value() const
{
    return _quantity*rate();
}

double Investment::purchase(double amount)
{
    int db = howManyUnits(rate(), amount-purchaseCost());
    _quantity += db;
    return db*rate()+purchaseCost();
}

double Investment::sell(double amount)
{
    int db = howManyUnits(rate(), amount+salesCost());
    if(_quantity>=db) _quantity -= db;
    else { db = _quantity; _quantity = 0;}
    return db*rate()-salesCost();
}

std::string Investment::toString()
{
    std::ostringstream ss;
    ss << "Szamla: "           << _account     <<
          " Nev: "             << _name        <<
          " jegyek szama: "    << _quantity;
    return ss.str();
}

