#Amber Liu
#al7bf
#12/04/2018
#inlab makefile

CXX=clang++ 
CXXFLAGS= -Wall -g
#DEBUG=-Wall -g

OFILES = traveling.o middleearth.o

main: $(OFILES)
	$(CXX) $(OFILES)
	doxygen
		
clean:
	-rm -f *.o *~ 
.SUFFIXES: .o .cpp

