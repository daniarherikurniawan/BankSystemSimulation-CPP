#include <iostream>
#include "Pengantri.h"
using namespace std;

Pengantri::Pengantri(){
	UrutanDatang = 0;
}
Pengantri::Pengantri(DateTime Waktu, int Urutan){
	WaktuTiba = Waktu;
	UrutanDatang = Urutan;
}
void Pengantri::setUrutanDatang(int Urutan){
	UrutanDatang = Urutan;
}
void Pengantri::setWaktuTiba(DateTime Waktu){
	WaktuTiba = Waktu;
}
DateTime Pengantri::getWaktuTiba(){
	return WaktuTiba;
}
int Pengantri::getUrutanDatang(){
	return UrutanDatang;
}