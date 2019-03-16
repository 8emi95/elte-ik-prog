#include "bag.h"

using namespace std;

void Bag::putIn(Object* e)
{
    unsigned int ind;
    if (search(e, ind))
    {
        ++_vect[ind].c;
        if(_vect[_maxind].c<_vect[ind].c) _maxind=ind;
        }else
        {
            _vect.push_back(Pair(e,1));
            if(_vect.size()==1) _maxind=0;
        }
    }

    Object* Bag::maxElem() const
    {
        if (_vect.size()==0 ) throw EmptyBag;
        return _vect[_maxind].v;
    }

    bool Bag::search(const Object* e, unsigned int &ind) const
    {
        bool l = false;
        for(unsigned int i=0; !l && i<_vect.size(); ++i)
        {
            l = e->equalTo(_vect[i].v);
            ind = i;
        }

        return l;
    };


