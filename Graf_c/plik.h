//definicje funkcji z plik.c ORAZ struktura naglowka pliku binarnego

#include <stdio.h>
#include "macierz.h"
#include <stdbool.h>

Macierz* czytajPlik(char *plik);

int liniaDoTablicy(char *linia, int **tab, int *size);

void wypiszTablice(int *tab, int n);

