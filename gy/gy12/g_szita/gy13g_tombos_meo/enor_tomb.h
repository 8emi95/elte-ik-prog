#ifndef ENOR_TOMB_H
#define ENOR_TOMB_H

#include<cstdlib>
#include<vector>

class Enor_tomb
{
	public:
		Enor_tomb(std::vector<int> v);
		void First();
		void Next();
		bool End() const;
		int Current() const;    //ez nem az az int mint a m�sik felsorol�n�l. ez az�rt int, mert int van a tombben

	private:
		std::vector<int> v; //nincs n �s m, mert a t�mbbol ki lehet talalni... tablas gyakon sem volt sose a konkret vektoros feladatokban
		size_t i;			//itt ak�r lehtne egy intervallum felsorolo is alatta
};

#endif // ENOR_TOMB_H
