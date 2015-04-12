#ifndef _TELLER_H
#define _TELLER_H

#include "Pengantri.h"

class Teller{
	public:
		Teller();
		Teller(int Urutan,int N);// N = jumlah antrian pada teller
		void CetakAntrian();
		void setJumlahAntrian(int N);
		void setNoUrut(int N);
		int getJumlahAntrian();
		int getNoUrut();
		void Arrive(int Urutan, DateTime Waktu);
		void Departure();
		bool IsEmpty();
		void DepartureByJockeying();
		int Head();
		int Tail();
		DateTime TimeOfTail();
		~Teller();
	private:
		int NoUrut;
		Pengantri *Q;
		int JumlahAntrian;
};

#endif