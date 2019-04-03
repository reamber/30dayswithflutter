#Amber Liu
#al7bf
#12/03/2018

CXX=clang++ 
CXXFLAGS= -Wall -g
#DEBUG=-Wall -g

OFILES = topological.o middleearth.o

a.out: $(OFILES)
	$(CXX) $(OFILES)
	doxygen
		
clean:
	-rm -f *.o *~ 
.SUFFIXES: .o .cpp

