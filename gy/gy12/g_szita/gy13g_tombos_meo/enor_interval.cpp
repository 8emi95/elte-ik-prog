#include "enor_interval.h"

Enor_interval::Enor_interval(int m, int n)	//mindig itt inicializ�ljuk a felsorol�t
{
	this->m = m;
	this->n = n;
}

void Enor_interval::First()
{
	i = m;	//ez a this->m
}

void Enor_interval::Next()	//a next szemantikaja az, hogy ha eddig !End() volt, akkor most "probal" olvasni
{							//es ha nem sikerul, azzal elrontja az endet (ez az�rt j� �gy mert mindig elore
	++i;					//olvasunk a ciklusainkban, tehat megkisereljuk az olvasast a ciklusmag vegen,
}							//ez igazza teszi End()-et, es a ciklusmagba ezert nem is lep be ujra.
							//nagyon fontos! a felsorol�s V�G�N �llva az End m�g hamis. UT�NA lesz igaz!
bool Enor_interval::End() const
{
	return i > n;	//lehet itt is l�tni. [m..n]-t sorolunk fel, akkor lett v�ge, amikor M�R t�ll�pt�nk
}					//(itt most nem vontam le 1-et mint a tombindexel�sn�l, azt megtettem ott, ahol haszn�lom ezt a felsorol�t)

int Enor_interval::Current() const
{
	return i;
}
