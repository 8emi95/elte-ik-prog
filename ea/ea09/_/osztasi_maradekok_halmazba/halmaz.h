//K�sz�tette:    Gregorics Tibor
//D�tum:         2009.01.24.
//Feladat:       Halmaz t�pus

#ifndef _HALMAZ
#define _HALMAZ

#include <vector>
#include <fstream>

// T�pus�rt�k:      0 �s k-1 k�z� es� term�szetes sz�mokat tartalmaz� halmaz
// Reprezent�ci�:   bool *v         - logikai t�mbre mutat�: v[e] a.cs.a igaz, ha e eleme a halmaznak
//                  int db          - v-beli igaz �rt�kek sz�ma (a halmaz elemsz�ma)
// M�veletek:       Halmaz(int k)   - �res halmaz l�trehoz�sa
//                  void Be(int e)  - elem berak�sa a halmazba
//                  int  Darab()    - halmaz sz�moss�g�nak lek�rdez�se
//                  operator<<()    - halmaz elemeinek ki�r�sa
class Halmaz{
public:
    struct Exception {int WrongInput;};
    Halmaz(int k);
    void Be(int e);
    int  Darab() const;
    friend std::ostream& operator<<(std::ostream& o, const Halmaz &h);
private:
    std::vector<bool> v;
    int k;
    int  db;
};

#endif
