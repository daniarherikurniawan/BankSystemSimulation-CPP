#include <iostream>
#include <cstdlib>
#include "Date.h"
#include "Time.h"
#include "DateTime.h"
#include "Pengantri.h"
#include "Teller.h"
#include "Bank.h"
#include "Event.h"

using namespace std;

int main(){
	Event E;
	E.getInputAwal();
	E.getNextInput();
	E.LoopTerminate();
	return 0;
}

