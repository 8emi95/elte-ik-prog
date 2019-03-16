#ifndef ENOR_H
#define ENOR_H

#include <fstream>
#include <string>
#include <sstream>


enum Status { abnorm, norm };

struct sor {
    std::string nev;
    std::string datum;
    int osszeg;
};
struct current {
    std::string nev;
    int db;
    int osszeg;
};

class Enor {
    public:
        Enor(const std::string &fajlnev);
        void First();
        void Next();
        current Current() const { return akt; }
        bool End() const { return vege; }
    private:
        std::ifstream x;
        Status sx;
        sor dx;
        current akt;
        bool vege;
        void Read();
};

#endif
