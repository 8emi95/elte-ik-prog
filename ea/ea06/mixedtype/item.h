#ifndef ITEM_H
#define ITEM_H
#include <string>

class Item
{
public:
    virtual ~Item() {}
    virtual bool is_Int()    const { return false;}
    virtual bool is_String() const { return false;}
    virtual bool equalTo(const Item* r) const { return false; };
};

class Int : public Item
{
private:
    int _value;
public:
    Int(int n) : _value(n) {}
    bool is_Int() const { return true; }
    int  value()  const { return _value; }
    bool equalTo(const Item* r) const
    {
        return  r->is_Int() &&  this->value() == ((Int*)r)->value();
    }
};

class String : public Item
{
private:
    std::string _value;
public:
    String(const std::string str) : _value(str) {}
    std::string value() const { return _value; }
    bool equalTo(const Item* r) const
    {
        return  r->is_String() &&   this->value() == ((String*)r)->value();
    }
};

#endif // ITEM_H
