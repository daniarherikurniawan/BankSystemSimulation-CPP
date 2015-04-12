#ifndef _BANK_H
#define _BANK_H

#include "Teller.h"

class Bank {
	public:
		static int NoUrutPengantri;
		int GetJumlahTeller();
		Bank(int N, DateTime TMax);//N = jumlah teller
		void CetakTeller();
		void setTMax(DateTime Waktu);
		DateTime getTMax();
		bool BelumTutup();
		bool IsArrival(string s);
		void Arrival(DateTime Time);
		void Departure(string s);
		bool IsBankEmpty();
		void TerminateLoop();
	private:
		Teller *T;
		DateTime TMax;
		int JumlahTeller;
		int Jockeying(int iOrigin);
};

#endif