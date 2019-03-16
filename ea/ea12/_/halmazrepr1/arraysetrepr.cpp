#include "arraysetrepr.h"
#include "set.h"


void ArraySetRepr::setempty()
{
    _vect.clear();
}

void ArraySetRepr::insert(int e)
{
    if(!in(e)) _vect.push_back(e);
}

void ArraySetRepr::remove(int e)
{
    unsigned int ind;
    if(search(e,ind)){
        _vect[ind] = _vect[_vect.size()-1];
        _vect.pop_back();
    }
}

int ArraySetRepr::select() const
{
    if(_vect.size()==0) throw Set::EMPTYSET;
    return _vect[0];
}

bool ArraySetRepr::in(int e)    const
{
    unsigned int ind;
    return search(e,ind);
}

bool ArraySetRepr::empty() const
{
    return _vect.size()==0;
}

bool ArraySetRepr::search(int e, unsigned int &ind) const
{
    bool l = false;
    for(unsigned int i=0; !l && i<_vect.size(); ++i ){
        l = _vect[i]==e;
        ind = i;
    }
    return l;
}
