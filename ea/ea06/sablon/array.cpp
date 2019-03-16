#include "array.h"
#include <fstream>
#include <iostream>
#include <cstdlib>

using namespace std;

vector<int> upload(const string &fname)
{
    vector<int> x;
    ifstream f(fname.c_str());
    if(f.fail()){
        cout << "Hiba a f�jl nyit�sakor!\n";
        exit(1);
    }
    int e;
    while(f >> e) x.push_back(e);
    return x;
}

void write(const vector<int> &x)
{
    for(unsigned int i=0; i<x.size(); ++i){
        cout << " " << x[i];
    }
}

