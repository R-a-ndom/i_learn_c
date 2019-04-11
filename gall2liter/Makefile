# Gallons to liters table program Makefile

gall2liter.o: gall2liter.c gall2liter.h
	gcc -Wall -c gall2liter.c

main.o: main.c
	gcc -Wall -c -o main.o main.c

gall2liter: gall2liter.o main.o
	gcc -Wall -o gall2liter main.o gall2liter.o

clean:
	rm *.o gall2liter
