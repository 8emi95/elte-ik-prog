#include "bag.h"

using namespace std;

void Bag::putIn(int e)
{
    int ind;
    if (search(e, ind)){
        ++_vect[ind].c;
        if (_vect[_mind].c < _vect[ind].c)
            _mind = ind;
        else {
            _vect[_m++] = Pair(e,1);
             if (_m==1 ) _mind = 0;
        }
    }
}

int Bag::maxElem() const
{
    if (_m==0 ) throw EmptyBag;
    return _vect[_mind].v;
}

bool Bag::search(int e, int &ind) const
{
    bool l = false;
    for(int i=0; !l && i<_m; ++i){
        l = e == _vect[i].v;
        ind = i;
    }
    return l;
}

