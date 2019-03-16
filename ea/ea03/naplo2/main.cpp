#include <iostream>
#include <vector>
#include "matrix_fill_keyboard.h"

using namespace std;

bool legjobb(const vector<vector<int> > &naplo, double &max, int &ind);
void osszeg_darab(const vector<int> &sor, int &s,int &c);

int main()
{
    cout.setf(ios::fixed);
    cout.precision(2);

    vector<vector<int> > naplo;
    int ind;
    double max;

    feltolt(naplo);

    if(legjobb(naplo,max,ind))
        cout << "Az egyik legjobb diák a " << ind+1
             << ". sorszámú, akinek az átlaga:" << max << endl;
    else
        cout << "Senki sem kapott osztályzatot.\n";

    return 0;
}

bool legjobb(const vector<vector<int> > &naplo, double &max, int &ind)
{
    bool l = false;
    for(int i = 0; i<(int)naplo.size(); ++i){
        int c, s;
        osszeg_darab(naplo[i],s,c);
        if(0==c) continue;
        if(l){
            if(s/c>max){
                max = (double)s/c;
                ind = i;
            }
        }else{
            l = true;
            max = s/c;
            ind = i;
        }
    }
    return l;
}

void osszeg_darab(const vector<int> &sor, int &s,int &c)
{
    s = 0.0;
    c = 0;
    for(int j = 0; j<(int)sor.size(); ++j){
        if(sor[j]!=0){
            s += sor[j];
            ++c;
        }
    }
}
