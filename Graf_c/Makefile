CC = gcc
CFLAGS = -Wall -g

all: program

program: main.o macierz.o plik.o 
	$(CC) main.o macierz.o plik.o -o program

main.o: main.c macierz.h plik.h
	$(CC) $(CFLAGS) -c main.c

plik.o: plik.c plik.h macierz.h
	$(CC) $(CFLAGS) -c plik.c

macierz.o: macierz.c macierz.h
	$(CC) $(CFLAGS) -c macierz.c

clean:
	rm -f *.o
