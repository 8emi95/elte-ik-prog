#ifndef GOODLUCK_H
#define GOODLUCK_H

#include "investment.h"
#include "condition.h"
#include <string>

class GoodLuck : public Investment
{
public:
    // osztály adattag
    static Condition _condition;

protected:
    // példány adattag
    std::string _beneficiary;

protected:
    // példány metódus
    Condition condition() const { return _condition; }

public:
    // konstruktorok
    GoodLuck(const std::string &str1, const std::string &str2);
    GoodLuck(const std::string &str);

    // példánymetódusok
    std::string toString() const;
    std::string getBeneficiary() const   { return _beneficiary; }
    void setBeneficiary(std::string str) { _beneficiary = str; }
};

#endif // GOODLUCK_H
