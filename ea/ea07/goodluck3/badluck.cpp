#include "badluck.h"
#include <sstream>

// osztály adattagok
double BadLuck::_rate = 2.4;
double BadLuck::_salesCost = 600.0;
double BadLuck::_purchaseCost = 300.0;

// konstruktorok
BadLuck::BadLuck(const std::string &str) : Investment(str) {}

