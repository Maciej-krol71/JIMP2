//funkcje tworzenia macierzy

#include<stdio.h>
#include "macierz.h"
#include<stdlib.h>

Macierz * stworzMacierz(int n) {
    int i=0;
    Macierz * m = (Macierz*) malloc(sizeof(Macierz));
    if (m != NULL) {
        m->r = n;
        m->c = n;
        m->v = malloc(sizeof(int*) * n);
        for (i=0; i < n; i++) {
                m->v[i] = malloc(sizeof(int) * n);
        }
    } else printf("Blad alokacji pamieci macierzy.");
   

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            m->v[i][j]=0;
        }
        
    }

    return m;
    
}

void wypiszMacierz(Macierz *m) {
	int i=0;
    int j=0;
	printf("[ \n");
	for (i = 0; i < m->r; i++) {
		printf("%d|  ", i);
		for (j = 0; j < m->c; j++) {
			printf("%d ", m->v[i][j]);
		}
		printf("\n");
	}
	printf("]\n");
}

void zwolnijMacierz(Macierz * m) {
    int i=0;
    for (i=0; i < m->r; i++)
        free(m->v[i]);
    free(m->v);
    free(m);
  }
