#ifndef ARRAYSETREPR_H
#define ARRAYSETREPR_H

#include <vector>
#include "setrepr.h"

class ArraySetRepr : public SetRepr{
public:
    void setempty();
    void insert(int e);
    void remove(int e);
    int  select() const;
    bool in(int e)    const;
    bool empty() const;

    class ArraySetReprEnum : public Enumerator
    {
    public:
        ArraySetReprEnum(ArraySetRepr *p) : _s(p) { ++(_s->_enumeratorCount); }
        ~ArraySetReprEnum() { --(_s->_enumeratorCount); }
        void first() { _ind = 0; }
        void next()  { ++_ind;}
        bool end()    const { return _ind == _s->_vect.size(); }
        int current() const { return _s->_vect[_ind];}
    private:
        ArraySetRepr *_s;
        unsigned int _ind;
    };

    Enumerator* createEnumerator() { return new ArraySetReprEnum(this); }

private:
    static const int _blockSize = 20;

    std::vector<int> _vect;

    bool search(int e, unsigned int &ind) const;
};

#endif // ARRAYSETREPR_H
