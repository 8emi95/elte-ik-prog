#ifndef BAG_H
#define BAG_H
#include <vector>

class Bag
{
public:
    enum Exceptions {EmptyBag};
    Bag()
    {
        setEmpty();
    }
    void setEmpty()
    {
        _vect.clear();
    }
    void putIn(int e);
    int  maxElem() const;
private:
    struct Pair
    {
        int v;
        int c;
        Pair() {}
        Pair(int a, int b): v(a), c(b) {}
    };
    std::vector<Pair> _vect;
    unsigned int _maxind;

    bool search(int e, unsigned int &ind) const;
};

#endif // BAG_H
