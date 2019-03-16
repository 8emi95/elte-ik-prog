//Készítette:       Gregorics Tibor
//Dátum:            2014.04.01.
//Feladat:          Ékezetes szöveg alakítása

#include <fstream>
#include <iostream>
#include <cstdlib>
#include <sstream>

using namespace std;

char konverzio(char ch);

//Feladat: 	        Alakítsuk át egy fájlban elhelyezett szöveg ékezetes magánhangzóit, és
//                  az eredményt helyezzük el egy fájlban.
//Bemenõ adatok:    ifstream x  - átalakítandó szöveges fájl
//Kimenõ adatok:    ofstream y  - átalakított szöveges fájl
//Tevékenység:	    A fájlok sikeres nyitása illetve létrehozása után egyenként másolja át
//                  az input fájl karaktereit az output fájlba, de az ékezetes karaktereket
//                  a megfelelõ formára alakítva.
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

//Feladat: 	        Megadja egy betûnek a megfelelõjét.
//Bemenõ adatok:    ch  - átalakítandó karakter
//Kimenõ adatok:    char (visszatérési érték) - átalakított alak
//Tevékenység:	    egy karakter megfelelõjét adja vissza.
char konverzio(char ch)
{
    char new_ch;
    switch (ch) {
        case 'á' :                          new_ch = 'a'; break;
        case 'é' :                          new_ch = 'e'; break;
        case 'í' :                          new_ch = 'i'; break;
        case 'ó' : case 'ö' : case 'õ' :    new_ch = 'o'; break;
        case 'ú' : case 'ü' : case 'û' :    new_ch = 'u'; break;
        case 'Á' :                          new_ch = 'A'; break;
        case 'É' :                          new_ch = 'E'; break;
        case 'Í' :                          new_ch = 'I'; break;
        case 'Ó' : case 'Ö' :case 'Õ' :     new_ch = 'O'; break;
        case 'Ú' : case 'Ü' :case 'Û' :     new_ch = 'U'; break;
        default  :                          new_ch = ch;
    }
    return new_ch;
}
