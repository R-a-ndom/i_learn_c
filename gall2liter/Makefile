# Gallons to liters table program Makefile

gall2liter.o: gall2liter.c gall2liter.h
	gcc -c gall2liter.c

main.o: main.c
	gcc -c -o main.o main.c

gall2liter: gall2liter.o main.o
	gcc -o gall2liter main.o gall2liter.o

clean:
	rm *.o gall2liter
