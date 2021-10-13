GPP= g++ -std=c++17

all: base_shape

base_shape: Cube_methods.o Rectangle_methods.o main.o
	$(GPP) $^ -o $@

Cube_methods.o: Cube_methods.cpp cube.hpp
	$(GPP) -c $< 

Rectangle_methods.o: Rectangle_methods.cpp rectangle.hpp
	$(GPP) -c $< 

main.o: main.cpp rectangle.hpp cube.hpp
	$(GPP) -c $<

clean:
	-rm *.o base_shape
