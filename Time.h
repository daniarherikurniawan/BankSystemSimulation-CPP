#ifndef _TIME_H
#define _TIME_H

class Time {
	private:
		int Jam,Menit,Detik;		//jam, menit, detik
	public:
		Time();
		void setJam(int j);
		void setMenit(int m);
		void setDetik(int d);
		int getJam();
		int getMenit();
		int getDetik();
		int TimeCompare(Time T);
};
#endif