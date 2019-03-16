#include "enor_tomb.h"

using namespace std;

Enor_tomb::Enor_tomb(vector<int> v)
{
	this->v = v;
}

void Enor_tomb::First()
{
	i = 0;
}

void Enor_tomb::Next()
{
	++i;
}

bool Enor_tomb::End() const
{
	return i >= v.size();	//itt a tombindexel�s miatt m�r i=n eset is t�lindexel�snek sz�m�t
}

int Enor_tomb::Current() const
{
	return v[i];
}
