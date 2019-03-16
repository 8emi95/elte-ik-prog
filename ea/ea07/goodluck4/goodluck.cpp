#include "goodluck.h"
#include <sstream>


// osztály adattag
Condition GoodLuck::_condition(4.8, 400, 200);

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
std::string GoodLuck::toString() const
{
    std::ostringstream ss;
    ss << "Szamla: "           << _account     <<
          " Nev: "             << _name        <<
          " Kedvezmenyezett: " << _beneficiary <<
          " jegyek szama: "    << _quantity;
    return ss.str();
}

