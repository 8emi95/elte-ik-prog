#ifndef ENOR_H
#define ENOR_H

#include<iostream>
#include<fstream>
#include<vector>

struct Kiccica
{
    std::string nev, nem;
};

struct Adat
{
    std::string nev;
    int kor;
    std::vector<Kiccica> kolkok;
    std::string szin;
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
        Adat akt;   //ez a "dx"
        bool vege;  //vagy Status sx, ahol a Status tipusa ez: enum Status { Norm, Abnorm };
};

#endif // ENOR_H
