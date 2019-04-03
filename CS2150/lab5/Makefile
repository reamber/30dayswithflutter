#Amber Liu
#al7bf
#10/16/2018
#Section 106(3:30-4:45)

CXX=clang++ $(CXXFLAGS)
CXXFLAGS= -Wall -g
#DEBUG=-Wall -g

OFILES = BinaryNode.o BinarySearchTree.o BSTPathTest.o

a.out: $(OFILES)
	$(CXX) $(OFILES) -o a.out
		
clean:
	-rm -f *.o *~ 
.SUFFIXES: .o .cpp

BSTPathTest.o: BSTPathTest.cpp BinarySearchTree.h BinaryNode.h
BinaryNode.o: BinaryNode.cpp BinaryNode.h
BinarySearchTree.o: BinarySearchTree.cpp BinarySearchTree.h BinaryNode.h
