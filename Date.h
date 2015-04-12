#ifndef _DATE_H
#define _DATE_H

#include <iostream>
using namespace std;

class Date {
	private:
		int DD;		//tanggal
		int MM;		//bulan
		int YY;	//tahun
	public:
		Date();
		void setDD(int D);
		void setMM(int M);
		void setYY(int Y);
		int getDD();
		int getMM();
		int getYY();
		int DateCompare(Date D);
};

#endif