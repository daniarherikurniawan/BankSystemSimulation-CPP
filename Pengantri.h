#ifndef _PENGANTRI_H
#define _PENGANTRI_H

#include "DateTime.h"

class Pengantri {
	public:
		Pengantri();
		Pengantri(DateTime Waktu, int Urutan);
		void setWaktuTiba(DateTime Waktu);
		void setUrutanDatang(int Urutan);
		DateTime getWaktuTiba();
		int getUrutanDatang();
	private:
		DateTime WaktuTiba;
		int UrutanDatang;
};

#endif