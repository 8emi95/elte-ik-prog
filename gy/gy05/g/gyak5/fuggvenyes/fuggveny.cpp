#ifndef FUGGVENY_H_INCLUDED
#define FUGGVENY_H_INCLUDED

#include<cstdlib>
#include<time.h>
#include<vector>

//kozos feladatok:
//1. forrasfajl letrehozasa es torzsek bemasolasa
//2. extrem. elem konstanssa tetele (atalakithatobba teszi a programot)
//3. this a konstruktorba

struct Fuggveny
{
	std::vector<int> v;
	int m,n,k;

	const int hiba = -51;

	Fuggveny(int m, int n)
	{
		this->m = m;
		this->n = n;

		srand(time(NULL));

		if(n-m+1 > 0)
			v.resize(n-m+1);
		for(int i=m;i<=n;++i)
			v[i-m] = (rand() % 100 - 50);
	}

	int operator()(int i)
	{
		if(i<m || i > n)
			return -51;
		else
			return v[i-m];
	}

	void kiir()	//kiirja a fuggveny osszes erteket [m..n]-en
	{
		for(int i=m;i<=n;++i)
			std::cout<<v[i-m]<<" ";
		std::cout<<std::endl;
	}
};

#endif // FUGGVENY_H_INCLUDED
