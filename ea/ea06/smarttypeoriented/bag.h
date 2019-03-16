#ifndef BAG_H
#define BAG_H
#include <vector>

class Bag
{
public:
    enum Exceptions {EmptyBag};
    Bag(int m){
        _vect.resize(m+1);
        _maxelem = 0;
        for(int i=0; i<m; ++i) _vect[i] = 0;
    }
    void putIn(int e){
        if(++_vect[e]>_vect[_maxelem]) _maxelem = e;
    }
    int  maxElem() const{
        if(_vect[_maxelem]>0) return _maxelem;
        else throw EmptyBag;
    }
private:
    std::vector<int> _vect;
    int _maxelem;
};

#endif // BAG_H
