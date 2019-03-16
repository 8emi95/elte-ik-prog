#include <iostream>
#include <vector>
#include "matrix_fill_keyboard.h"
#include "matrix_fill_file.h"
#include "read.h"

using namespace std;

bool legjobb(const vector<vector<int> > &naplo, double &max, int &ind);
void osszeg_darab(const vector<int> &sor, int &s,int &c);
bool egy_ketto(int n){ return 1==n or 2==n; }

int main()
{
    cout.setf(ios::fixed);
    cout.precision(2);

    vector<vector<int> > naplo;
    int ind;
    double max;

    cout << "Honnan olvassuk be az adatokat?\n\
    1 - Szöveges állomány\n\
    2 - Billentyűzet\n";
    int a = read_int("bevitel módja: ","1 vagy 2 lehet",egy_ketto);
    switch(a)
    {
       case 1: file::feltolt(naplo); break;
       case 2: keyboard::feltolt(naplo); break;
    }

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
