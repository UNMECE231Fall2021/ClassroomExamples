GPP=g++ -std=c++17

all: list_int

list_int: main.o int_list_methods.o
	$(GPP) $^ -o $@

int_list_methods.o: int_list_methods.cpp IntList.hpp
	$(GPP) -c $<

main.o: main.cpp IntList.hpp
	$(GPP) -c $<

clean:
	-rm *.o list_int
