#ifndef ENOR_H
#define ENOR_H

#include<iostream>
#include<fstream>
#include<vector>

struct Par
{
    int hely;
    char tipus;
};

struct Adat
{
    std::string azon;
    std::string terem;
    std::string ido;
    std::vector<Par> jegyek;
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
