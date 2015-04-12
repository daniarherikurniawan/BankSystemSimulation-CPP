#include "Time.h"
#include <iostream>
using namespace std;

/* ctor */
Time::Time() {
	Jam = 0;
	Menit = 0;
	Detik = 0;
}

/* Setter/getter */
void Time::setJam(int j) { Jam = j; }
void Time::setMenit(int m) { Menit = m; }
void Time::setDetik(int d) { Detik = d; }
int Time::getJam() { return Jam; }
int Time::getMenit() { return Menit; }
int Time::getDetik() { return Detik; }

/* Fungsi lain */
int Time::TimeCompare(Time T) {
/* Jika this lebih awal dari T mengembalikan nilai -1 */
/* Jika this sama dengan T mengembalikan nilai 0 */
/* Jika this lebih akhir dari T mengembalikan nilai 1 */

	if ( Jam < T.getJam() ) {	//this.Jam < T.Jam
		return -1;
	} else if ( Jam == T.getJam() ) {	//this.Jam == T.Jam
		if ( Menit < T.getMenit() ) {	//this.Menit < T.Menit
			return -1;
		} else if ( Menit == T.getMenit() ) {	//this.Menit == T.Menit
			if ( Detik < T.getDetik() ) {	//this.detik < T.detik
				return -1;
			} else if ( Detik == T.getDetik() ) {	//this.detik == T.detik
				return 0;
			} else {	//this.detik > T.detik
				return 1;
			}
		} else {	//this.Menit > T.Menit
			return 1;
		}
	} else {	//this.Jam > T.Jam
		return 1;
	}
}