#include <iostream>

using namespace std;
//namespace

const int MAXN = 300; //más szám kell akk csak ezt kelljen átírni, const h ne lehessen átírni
const int MAXM = 500;

int szgk[MAXN];
int utas[MAXM]; //ha minden fv használja, ha van egy aki nem használja akk már ink mainben deifiniáljuk

//globális változók hátránya...

int main()
{
    int kutya[MAXM];
    int m = 100;
    //függvényekbe
    int m = tombBeolvasas(kutya,m);
    cout << m; //std::cout... namespsace nélkül
    //szamolas();
    kiiras();

    return 0;
}

//void mellékhatásos fv?
int tombBeolvasas(int kutya[MAXM], int &n) //tömb mutató a tömb elsõ elemére nézve, nem másolódik
{
    //érdemes minden változót a lehetõ legszûkebb helyen definiálni
    string s;

    cin >> s;
    int n = atoi(s.c_str()); //számot stringként beolvas, számmá konvertál, ha nem sikerül akk 0?
    n = 5;
    for(...)
            ...kutya[i] = 20 //az lesz

    return n; //vissza kell térni vmivel
}


//elfedés: felsõ blokkban definiálok egy változót amit kívül definiáltam
//láthatóság:

//konvenció: ha 1 utasítás van for-ban akk el lehet hagyni {-t
//tördelés fontos

//int i;
//for(int i..) elfelejtjük dklarálni (int hiányzik) akk for-on kívüli i lesz az értéke
