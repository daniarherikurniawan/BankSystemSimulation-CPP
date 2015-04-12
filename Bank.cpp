#include "Bank.h"
#include <cstdlib>
#include <iostream>
using namespace std;

Bank::Bank(int N, DateTime TMax){
	this->TMax = TMax;
	JumlahTeller = N;
	T = new Teller[N];
	for(int a = 0 ; a< JumlahTeller; a++){
		T[a].setNoUrut(a);
		T[a].setJumlahAntrian(0);
	}
}
int Bank::GetJumlahTeller(){
	return JumlahTeller;
}
int Bank::NoUrutPengantri = 0;
void Bank::CetakTeller(){
	for(int a = 0; a < JumlahTeller ; a++){
		T[a].CetakAntrian();
	}
}
void Bank::setTMax(DateTime Waktu){
	TMax = Waktu;
}
DateTime Bank::getTMax(){
	return TMax;
}
bool Bank::BelumTutup(){
	return true;
}
bool Bank::IsArrival(string s){
	if(s[21-1]=='A'){
		NoUrutPengantri ++;
		return true;
	}else{
		return false;
	}
}
bool Bank::IsBankEmpty(){
	for(int a = 0 ; a <JumlahTeller; a++){
		if(!T[a].IsEmpty()){
			return false;
		}
	}
	return true;
}
void Bank::Arrival(DateTime Time){
	int NoUrutTeller = T[0].getNoUrut();
	int JumlahAntrian = T[0].getJumlahAntrian();
	for(int a = 1; a< JumlahTeller; a++){
		if(JumlahAntrian > T[a].getJumlahAntrian()){
			NoUrutTeller = T[a].getNoUrut();
			JumlahAntrian = T[a].getJumlahAntrian();
		}
	}
	T[NoUrutTeller].Arrive(NoUrutPengantri,Time);
}
void Bank::Departure(string s){
	string No;
	int Length = s.length();
	int UrutanTeller;
	No = s.substr(22,Length-22);
	int idPengantri = atoi(No.c_str()) ;
	for(int a = 0; a < JumlahTeller; a++){
		if(!T[a].IsEmpty()){
			if(T[a].Head() == idPengantri){
				UrutanTeller = a;
			}
		}
	}
	T[UrutanTeller].Departure();
	int TujuanJockeying = Jockeying(UrutanTeller);
	if ( TujuanJockeying != -1 ) {
		int Tail = T[UrutanTeller].Tail();
		DateTime Time = T[UrutanTeller].TimeOfTail();
		T[UrutanTeller].DepartureByJockeying();
		T[TujuanJockeying].Arrive(Tail,Time);
	}
}
void Bank::TerminateLoop(){
	for(int a = 0; a < JumlahTeller; a++){
		while(!T[a].IsEmpty()){
			cout<<"Departure "<<T[a].Head()<<endl;
			T[a].Departure();
		}
	}
}
int Bank::Jockeying(int iOrigin) {
	int minkiri, Nominkiri;
	int minkanan, Nominkanan;
	
	Nominkiri = iOrigin;
	minkiri = T[iOrigin].getJumlahAntrian();
	for (int i=0; i<iOrigin; i++) {		//mengecek antrian di sebelah "kiri" iOrigin
		if ( (T[iOrigin].getJumlahAntrian()-T[i].getJumlahAntrian() > 2) && T[i].getJumlahAntrian() <= minkiri ) {
			Nominkiri = i;
			minkiri = T[i].getJumlahAntrian();
		}
	}

	Nominkanan = iOrigin;
	minkanan = T[iOrigin].getJumlahAntrian();
	for (int i=iOrigin+1; i<JumlahTeller; i++) {	//mengecek antrian di sebelah "kanan" iOrigin
		if ( (T[iOrigin].getJumlahAntrian()-T[i].getJumlahAntrian() > 2) && T[i].getJumlahAntrian() < minkanan ) {
			Nominkanan = i;
			minkanan = T[i].getJumlahAntrian();
		}
	}
	
	if (minkiri > minkanan) {
		minkiri = minkanan;
		Nominkiri = Nominkanan;
	} else if (minkiri == minkanan) {
		if ( (iOrigin-Nominkiri) > (Nominkanan-iOrigin) ) {		//sebelah kiri lebih jauh dari sebelah kanan
			Nominkiri = Nominkanan;
		}
	}
	
	if (Nominkiri == iOrigin) {		//tidak terjadi jockeying
		return -1;
	} else {
		return Nominkiri;
	}
}