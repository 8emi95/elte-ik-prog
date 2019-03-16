#include "matrix_fill_keyboard.h"
#include <iostream>
#include <sstream>
#include "read.h"

using namespace std;

bool jegy(int n) { return n>=0 && n<=5;}

void feltolt(vector<vector<int> > &naplo)
{
    int n = read_int("H�ny di�k van? ", "Term�szetes sz�mot k�rek!", nat);
    int m = read_int("H�ny t�rgy van? ", "Term�szetes sz�mot k�rek!", nat);

    naplo.resize(n);

    for(int i=0; i<n; ++i){
        naplo[i].resize(m);
        cout << endl;
        for(int j=0; j<m; ++j){
            stringstream ss;
            ss << i+1 << ". di�k " << j+1 << ". tant�rgyb�l kapott jegye= ";
            naplo[i][j] = read_int(ss.str(),
                                   "0 �s 5 k�z�tti eg�sz sz�mot k�rek!",
                                   jegy);
        }
    }
    cout << endl;
}

