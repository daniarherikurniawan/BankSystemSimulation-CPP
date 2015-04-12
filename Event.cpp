#include <iostream>
#include "Event.h"

using namespace std;
Event::Event(){

}
void Event::SetBank(Bank lastB){
	//method ini dipanggil jika Bank sebelumnya memang sudah ada
	B = new Bank(lastB.GetJumlahTeller(),lastB.GetTMax());
}
Bank Event::GetBank(){
	return *B;
}
void Event::getInputAwal(){
	//method ini digunakan untuk membuat bank
	string s,temp;
	int n;
	cout<<"Masukkan TMax : "; cin>>s; 
	cout<<"Masukkan jumlah teller : "; cin>>n; getline(cin,temp);
	TMax = new DateTime(s);
	B = new Bank(n,*TMax);
}
void Event::getNextInput(){
	int status = -1;
	string s;
	while(status ==-1){
		cout<<"Masukkan input : ";
		getline(cin,s);
		DateTime Time(s);
		status = Time.DateTimeCompare(*TMax);
		if(status == -1){
			if(B->IsArrival(s)){
				B->Arrival(Time);
			}else{
				B->Departure(s);
			}
			B->CetakTeller();
		}
	}
}
void Event::LoopTerminate(){
	if(!B->IsBankEmpty()){
		cout<<"Loop terminate"<<endl;
		B->TerminateLoop();
	}
}