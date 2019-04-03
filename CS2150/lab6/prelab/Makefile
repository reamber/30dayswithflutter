#Amber Liu
#al7bf
#10/23/2018
#Section 106(3:30-4:45)

CXX=clang++ -Wall -std=c++11 $(CXXFLAGS)
CXXFLAGS= -Wall -O2
#DEBUG=-Wall -g

OFILES = wordPuzzle.o hashTable.o timer.o

a.out: $(OFILES)
	$(CXX) $(OFILES) -o a.out
		
clean:
	-rm -f *.o *~ 
.SUFFIXES = .o .cpp

hashTable.o: hashTable.cpp hashTable.h
timer.o: timer.cpp timer.h
wordPuzzle.o: wordPuzzle.cpp hashTable.h timer.h
