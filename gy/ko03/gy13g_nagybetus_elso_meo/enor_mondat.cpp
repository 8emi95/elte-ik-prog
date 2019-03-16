#include "enor_mondat.h"

using namespace std;

Enor_mondat::Enor_mondat(string fnev)
{
//    ifstream x;
//    x.open("be.txt");

    x.open(fnev.c_str());
    if(x.fail())
       {
           cerr << "Kaki." << endl;
//           exit(1);
       }
}

Enor_mondat::~Enor_mondat()
{
    x.close();
}

void Enor_mondat::First()
{
    Next();
}

size_t Enor_mondat::Current() const
{
    return dx;
}

bool Enor_mondat::End() const
{
    return Abnorm == sx;
}

void Enor_mondat::Next()
{
    //x >> dx;
    getline(x, dx, '.');
    if(x.fail())
       sx = Abnorm;
}
