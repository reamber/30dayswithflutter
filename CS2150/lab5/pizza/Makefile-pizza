#Amber Liu
#al7bf
#10/11/2018
#Section 106(3:30-4:45)

CXX=clang++ $(CXXFLAGS)
CXXFLAGS= -Wall -O2
#DEBUG=-Wall -g

OFILES = pizza.o pizzadough.o tomatosauce.o toppings.o \
    mushrooms.o peppers.o cheese.o pepperoni.o

pizza: $(OFILES)
	$(CXX) $(DEBUG) $(OFILES) -o pizza
	@echo "Pizza is Hot and Ready!"
		
clean:
	-rm -f *.o *~ pizza
.SUFFIXES: .o .cpp

cheese.o: cheese.cpp cheese.h
mushrooms.o: mushrooms.cpp mushrooms.h
pepperoni.o: pepperoni.cpp pepperoni.h
peppers.o: peppers.cpp peppers.h
pizza.o: pizza.cpp pizzadough.h tomatosauce.h toppings.h cheese.h \
  mushrooms.h peppers.h pepperoni.h
pizzadough.o: pizzadough.cpp pizzadough.h
tomatosauce.o: tomatosauce.cpp tomatosauce.h
toppings.o: toppings.cpp toppings.h cheese.h mushrooms.h peppers.h \
  pepperoni.h

