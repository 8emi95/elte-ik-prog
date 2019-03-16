#ifndef Object_H
#define Object_H
#include <string>

class Object
{
public:
    virtual ~Object() {}
    virtual bool is_Integer()    const { return false;}
    virtual bool is_String() const { return false;}
    virtual bool equalTo(const Object* r) const = 0;
};

class Integer : public Object
{
private:
    int _value;
public:
    Integer(int n) : _value(n) {}
    bool is_Integer() const { return true; }
    int  value()  const { return _value; }
    bool equalTo(const Object* o) const
    {
        return  o->is_Integer() &&  this->_value == ((Integer*)o)->_value;
    }
};

class String : public Object
{
private:
    std::string _value;
public:
    String(const std::string str) : _value(str) {}
    std::string value() const { return _value; }
    bool equalTo(const Object* o) const
    {
        return  o->is_String() &&   this->_value == ((String*)o)->_value;
    }
};

#endif // Object_H
