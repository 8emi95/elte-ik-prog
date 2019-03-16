#include "bag.h"
using namespace std;

void Bag::putIn(int e)
{
    unsigned int ind;
    if (search(e, ind))
    {
        ++_vect[ind].c;
        if (_vect[_maxind].c < _vect[ind].c) _maxind = ind;
    }
    else
    {
        _vect.push_back(Pair(e,1));
        if (_vect.size()==1) _maxind = 0;
    }
}


int Bag::maxElem() const
{
    if (_vect.size()==0 ) throw EmptyBag;
    return _vect[_maxind].v;
}

bool Bag::search(int e, unsigned int &ind) const
{
    bool l = false;
    for(unsigned int i=0; !l && i<_vect.size(); ++i)
    {
        l = e == _vect[i].v;
        ind = i;
    }
    return l;
};


