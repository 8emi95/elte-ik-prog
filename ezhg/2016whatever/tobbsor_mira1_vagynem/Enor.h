#ifndef ENOR_H
#define ENOR_H

#include<iostream>
#include<fstream>

struct Adat
{
    std::string nev;
    std::string mezony;
    std::string csapat1;
    std::string csapat2;
};

class Enor
{
    public:
        Enor(std::string fnev);
        ~Enor();
        void First();
        void Next();
        Adat Current() const { return akt; }
        bool End() const { return vege; }

    protected:
        std::ifstream x;
        Adat akt;
        bool vege;

    private:
};

#endif // ENOR_H
