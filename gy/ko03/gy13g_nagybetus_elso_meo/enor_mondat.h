#ifndef ENOR_MONDAT_H
#define ENOR_MONDAT_H

#include <iostream>
#include <fstream>
#include "kozos.h"

//using namespace std; //ki lehet rakni, nem lesz g�z

class Enor_mondat
{
//    public:
//        Enor_mondat(std::string fnev);
//        ~Enor_mondat();
//        void First();
//        std::string Current() const; //cpp f�jlban is oda kell �rni a const-ot
//        bool End() const;
//        void Next();
//    private:
//        std::ifstream x;
//        std:: string dx;
//        Status sx;

    public:
        Enor_mondat(std::string fnev);
        ~Enor_mondat();
        void First();
        std::string Current() const; //cpp f�jlban is oda kell �rni a const-ot
        bool End() const;
        void Next();
    private:
        std::ifstream x;
        size_t dx;
        Status sx;
};

#endif // ENOR_MONDAT_H
