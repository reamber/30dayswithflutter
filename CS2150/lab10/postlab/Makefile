#Amber Liu
#al7bf
#11/29/2018
#postlab10

CXX=clang++ $(CXXFLAGS)
CXX2=clang++ $(CXXFLAGS2)
CXX3=clang $(CXXFLAGS3)
CXXFLAGS=-O2 -std=c++11 -o decoder
CXXFLAGS2=-O2 -std=c++11 -o encoder
CXXFLAGS3=-o linkedlist
#DEBUG=-Wall -g
OFILES=huffmanNode.o huffmandec.o
OFILES2=heap.o huffmanNode.o huffmanTree.o huffmanenc.o
OFILES3=linkedlist.o

all = encoder decoder linkedlist

decoder: $(OFILES)
	     $(CXX) $(OFILES)

encoder: $(OFILES2)
	     $(CXX2) $(OFILES2)

linkedlist: $(OFILES3)
	     $(CXX3) $(OFILES3)
		
clean:
	-rm -f *.o *~ 
.SUFFIXES = .o .cpp
