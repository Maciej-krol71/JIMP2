//Definicja struktury macierzy

//Naglowki funkcji macierz.c

#ifndef MACIERZ_H
#define MACIERZ_H

typedef struct macierz{
    int r, c;
    int **v;
} Macierz;


Macierz * stworzMacierz(int n);
void wypiszMacierz(Macierz *m);
void zwolnijMacierz(Macierz *m);

#endif
