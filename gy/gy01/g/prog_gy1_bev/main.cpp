#include <iostream>

using namespace std;
//namespace

const int MAXN = 300; //m�s sz�m kell akk csak ezt kelljen �t�rni, const h ne lehessen �t�rni
const int MAXM = 500;

int szgk[MAXN];
int utas[MAXM]; //ha minden fv haszn�lja, ha van egy aki nem haszn�lja akk m�r ink mainben deifini�ljuk

//glob�lis v�ltoz�k h�tr�nya...

int main()
{
    int kutya[MAXM];
    int m = 100;
    //f�ggv�nyekbe
    int m = tombBeolvasas(kutya,m);
    cout << m; //std::cout... namespsace n�lk�l
    //szamolas();
    kiiras();

    return 0;
}

//void mell�khat�sos fv?
int tombBeolvasas(int kutya[MAXM], int &n) //t�mb mutat� a t�mb els� elem�re n�zve, nem m�sol�dik
{
    //�rdemes minden v�ltoz�t a lehet� legsz�kebb helyen defini�lni
    string s;

    cin >> s;
    int n = atoi(s.c_str()); //sz�mot stringk�nt beolvas, sz�mm� konvert�l, ha nem siker�l akk 0?
    n = 5;
    for(...)
            ...kutya[i] = 20 //az lesz

    return n; //vissza kell t�rni vmivel
}


//elfed�s: fels� blokkban defini�lok egy v�ltoz�t amit k�v�l defini�ltam
//l�that�s�g:

//konvenci�: ha 1 utas�t�s van for-ban akk el lehet hagyni {-t
//t�rdel�s fontos

//int i;
//for(int i..) elfelejtj�k dklar�lni (int hi�nyzik) akk for-on k�v�li i lesz az �rt�ke
