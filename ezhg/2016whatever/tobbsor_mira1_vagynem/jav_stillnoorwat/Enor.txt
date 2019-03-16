#ifndef ENOR_H
#define ENOR_H

#include<iostream>
#include<vector>
#include<fstream>

struct Par
{
    int adag;
    std::string tipus;
};

struct Adat
{
    std::vector<std::string> rovidetes;
    int asztalszam;
    std::string ido;
    std::vector<Par> p;

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

    private:
        std::ifstream x;
        Adat akt;
        bool vege;
};

#endif // ENOR_H
