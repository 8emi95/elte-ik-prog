#include <vector>
#include <iostream>
#include <fstream>
#include "array.h"
using namespace std;

unsigned int mostFrequented(const vector<int> &x);
unsigned int frequency(const vector<int> &x, unsigned int i);

int main()
{
    ifstream f( "input.txt" );
    if(f.fail()){
        cout << "Hiba a fajl nyitasakor!\n";
        return 1;
    }

    vector<int> x;
    int e;
    while(f >> e) x.push_back(e);

    if(x.size()==0){
        cout << "Ures tombben nincs értelme a kerdesnek.\n";
        return 0;
    } else {
        cout << "A megadott tomb leggyakoribb eleme: "
             << x[mostFrequented(x)] << endl;
    }

    return 0;
}

unsigned int mostFrequented(const vector<int> &x)
{
    unsigned int max = 0;
    unsigned int ind = 0;
    for(unsigned int i=0; i<x.size(); ++i){
        unsigned int c = frequency(x,i);
        if(max < c){
            max = c;
            ind = i;
        }
    }
    return ind;
}

unsigned int frequency(const vector<int> &x, unsigned int i)
{
    unsigned int c = 0;
    for(unsigned int j=0; j<i; ++j){
        if(x[j]==x[i]) ++c;
    }
    return c;
}

