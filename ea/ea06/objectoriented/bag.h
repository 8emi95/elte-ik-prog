#ifndef BAG_H
#define BAG_H
#include <vector>

class Bag
{
public:
    enum Exceptions {EmptyBag};

    void setEmpty(int n){
        _vect.resize(n);
        _m = 0;
    }
    void putIn(int e);
    int  maxElem() const;
private:
    struct Pair{
        int v;
        int c;
        Pair(){}
        Pair(int a, int b): v(a), c(b) {}
    };
    std::vector<Pair> _vect;
    int _m;
    int _mind;

    bool search(int e, int &ind) const;
};

#endif // BAG_H

