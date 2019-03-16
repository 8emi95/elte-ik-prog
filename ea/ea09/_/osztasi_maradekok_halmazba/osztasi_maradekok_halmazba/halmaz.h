//Készítette:    Gregorics Tibor
//Dátum:         2009.01.24.
//Feladat:       Halmaz típus

#ifndef _HALMAZ
#define _HALMAZ

#include <vector>
#include <fstream>

// Típusérték:      0 és 99 közé esõ természetes számokat tartalmazó halmaz
// Reprezentáció:   bool v[n]       - n elemû logikai tömb: v[e] a.cs.a igaz, ha e eleme a halmaznak
//                  int db          - v-beli igaz értékek száma (a halmaz elemszáma)
// Mûveletek:       Halmaz(int n)   - üres halmaz létrehozása
//                  void Be(int e)  - elem berakása a halmazba
//                  int  Darab()    - halmaz számosságának lekérdezése
//                  operator<<()    - halmaz elemeinek kiírása
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
