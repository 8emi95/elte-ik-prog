#ifndef ENOR_H
#define ENOR_H

#include <fstream>
#include <string>
#include <sstream>


enum Status { abnorm, norm };

struct fogas {
    int versenyzo;
    std::string halfajta;
    double meret;
};
struct ponty30nagy {
    int versenyzo;
    int db;
};

class Enor {
    public:
        Enor(const std::string &fajlnev);
        void First();
        void Next();
        ponty30nagy Current() const { return akt; }
        bool End() const { return vege; }
    private:
        std::ifstream x;
        Status sx;
        fogas dx;
        ponty30nagy akt;
        bool vege;
        void Read();
};

#endif
