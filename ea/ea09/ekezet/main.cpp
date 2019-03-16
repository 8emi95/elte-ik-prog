//K�sz�tette:       Gregorics Tibor
//D�tum:            2014.04.01.
//Feladat:          �kezetes sz�veg alak�t�sa

#include <fstream>
#include <iostream>
#include <cstdlib>
#include <sstream>

using namespace std;

char konverzio(char ch);

//Feladat: 	        Alak�tsuk �t egy f�jlban elhelyezett sz�veg �kezetes mag�nhangz�it, �s
//                  az eredm�nyt helyezz�k el egy f�jlban.
//Bemen� adatok:    ifstream x  - �talak�tand� sz�veges f�jl
//Kimen� adatok:    ofstream y  - �talak�tott sz�veges f�jl
//Tev�kenys�g:	    A f�jlok sikeres nyit�sa illetve l�trehoz�sa ut�n egyenk�nt m�solja �t
//                  az input f�jl karaktereit az output f�jlba, de az �kezetes karaktereket
//                  a megfelel� form�ra alak�tva.
int main()
{
    ifstream x("inp.txt");
    if ( x.fail() ){
        cout<<"Nincs input file"<<endl;
        char ch; cin>>ch;
        exit(1);
    }

    ofstream y("out.txt");
    if ( y.fail() ){
        cout<<"Nem lehet letrehozni az output file-t"<<endl;
        char ch; cin>>ch;
        exit(1);
    }

    char ch;
    for(x.get(ch); !x.eof(); x.get(ch)){
        y << konverzio(ch);
    }

  return 0;
}

//Feladat: 	        Megadja egy bet�nek a megfelel�j�t.
//Bemen� adatok:    ch  - �talak�tand� karakter
//Kimen� adatok:    char (visszat�r�si �rt�k) - �talak�tott alak
//Tev�kenys�g:	    egy karakter megfelel�j�t adja vissza.
char konverzio(char ch)
{
    char new_ch;
    switch (ch) {
        case '�' :                          new_ch = 'a'; break;
        case '�' :                          new_ch = 'e'; break;
        case '�' :                          new_ch = 'i'; break;
        case '�' : case '�' : case '�' :    new_ch = 'o'; break;
        case '�' : case '�' : case '�' :    new_ch = 'u'; break;
        case '�' :                          new_ch = 'A'; break;
        case '�' :                          new_ch = 'E'; break;
        case '�' :                          new_ch = 'I'; break;
        case '�' : case '�' :case '�' :     new_ch = 'O'; break;
        case '�' : case '�' :case '�' :     new_ch = 'U'; break;
        default  :                          new_ch = ch;
    }
    return new_ch;
}
