#include<iostream>
#include<vector>
#include<cstdlib>
#include<time.h>

using namespace std;

//interface Enor<E> //enumerátor is interfész
//{
//    First()
//    Next()
//    Current()
//    End()
//};
//
//class FajlEnor : ...
//
//interface List<E> //interface Java-ban, így néz ki -> c++ absztrakt osztály
//{
//    add(E e);
//};
//
//class ArrayList<E> //ugyanúgy máküdik mind2 funkcionálisan
//{
//    add() {...}
//};
//
//class LinkedList<E>
//
//List<int> l = new List<>();
//l.add(45);

//class Eloleny
//{
//    //int labakSzama;
//    unsigned mennyiLabaVan();
//};
//
//class Ember : public Eloleny
//{
//    string nev;
//    mennyiLabaVan() { return 2; }
//};
//
//class Hallgato
//{
//private:
//    string nev;
//    string neptun;
//    int agyakSzama;
//
//public:
//    void setAgyak(int a)
//    {
//        if(a < 2)
//            agyakSzama = a;
//    }
//};
//
//    Hallgato h;
//    h.agyakSzama = 0;
//    h.setAgyak(8); //aki kívülrõl használja annak nem kell tudnia..

struct E
{
    string nev;
    int kor;
};

class Matrix //altalaban azert a deklaraciokat es definiciokat illik elvalasztani kulon fajlokba
{//default konstruktor: paraméter nélkül (?)

private:	//a matrix "reprezentacioja" kerul a privat reszbe
    vector<vector<int> > mx;
    size_t n;	//(erre vegul is nincs szukseg -- mert n = mx.size() -- csak a pelda kedveert van)

public:		//a publikba pedig az osztaly "interfesze"
    Matrix(size_t n, bool nullaz = false)	//konstruktor. hivhato (int,bool) es (int) parameterezessel is
    {
        mx.resize(n);
        this->n = n;			//ha a param. neve azonos, mint az adattag, akkor elfedi azt, de a thisen keresztul elerjuk az adattagot is
        for(size_t i=0; i<n; ++i)
        {
            mx[i].resize(n);
            for(size_t j=0; j<n; ++j)
            {
                if(nullaz)
                    mx[i][j] = 0;			//nullmatrix
                else
                    mx[i][j] = rand() % 10;	//[0..9]-beli random szamok
            }
        }
    }

    ~Matrix()	//destruktor
    {
        cout<<"Destruktor meghivodott egy "<<n<<"x"<<n<<"-es matrixon."<<endl;
    }   //lathato, ezen a ponton meg elnek a (statikus memoriabeli) attributumok!

    void Kiir(ostream& os) const //const, mert a thist (azaz azt a matrixot, akin meghivom) nem modositja
    {
        //az ostreamet viszont igen, hiszen kiir ra...
        for(size_t i=0; i<n; ++i)
        {
            for(size_t j=0; j<n; ++j)
            {
                os<<mx[i][j]<<" ";
            }
            os<<endl;
        }
    }

    int Lekerdez(size_t i,size_t j) const
    {
        return mx[i][j];
    }

    void Modosit(size_t i, size_t j, int ertek)	//ez nem const, mert modosit
    {
        //a legritkabb esetekben hasznalunk publikus adattagokat,
        mx[i][j] = ertek;		//inkabb irunk publikus lekerdezo es modosito fuggvenyeket, mint itt is.
    }							//indoklast lasd pdf-ben

};

int main()
{
    srand(time(NULL));

    Matrix m1(4);
    cout<<"m1 4-szer 4-es:"<<endl;
    m1.Kiir(cout);
    cout<<endl;

    {
        Matrix m2(4);	//blokkon belul hozva letre...
    }					//... a destruktora mar itt, a blokk vegen lefut, mig a tobbinek csak a main() vegen.
    cout<<"m2 mar nincs, szegeny"<<endl;
    cout<<endl;

    Matrix m3(3);
    Matrix m4(3);

    //m2.Kiir(cout);	//o mar nem el
    cout<<"m3 eredeti:"<<endl;
    m3.Kiir(cout);
    cout<<endl;
    cout<<"m4 eredeti:"<<endl;
    m4.Kiir(cout);
    cout<<endl;

    cout<<"A destruktorok pedig meghivodnak a letrehozassal ellentetes sorrendben (lasd hivasi verem)"<<endl;

    return 0;
}
