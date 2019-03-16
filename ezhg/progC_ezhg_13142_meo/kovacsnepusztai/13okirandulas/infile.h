#ifndef INFILE_H_INCLUDED
#define INFILE_H_INCLUDED

#include <vector>
#include <fstream>
#include <string>

using namespace std;

struct ember{
    string nev;
    vector<string> datum;
    vector<int> osszeg;
};


enum Status{abnorm, norm};

class SeqInfile
{
    private:
        ifstream f;
        ember elem;
        Status st;

        void read();
    public:
        SeqInfile(string fname);
        void First() {read();}
        void Next() {read();}
        bool End() const {return st==abnorm;}
        ember Current() const {return elem;}
        ~SeqInfile() {f.close();}



};

#endif // INFILE_H_INCLUDED
