#include <iostream>
#include "Date.h"
using namespace std;

/* ctor */
Date::Date() {
	DD = 0;
	MM = 0;
	YY = 0;
}

/* Setter/getter */
void Date::setDD(int D) { DD = D; }
void Date::setMM(int M) { MM = M; }
void Date::setYY(int Y) { YY = Y; }
int Date::getDD() { return DD; }
int Date::getMM() { return MM; }
int Date::getYY() { return YY; }

/* Fungsi lain */
int Date::DateCompare(Date D) {
/* Jika this lebih awal dari D mengembalikan nilai -1 */
/* Jika this sama dengan D mengembalikan nilai 0 */
/* Jika this lebih akhir dari D mengembalikan nilai 1 */

	if ( YY < D.getYY() ) {		//tahun this < tahun D
		return -1;
	} else if ( YY == D.getYY() ) {	//tahun this == tahun D
		if ( MM < D.getMM() ) {		//bulan this < bulan D
			return -1;
		} else if ( MM == D.getMM() ){	//bulan this == bulan D
			if ( DD < D.getDD() ) {		//tanggal this > tanggal D
				return -1;
			} else if ( DD == D.getDD() ) {	//tanggal this == tanggal D
				return 0;
			} else {	//tangal this > tanggal D
				return 1;
			}
		} else {	//bulan this > bulan D
			return 1;
		}
	} else {	//tahun this > tahun D
		return 1;
	}
}
