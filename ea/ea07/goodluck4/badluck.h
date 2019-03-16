#ifndef BADLUCK_H
#define BADLUCK_H

#include "investment.h"
#include "condition.h"
#include <string>

class BadLuck : public Investment
{
public:
    // osztály adattag
    static Condition _condition;

protected:
    // példány metódus
    Condition condition() const { return _condition; }

public:
    // konstruktor
    BadLuck(const std::string &str) : Investment(str) {}
};

#endif // BADLUCK_H
