#ifndef FELSOROLO_H
#define FELSOROLO_H
#include <vector>
#include <fstream>

struct kutya
{
    std::string nev;
    int chipszam;
    std::vector<int> szorzo;
    std::vector<int> pontszam;
    int osszpontszam;
};

class felsorolo
{
    public:
        felsorolo(std::string fajlnev);
        void First();
        void Next();
        kutya Current();
        bool End();
    private:
        bool sx;
        kutya dx;
        std::fstream x;
};

#endif // FELSOROLO_H
