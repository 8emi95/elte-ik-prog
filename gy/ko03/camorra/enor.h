#ifndef ENOR_H
#define ENOR_H

#include<iostream>
#include<fstream>
#include<vector>
//potencialisan mast is be kellhet include-olni...

struct Adat
{
    //Ide kerulnek a rekord adattagjai.
    //Ha nevezetes felsorolot akarunk, akkor ez egyszeruen a fajl egy soranak a "sablonja" -
    //    de ez neha feleslegesen terjengosse teszi a beolvasast.
    //Ha egyedit, akkor kb. barmi - itt tobbet kell gondolkodni, de a kod szinte biztos hogy rovidebb, egyszerubb lesz.
    //Ha azonos szerepu dologbol tobb van egy sorban (pl. minden sor egy "mozifilm" es tobb vetitesi ido van, vagy ilyesmi),
    //    akkor azt erdemes std::vectorba rakni (#include<vector>).
    //Ha egy adattag "vagy van, vagy nincs", akkor a "nincs" esetre helyettesitsuk valami extremalis ertekre
    //    (pl.: ha vagy van egy '+' jel a sorok vegen, vagy nincs, akkor a nincs esetben jeloljuk ezt mondjuk '-'-szal.
    //    Vagy ha vagy van egy termeszetes szam minden sorban, vagy nem, akkor ha nincs, jelolje az, hogy ennek az adattagnak -1
    //    erteket adunk. stb.).

    std::string iparag;
    std::vector<int> keruletek;
    //bool mind10alatt;
    std::string konk;
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

//        //külsõ golbális függvények lesznek
//        friend std::istream& operator>>(std::istream & ifs, Adat & a); //input folyam, lehet ifstrem vagy...
//        friend std::ostream& operator<<(std::ostream & ofs, const Adat & a); //output stream lehet cout vagy output file

    private:
        std::ifstream x;
        Adat akt;   //ez a "dx"
        bool vege;  //vagy Status sx, ahol a Status tipusa ez: enum Status { Norm, Abnorm };
};

#endif // ENOR_H
