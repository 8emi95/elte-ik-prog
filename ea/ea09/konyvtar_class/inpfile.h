#ifndef INPFILE_H
#define INPFILE_H

#include <fstream>
#include <string>
#include "common.h"

typedef enum{abnorm, norm} status;

class inpfile{
public:
    inpfile(string fname="");
    void read( konyv &dx, status &sx);
private:
    ifstream f;
};


#endif
