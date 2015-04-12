#ifndef _EVENT_H
#define _EVENT_H

#include "Bank.h"

class Event{
public:
	Event();
	void SetBank(Bank lastB);
	Bank GetBank();
	void getInputAwal();
	void getNextInput();
	void LoopTerminate();
private:
	Bank *B;
	DateTime *TMax;
};

#endif