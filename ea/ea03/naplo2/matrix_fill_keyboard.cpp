#include "matrix_fill_keyboard.h"
#include <iostream>
#include <sstream>
#include "read.h"

using namespace std;

bool jegy(int n) { return n>=0 && n<=5;}

void feltolt(vector<vector<int> > &naplo)
{
    int n = read_int("Hány diák van? ", "Természetes számot kérek!", nat);
    int m = read_int("Hány tárgy van? ", "Természetes számot kérek!", nat);

    naplo.resize(n);

    for(int i=0; i<n; ++i){
        naplo[i].resize(m);
        cout << endl;
        for(int j=0; j<m; ++j){
            stringstream ss;
            ss << i+1 << ". diák " << j+1 << ". tantárgyból kapott jegye= ";
            naplo[i][j] = read_int(ss.str(),
                                   "0 és 5 közötti egész számot kérek!",
                                   jegy);
        }
    }
    cout << endl;
}

