#Amber Liu
#al7bf
#11/27/2018
#Section 106(3:30-4:45)

CXX=clang++ 
CXXFLAGS= -Wall -g

OFILES = heap.o huffmanNode.o huffmanTree.o huffmanenc.o

main: $(OFILES)
	$(CXX) $(OFILES)
		
clean:
	-rm -f *.o *~ 
.SUFFIXES = .o .cpp

heap.o: heap.cpp heap.h huffmanNode.h
huffmanNode.o: huffmanNode.cpp huffmanNode.h
huffmanTree.o: huffmanTree.cpp huffmanTree.h huffmanNode.h heap.h
huffmanenc.o: huffmanenc.cpp heap.h huffmanNode.h huffmanTree.h