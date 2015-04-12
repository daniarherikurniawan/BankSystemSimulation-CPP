#include <iostream>
#include "DateTime.h"
using namespace std;

/* ctor */
DateTime::DateTime() {}	//ctor tanpa parameter
DateTime::DateTime(string format) {
/* Membentuk DateTime dari string dengan format "DD-MM-YYYY;JJ:MM:DD" */
	int a,b,c;
	
	a = 10*(format[0] - '0') + format[1] - '0';
	b = 10*(format[3] - '0') + format[4] - '0';
	c = 1000*(format[6] - '0') + 100*(format[7] - '0') + 10*(format[8] - '0')
		+ (format[9] - '0');
	D.setDD(a);
	D.setMM(b);
	D.setYY(c);
	
	a = 10*(format[11] - '0') + format[12] - '0';
	b = 10*(format[14] - '0') + format[15] - '0'; 
	c = 10*(format[17] - '0') + format[18] - '0'; 
	T.setJam(a);
	T.setMenit(b);
	T.setDetik(c);
}

/* Getter */
Date DateTime::getDate() { return D; }
Time DateTime::getTime() { return T; }

/* Fungsi lain */
void DateTime::PrintDateTime() {
		cout << "Date: ";
		cout << D.getDD() << "-" << D.getMM() << "-" << D.getYY() << endl;
		cout << "Time: ";
		cout << T.getJam() << ":" << T.getMenit() << ":" << T.getDetik() << endl;
}

int DateTime::DateTimeCompare(DateTime DT) {
/* Jika this lebih awal dari DT mengembalikan nilai -1 */
/* Jika this sama dengan DT mengembalikan nilai 0 */
/* Jika this lebih akhir dari DT mengembalikan nilai 1 */

	if ( D.DateCompare(DT.getDate()) != 0 ) {	//this != DT
		return D.DateCompare(DT.getDate());
	} else {	//this == DT
		return T.TimeCompare(DT.getTime());
	}
}