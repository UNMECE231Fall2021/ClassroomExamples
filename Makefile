#target: prerequisites
	#commands

all: math_run

math_run: maths.o main.o
	gcc $^ -o $@
	#$^ = maths.o main.o, $@ = math_run

maths.o: maths.c Maths.h
	gcc -c $<
	#$< = maths.c

main.o: main.c Maths.h
	gcc -c $<
	#$< = main.c

clean:
	rm a.out
