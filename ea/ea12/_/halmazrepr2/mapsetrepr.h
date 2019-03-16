#ifndef MAPSETREPR_H
#define MAPSETREPR_H

#include "setrepr.h"
#include <vector>

class MapSetRepr : public SetRepr {
public:
    MapSetRepr (int n): _count(0){
        _vect.resize(n+1);
        setempty();
    }

    void setempty();
    void insert(int e);
    void remove(int e);
    int  select() const;
    bool in(int e)    const;
    bool empty() const;

    class MapSetReprEnum : public Enumerator
    {
    public:
        MapSetReprEnum(MapSetRepr *p) : _s(p) { ++(_s->_enumeratorCount); }
        ~MapSetReprEnum() { --(_s->_enumeratorCount); }
        void first() { _elem = -1; next(); }
        void next()  {
            for(++_elem; _elem < (int)_s->_vect.size() && !_s->_vect[_elem]; ++_elem);
        }
        bool end() const { return _elem == (int)_s->_vect.size(); }
        int current() const { return _elem;}
    private:
        MapSetRepr *_s;
        int _elem;
    };

    Enumerator* createEnumerator() { return new MapSetReprEnum(this); }

private:
    std::vector<int> _vect;
    int  _count;
};

#endif // MAPSETREPR_H
