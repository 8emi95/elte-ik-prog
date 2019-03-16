#include "matrix_fill_file.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>

using namespace std;

void feltolt(vector<vector<int> > &naplo)
{
    ifstream f("input.txt");
    if(f.fail()){
        cout << "Nincs meg az inputfájl!\n";
        exit(1);
    }

    int n,m;
    f >> n >> m;

    naplo.resize(n);
    cout << "Beolvasott adatok:\n";
    for(int i = 0; i<n; ++i){
        naplo[i].resize(m);
        for(int j = 0; j<m; ++j){
            f >> naplo[i][j];
            cout << setw(4) << naplo[i][j];
        }
        cout << endl;
    }
}

