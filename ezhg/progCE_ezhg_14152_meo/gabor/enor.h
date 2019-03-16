#ifndef ENOR_H
#define ENOR_H

#include<vector>
#include<sstream>
#include<iostream>
#include<fstream>
#include<cstdlib>

using namespace std;

struct Vasarlas
{
    int ev; //a redv�s null�k miatt 5 int
    int ho;
    int nap;
    int ora;
    int perc;
    string azon; //0 az elej�n
    vector<string> arukod;
};

enum Statusz { norm, abnorm };

class Felsorolo
{
private:
    ifstream fajl;
    Vasarlas vasarl;
    Statusz st;

    void read(); //egy sor beolvas�sa

public:
    void first() { read(); }
    Vasarlas current() { return this -> vasarl; }
    void next() { read(); }
    bool end() { return (this -> st == abnorm); }
    Felsorolo(string fajlnev);
    ~Felsorolo() { this -> fajl.close(); }
};

#endif // ENOR_H
