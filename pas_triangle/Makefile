# Pascal triangle C program Makefile
# Program outputs Pascal triangle
# on the standard output.
# size of triangle is the first comand-line argument

pas_triangle:main.c pas_triangle.o
	gcc -Wall -o pas_triangle main.c pas_triangle.o

pas_triangle.o:pas_triangle.c pas_triangle.h
	gcc -c -Wall pas_triangle.c

clean:
	rm *.o pas_triangle

