#include "mapsetrepr.h"
#include "set.h"


void MapSetRepr::setempty()
{
    for(int e=0; e<(int)_vect.size(); ++e) _vect[e] = false;
    _count = 0;
}

void MapSetRepr::insert(int e)
{
    if(_enumeratorCount!=0) throw Set::UNDER_TRAVERSAL;
    if(e<0 || e>(int)_vect.size()-1) throw Set::ILLEGAL_ELEMENT;
    if(!_vect[e]){
        _vect[e] = true;
        ++_count;
    }
}

void MapSetRepr::remove(int e)
{
    if(_enumeratorCount!=0) throw Set::UNDER_TRAVERSAL;
    if(e<0 || e>(int)_vect.size()-1) throw Set::ILLEGAL_ELEMENT;
    if(_vect[e]){
        _vect[e] = false;
        --_count;
    }
}

int MapSetRepr::select() const
{
    if(_count==0) throw Set::EMPTYSET;
    int e;
    for(e=0; !_vect[e]; ++e);
    return e;
}

bool MapSetRepr::in(int e)    const
{
    if(e<0 || e>(int)_vect.size()-1) throw Set::ILLEGAL_ELEMENT;
    return _vect[e];
}

bool MapSetRepr::empty() const
{
    return _count==0;
}
