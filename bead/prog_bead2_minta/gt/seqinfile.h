#ifndef SEQINFILE_H
#define SEQINFILE_H

#include <fstream>

struct Student{
    std::string name;
    int test1, test2, exam;
    bool accept, include;
};

enum Status{abnorm, norm};

class SeqInFile
{
    public:
        SeqInFile(const std::string &fname);
        void First() { read();}
        void Next()  { read();}
        Student Current() const { return e; }
        bool End() const { return abnorm==st; }
    private:
        std::ifstream x;
        Student e;
        Status st;

        void read();
};

#endif // SEQINFILE_H
