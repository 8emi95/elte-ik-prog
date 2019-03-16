#ifndef MAPSETREPR_H
#define MAPSETREPR_H

#include "setrepr.h"
#include <vector>

class MapSetRepr : public SetRepr {
public:
    MapSetRepr(int n): _count(0){
        _vect.resize(n+1);
        setempty();
    }

    void setempty();
    void insert(int e);
    void remove(int e);
    int  select() const;
    bool in(int e)    const;
    bool empty() const;

private:
    std::vector<int> _vect;
    int  _count;
};

#endif // MAPSETREPR_H
