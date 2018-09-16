# Pascal triangle C program Makefile
# Program outputs Pascal triangle
# on the standard output.
# size of triangle is the first comand-line argument

pastriangle:main.c pastriangle.o
	gcc -Wall -o pastriangle main.c pastriangle.o

pastriangle.o:pastriangle.c pastriangle.h
	gcc -c -Wall pastriangle.c

clean:
	rm *.o pastriangle

