#Amber Liu
#al7bf
#11/28/2018
#Section 106(3:30-4:45)

CXX=clang++ 
CXXFLAGS= -Wall -g

OFILES = huffmanNode.o huffmandec.o

main: $(OFILES)
	$(CXX) $(OFILES)
		
clean:
	-rm -f *.o *~ 
.SUFFIXES = .o .cpp

huffmanNode.o: huffmanNode.cpp huffmanNode.h
huffmandec.o: huffmandec.cpp huffmanNode.h