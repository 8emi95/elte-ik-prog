//K�sz�tette:    Gregorics Tibor
//D�tum:         2009.01.24.
//Feladat:       Halmaz t�pus

#ifndef _HALMAZ
#define _HALMAZ

#include <vector>
#include <fstream>

// T�pus�rt�k:      0 �s 99 k�z� es� term�szetes sz�mokat tartalmaz� halmaz
// Reprezent�ci�:   bool v[n]       - n elem� logikai t�mb: v[e] a.cs.a igaz, ha e eleme a halmaznak
//                  int db          - v-beli igaz �rt�kek sz�ma (a halmaz elemsz�ma)
// M�veletek:       Halmaz(int n)   - �res halmaz l�trehoz�sa
//                  void Be(int e)  - elem berak�sa a halmazba
//                  int  Darab()    - halmaz sz�moss�g�nak lek�rdez�se
//                  operator<<()    - halmaz elemeinek ki�r�sa
class Halmaz{
public:
    struct Exception {int WrongInput;};
    Halmaz();
    void Be(int e) throw (Exception);
    int  Darab() const;
    friend std::ostream& operator<<(std::ostream& o, const Halmaz &h);
private:
    static const int n = 100;
    bool v[n];
    int  db;
};

#endif
