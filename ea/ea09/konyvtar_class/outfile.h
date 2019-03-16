#ifndef OUTFILE_H
#define OUTFILE_H

#include <fstream>
#include <string>
#include "common.h"

class outfile{
public:
    outfile(string fname="");
    void write( const konyv dy);
private:
    ofstream g;
};


#endif
