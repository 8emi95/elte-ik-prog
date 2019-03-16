#ifndef SETREPR_H
#define SETREPR_H

#include "enumerator.h"


class SetRepr {
public:
    SetRepr():_enumeratorCount(0){}
    virtual ~SetRepr(){};

    virtual void setempty() 	= 0;
    virtual void insert(int e) 	= 0;
    virtual void remove(int e) 	= 0;
    virtual int  select() const = 0;
    virtual bool in(int e)const = 0;
    virtual bool empty() const 	= 0;

    virtual Enumerator* createEnumerator() = 0;

protected:
    int _enumeratorCount;
};


#endif // SETREPR_H
