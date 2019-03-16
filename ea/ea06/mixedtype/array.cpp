#include "array.h"
#include <fstream>
#include <iostream>
#include <cstdlib>

using namespace std;

vector<Item*> upload(const string &fname)
{
    vector<Item*> x;
    ifstream f(fname.c_str());
    if(f.fail()){
        cout << "Hiba a fájl nyitásakor!\n";
        exit(1);
    }

    x.push_back(new String("str"));
    int e;
    while(f >> e){
       x.push_back(new Int(e));
    }
//    x.push_back(new String("str"));
    x.push_back(new String("str"));
    return x;
}

void write(const vector<Item*> &x)
{
    for(unsigned int i=0; i<x.size(); ++i){
        if(x[i]->is_Int()) cout << " " << ((Int*)x[i])->value();
        else if(x[i]->is_String()) cout << " " << ((String*)x[i])->value();
    }
}

