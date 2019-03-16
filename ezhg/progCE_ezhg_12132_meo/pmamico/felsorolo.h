#ifndef FELSOROLO_H_INCLUDED
#define FELSOROLO_H_INCLUDED

#include <iostream>
#include <fstream>
#include <vector>

struct Korido
{
    int kor;
    std::string ido;
};

struct Struktura  //!beolvasando fajl strukturaja (egy sor)
{
    std::string nev;
    std::string csapat;
    std::vector <Korido> korido;

    bool gyorsul;

};

class Felsorolo //!felsorolo objektum
{
private:
    enum Status  //fajlbeolvasas allapota tipus
    {
        abnorm,
        norm
    };

    Status sx;  // fajl allapota
    Struktura dx; // fajl szerkezete
    std::ifstream x; // x - beolvasando fajl

    void Read(Status & sx, Struktura & dx, std::ifstream & x);//olvasas

public: //publikusan elerheto metodusok
    Felsorolo(std::string filename);
    ~Felsorolo();

    void First();
    void Next();
    Struktura Current() const;
    bool End() const;
};

#endif // FELSOROLO_H_INCLUDED
