#ifndef ARRAYSETREPR_H
#define ARRAYSETREPR_H

#include "setrepr.h"
#include <vector>

class ArraySetRepr : public SetRepr{
public:
    ArraySetRepr (){}
    void setempty();
    void insert(int e);
    void remove(int e);
    int  select() const;
    bool in(int e)    const;
    bool empty() const;

private:
    std::vector<int> _vect;

    bool search(int e, unsigned int &ind) const;
};

#endif // ARRAYSETREPR_H
