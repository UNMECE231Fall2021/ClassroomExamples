GPP = g++ -std=c++17

all: multishape

multishape: Triangle_methods.o main.o
	$(GPP) $^ -o $@

Triangle_methods.o: Triangle_methods.cpp triangle.hpp
	$(GPP) -c $<

main.o: main.cpp triangle.hpp
	$(GPP) -c $<

clean:
	-rm *.o multishape
