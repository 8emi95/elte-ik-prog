#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

const string fnev = "f1.txt";
// Tesztek:
// [] -> []
// [1] -> [1]
// [1,2] -> [1,2], [2,1]
// [1,1] -> [1,1]
// [1,2,3] -> [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], [3,2,1]
// [1,1,2] -> [1,1,2], [1,2,1], [2,1,1]
// [1,2,3,4] ->
//   [1,2,3,4], [1,2,4,3], [1,3,2,4], [1,3,4,2], [1,4,2,3], [1,4,3,2],
//   [2,3,4,1], [2,3,1,4], [2,4,1,3], [2,4,3,1], [2,1,3,4], [2,1,4,3],
//   [3,1,2,4], [3,1,4,2], [3,2,1,4], [3,2,4,1], [3,4,1,2], [3,4,2,1],
//   [4,1,2,3], [4,1,3,2], [4,2,1,3], [4,2,3,1], [4,3,1,2], [4,3,2,1] (24 db)

vector<int> beolvas();
void permutaciok(vector<int> v);

int main()
{
    vector<int> v = beolvas();
    permutaciok(v);
    return 0;
}

vector<int> beolvas()
{
    vector<int> v;

    ifstream ifs(fnev.c_str());
    int s;
    while(ifs>>s)
        v.push_back(s);
    ifs.close();

    return v;
}

void permutaciok(vector<int> v)
{
    //...
}
