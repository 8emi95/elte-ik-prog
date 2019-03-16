#ifndef BAG_H
#define BAG_H
#include <vector>
#include "object.h"

class Bag
{
public:
    enum Exceptions {EmptyBag};
    Bag()
    {
        _vect.clear();
    }

    void putIn(Object* e);
    Object* maxElem() const;
private:
    struct Pair
    {
        Object* v;
        int  c;
        Pair() {}
        Pair(Object* a, int b): v(a), c(b) {}
    };
    std::vector<Pair> _vect;
    unsigned int _maxind;

    bool search(const Object* e, unsigned int &ind) const;
};


#endif // BAG_H

