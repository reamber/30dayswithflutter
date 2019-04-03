#Amber Liu
#al7bf
#10/18/2018
#Section 106(3:30-4:45)

CXX=clang++ $(CXXFLAGS)
CXXFLAGS= -Wall -g
#DEBUG=-Wall -g

OFILES = AVLNode.o AVLTree.o AVLPathTest.o

a.out: $(OFILES)
	$(CXX) $(OFILES) -o a.out
		
clean:
	-rm -f *.o *~ 
.SUFFIXES: .o .cpp

AVLNode.o: AVLNode.cpp AVLNode.h
AVLPathTest.o: AVLPathTest.cpp AVLTree.h AVLNode.h
AVLTree.o: AVLTree.cpp AVLTree.h AVLNode.h
