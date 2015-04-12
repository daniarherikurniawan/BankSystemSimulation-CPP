#include "Teller.h"
#include <iostream>
using namespace std;

Teller::Teller(){
	JumlahAntrian = 0;
	//Q = new Pengantri[1];
}
Teller::Teller(int Urutan,int N){
	NoUrut = Urutan;
	JumlahAntrian= N;
	Q = new Pengantri[N+1];
}
Teller::~Teller(){
	delete Q;
}
int Teller::Head(){
	return Q[1].getUrutanDatang();
}
int Teller::Tail(){
	return Q[getJumlahAntrian()].getUrutanDatang();
}
DateTime Teller::TimeOfTail(){
	return Q[getJumlahAntrian()].getWaktuTiba();
}
bool Teller::IsEmpty(){
	return JumlahAntrian==0;
}
int Teller::getJumlahAntrian(){
	return JumlahAntrian;
}
int Teller::getNoUrut(){
	return NoUrut;
}
void Teller::setJumlahAntrian(int N){
	JumlahAntrian = N;
}
void Teller::setNoUrut(int N){
	NoUrut = N;
}
void Teller::CetakAntrian(){
	if(JumlahAntrian != 0){
		cout<<"Q["<<NoUrut<<"] = {";
		for(int a = 1 ; a<= JumlahAntrian; a++){
			cout<<Q[a].getUrutanDatang();
			if(a != JumlahAntrian){
				cout<<", ";
			}else{
				cout<<"}"<<endl;
			}
		}
	}
}
void Teller::DepartureByJockeying(){
	JumlahAntrian--;
	Pengantri *R= new Pengantri[JumlahAntrian+1];
	int b;
	for( b = 0; b <= JumlahAntrian; b++){
		R[b].setUrutanDatang(Q[b].getUrutanDatang());
		R[b].setWaktuTiba(Q[b].getWaktuTiba());
	}
	delete [] Q;
	Q = new Pengantri[JumlahAntrian];
	Q = R;
}
void Teller::Arrive(int Urutan,DateTime Waktu){
	JumlahAntrian++;
	Pengantri *R= new Pengantri[JumlahAntrian+1];
	int b;
	
	for( b = 1; b < JumlahAntrian; b++){
		R[b].setUrutanDatang(Q[b].getUrutanDatang());
		R[b].setWaktuTiba(Q[b].getWaktuTiba());
	}
	
	R[b].setUrutanDatang(Urutan);
	R[b].setWaktuTiba(Waktu);
	if(getJumlahAntrian()!=1){
		delete [] Q;
	}
	Q = new Pengantri[JumlahAntrian];
	Q = R;
}

void Teller::Departure(){
	JumlahAntrian--;
	Pengantri *R= new Pengantri[JumlahAntrian+1];
	int b;
	for( b = 1; b <= JumlahAntrian; b++){
		R[b].setUrutanDatang(Q[b+1].getUrutanDatang());
		R[b].setWaktuTiba(Q[b+1].getWaktuTiba());
	}
	delete [] Q;
	Q = new Pengantri[JumlahAntrian];
	Q = R;
}