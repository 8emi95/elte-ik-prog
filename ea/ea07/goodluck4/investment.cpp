#include "investment.h"
#include <sstream>


// konstruktor
Investment::Investment(const std::string &str)
{
    _account = Condition::newAccount();
    _name = str;
    _quantity = 0;
}

// példánymetódusok
double Investment::value() const
{
    return _quantity*condition().getRate();
}

double Investment::purchase(double amount)
{
    int db = condition().howManyUnits(amount-condition().getPurchaseCost());
    _quantity += db;
    return db*condition().getRate()+condition().getPurchaseCost();
}

double Investment::sell(double amount)
{
    int db = condition().howManyUnits(amount+condition().getSalesCost());
    if(_quantity>=db) _quantity -= db;
    else { db = _quantity; _quantity = 0;}
    return db*condition().getRate()-condition().getSalesCost();
}

std::string Investment::toString() const
{
    std::ostringstream ss;
    ss << "Szamla: "           << _account     <<
          " Nev: "             << _name        <<
          " jegyek szama: "    << _quantity;
    return ss.str();
}


