#ifndef ENOR_H_INCLUDED
#define ENOR_H_INCLUDED

#include<iostream>
#include<fstream>
#include<cstdlib>

class Enor
{
	public:
		Enor(std::string fnev)
		{
			x.open(fnev.c_str());
			if(x.fail())			//mar itt is lehet ellenorizni, azt hogy sikerult-e a megnyitas.
			{						//azt hogy ures-e, csak az (elso) olvasaskor!
				std::cerr<<"Fajlmegnyitasi hiba!"<<std::endl;
				exit(1);
			}
		}

		~Enor()
		{
			x.close();
		}

		void First()
		{
			vege = false;
			Next();
		}

		void Next()
		{
			x>>dx;
			vege = x.fail();
		}

		bool End() const
		{
			return vege;
		}

		int Current() const
		{
			return dx;
		}

	private:
		std::ifstream x;
		int dx;
		bool vege;
};

#endif // ENOR_H_INCLUDED
