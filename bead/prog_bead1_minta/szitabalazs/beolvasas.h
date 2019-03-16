#ifndef BEOLVASAS_H_INCLUDED
#define BEOLVASAS_H_INCLUDED

#include<iostream>
#include<vector>

/*
	A beolvasashoz szukseges (es a beolvasott adatok kiirasara szolgalo) fuggvenyek
*/

char beolv_char(char egyik,char masik, const std::string uzenet);
bool beolv_korosztalyok(std::vector<int> &k, std::istream &forras, bool ismet);
bool beolv_osztalyzatok(std::vector<std::vector<int> > &o, const std::vector<int> &k, std::istream &forras, bool ismet);

void kiir_korosztalyok(const std::vector<int> &k);
void kiir_osztalyzatok(const std::vector<std::vector<int> > &o);

/*
	megjegyzes, jo tanacs: ha itt az utolso pontosvesszot veletlen lehagyom, akkor a hibat nem itt, hanem a
	beolvasas.cpp "using namespace"-enel fogja dobni. erdemes vegiggondolni, miert!
	mivel a cpp a "sor veget" a ; alapjan hatarozza meg, ezert altalaban ha lehagysz egy pontosvesszot, a kovetkezo
	sorban fog miatta reklamalni. Most azert az emlitett sor a "kovetkezo", mert ez a file be van oda include-olva, es
	ilyenkor szovegszeruen behelyettesitodik oda.
*/

#endif // BEOLVASAS_H_INCLUDED
