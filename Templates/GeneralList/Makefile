GPP=g++ -std=c++17

all: glist

glist: main.o
	$(GPP) $^ -o $@

main.o: main.cpp GenericList.hpp
	$(GPP) -c $<

clean:
	-rm *.o glist
