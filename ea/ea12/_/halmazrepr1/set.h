#ifndef SET_H
#define SET_H

#include "setrepr.h"
#include "mapsetrepr.h"
#include "arraysetrepr.h"


class Set
{
public:
    enum Exceptions{EMPTYSET, ILLEGAL_ELEMENT};
    Set(int n = 0){
        if (n==0) _repr = new ArraySetRepr();
        else      _repr = new MapSetRepr (n);
    }
    void setempty()     { _repr->setempty(); }
    void insert(int e)  { _repr->insert(e); }
    void remove(int e)  { _repr->remove(e); }
    int  select() const { return _repr->select(); }
    bool in(int e)const { return _repr->in(e); }
    bool empty()  const { return _repr->empty(); }

private:
    SetRepr *_repr;
};

#endif // SET_H
