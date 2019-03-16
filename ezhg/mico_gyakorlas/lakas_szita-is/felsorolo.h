#ifndef FELSOROLO_H_INCLUDED
#define FELSOROLO_H_INCLUDED

#include <iostream>
#include <fstream>
#include <vector>

struct Struktura
{
    std::string azon;
    int osszeg;
    std::vector <std::string> datum;
    std::vector <int> fizet;

    int bef_ossz;
    bool becsulet;
};

class Felsorolo
{
private:
    enum Status
    {
        abnorm,
        norm
    };

    Status sx;
    Struktura dx;
    std::ifstream x;

    void Read(Status & sx, Struktura & dx, std::ifstream & x);

public:
    Felsorolo(std::string fajlnev);
    ~Felsorolo();

    void First();
    void Next();
    Struktura Current() const;
    bool End() const;
};

#endif /* FELSOROLO_H */
