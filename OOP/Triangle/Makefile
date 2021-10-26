GPP = g++ -std=c++17

all: multishape

multishape: Pyramid_methods.o Shape3D_methods.o Triangle_methods.o main.o
	$(GPP) $^ -o $@

Pyramid_methods.o: Pyramid_methods.cpp pyramid.hpp
	$(GPP) -c $<

Shape3D_methods.o: Shape3D_methods.cpp shape3D.hpp
	$(GPP) -c $<

Triangle_methods.o: Triangle_methods.cpp triangle.hpp
	$(GPP) -c $<

main.o: main.cpp triangle.hpp
	$(GPP) -c $<

clean:
	-rm *.o multishape
