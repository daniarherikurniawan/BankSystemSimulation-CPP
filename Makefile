OUTPUT=bin
ADT1=Date
ADT2=Time
ADT3=DateTime
ADT4=Pengantri
ADT5=Teller
ADT6=Bank
ADT7=Event

compile-test: $(MAIN).cpp $(ADT1).o $(ADT2).o $(ADT3).o $(ADT4).o $(ADT5).o $(ADT6).o $(ADT7).o
	g++ -o $(MAIN) $(MAIN).cpp $(ADT1).o $(ADT2).o $(ADT3).o $(ADT4).o $(ADT5).o $(ADT6).o $(ADT7).o
	
$(ADT1).o: $(ADT1).cpp $(ADT1).h
	g++ -c $(ADT1).cpp

$(ADT2).o: $(ADT2).cpp $(ADT2).h
	g++ -c $(ADT2).cpp

$(ADT3).o: $(ADT3).cpp $(ADT3).h
	g++ -c $(ADT3).cpp

$(ADT4).o: $(ADT4).cpp $(ADT4).h
	g++ -c $(ADT4).cpp

$(ADT5).o: $(ADT5).cpp $(ADT5).h
	g++ -c $(ADT5).cpp

$(ADT6).o: $(ADT6).cpp $(ADT6).h
	g++ -c $(ADT6).cpp

$(ADT7).o: $(ADT7).cpp $(ADT7).h
	g++ -c $(ADT7).cpp
	
grade:
	./$(MAIN)
	