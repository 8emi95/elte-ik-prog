#ifndef BAG_H
#define BAG_H
#include <vector>

template <typename Item>
class Bag
{
public:
    enum Exceptions {EmptyBag};
    Bag(){ _vect.clear(); }
    void putIn(const Item &e);
    Item maxElem() const;
private:
    struct Pair
    {
        Item v;
        int  c;
        Pair() {}
        Pair(const Item &a, int b): v(a), c(b) {}
    };
    std::vector<Pair> _vect;
    unsigned int _maxind;

    bool search(const Item &e, unsigned int &ind) const;
};


template <typename Item>
void Bag<Item>::putIn(const Item &e)
{
    unsigned int ind;
    if (search(e, ind)){
        ++_vect[ind].c;
        if(_vect[_maxind].c<_vect[ind].c) _maxind=ind;
    } else {
        _vect.push_back(Pair(e,1));
        if(_vect.size()==1) _maxind=0;
    }
}
template <typename Item>
Item Bag<Item>::maxElem() const
{
    if (_vect.size()==0 ) throw EmptyBag;
    return _vect[_maxind].v;
}
template <typename Item>
bool Bag<Item>::search(const Item &e, unsigned int &ind) const
{
    bool l = false;
    for(unsigned int i=0; !l && i<_vect.size(); ++i){
        l = e == _vect[i].v;
        ind = i;
    }
    return l;
};

#endif // BAG_H

