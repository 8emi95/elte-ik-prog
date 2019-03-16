#include "goodluck.h"
#include <sstream>


// osztály adattagok
double GoodLuck::_rate = 5.4;
double GoodLuck::_salesCost = 400.0;
double GoodLuck::_purchaseCost = 200.0;

// konstruktorok
GoodLuck::GoodLuck(const std::string &str1, const std::string &str2) : Investment(str1)
{
    _beneficiary = str2;
}

GoodLuck::GoodLuck(const std::string &str) : Investment(str)
{
    _beneficiary = "";
}

// példánymetódusok
std::string GoodLuck::toString()
{
    std::ostringstream ss;
    ss << "Szamla: "           << _account     <<
          " Nev: "             << _name        <<
          " Kedvezmenyezett: " << _beneficiary <<
          " jegyek szama: "    << _quantity;
    return ss.str();
}

