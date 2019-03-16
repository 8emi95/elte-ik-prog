#ifndef SETREPR_H
#define SETREPR_H


class SetRepr {
public:
    virtual void setempty() 	= 0;
    virtual void insert(int e) 	= 0;
    virtual void remove(int e) 	= 0;
    virtual int  select() const = 0;
    virtual bool in(int e)const = 0;
    virtual bool empty() const 	= 0;
    virtual ~SetRepr(){};
};


#endif // SETREPR_H
