#ifndef ENOR_INTERVAL_H
#define ENOR_INTERVAL_H

class Enor_interval
{
	public:
		Enor_interval(int m, int n);
		void First();
		void Next();
		bool End() const;
		int Current() const;

	private:
		int m,n,i;
		//seg�dv�ltoz�k amik befoly�solj�k a muveletek altal visszaadott eredmenyeket...
		//ezekben van tarolva a felsorolo "allapota"
};

#endif // ENOR_INTERVAL_H
