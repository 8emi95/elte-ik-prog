#ifndef ENUMERATOR_H
#define ENUMERATOR_H


class Enumerator
{
public:
    virtual void first() = 0;
    virtual void next() = 0;
    virtual bool end() const = 0;
    virtual int current() const = 0;
    virtual ~Enumerator(){}
};

#endif // ENUMERATOR_H
