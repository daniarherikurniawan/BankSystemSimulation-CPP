#ifndef _DATETIME_H
#define _DATETIME_H

#include "Date.h"
#include "Time.h"

class DateTime {
	private:
		Date D;
		Time T;
	public:
		DateTime();
		DateTime(string format);
		Date getDate();
		Time getTime();
		int DateTimeCompare(DateTime DT);
		void PrintDateTime();
};

#endif