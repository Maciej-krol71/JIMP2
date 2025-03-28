//funcja czytajaca plik csrrg


#include<stdio.h>
#include "macierz.h"
#include "plik.h"
#include<stdlib.h>
#include<string.h>

Macierz * czytajPlik(char *plik){
    
    int size = 1; //initial size
    //tab dla linii nr 2
    int *t = malloc(size * sizeof(int));
    int dlg=0;

    //tab dla linii nr 4 i 5
    int *t1 = NULL;
    int *t2 =NULL;
    int dlg1=0;
    int dlg2=0;

    if (!t) {
        printf("Blad alokacji pamieci\n");
        return NULL;
    }

    Macierz*m=NULL;
    FILE*in=fopen(plik, "r");


    if(in!=NULL){
        
        int licznik=0;
        char buffer[1000000];
        while (fgets(buffer, sizeof(buffer), in) != NULL) {
            licznik++;
            if (licznik == 2) { //zliczamy ilosc wierzcholkow, zeby utworzyc adjacency matrix 
                dlg = liniaDoTablicy(buffer, &t, &size);
                m = stworzMacierz(dlg);
            } else if (licznik == 4) {
                t1 = malloc(size * sizeof(int));
                dlg1 = liniaDoTablicy(buffer, &t1, &size);
            } else if (licznik == 5) {
                t2 = malloc(size * sizeof(int));
                dlg2 = liniaDoTablicy(buffer, &t2, &size);
            }
        }
        
    } else {
        printf("Blad otwarcia pliku");
        return NULL;
    }
    
    fclose(in);
    
    
    int i;
    for(i=0; i<dlg2-1; i++){ 

        int p=i+1;
        
        for (int k = t2[i]; k < t2[p]; k++)
        {
            m->v[t1[t2[i]]][t1[k]]=1;
            m->v[t1[k]][t1[t2[i]]]=1;
        }
        
    }
    
    //ostatni wierzch, bo wyzsza petla konczy sie na i-1; a plik ma i pozycji
    for (int j = t2[i]; j < dlg1; j++)
    {
        m->v[t1[t2[i]]][t1[j]]=1;
        m->v[t1[j]][t1[t2[i]]]=1;
    }
    
    for (int r = 0; r < dlg; r++) //ustawiamy przekatna na 0
    {
       m->v[r][r]=0;

    }

    free(t);
    free(t1);
    free(t2);

    return m;
}


int liniaDoTablicy(char *linia, int **tab, int *size) {
    //za pomoca funckji strtok() do rozdzielenia liczb
    char *token;
    int n = 0;
    token = strtok(linia, ";");
    while (token != NULL) {
        if (n >= *size) {
            *size *= 2;
            *tab = realloc(*tab, *size * sizeof(int));
            if (!*tab) {
                printf("Blad alokacji pamieci\n");
                exit(1);
            }
        }
        (*tab)[n++] = atoi(token);
        token = strtok(NULL, ";");
    }
    return n;
}

void wypiszTablice(int *tab, int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ", tab[i]);
    }
    printf("%c", '\n');
}



//funkcja zwracajaca plik csrrg

//funkcja zwracajaca plik binarny
/*uzycie funkcji fwrite oraz fopen w trybie "wb" 
optymalizacja pliku do jak najmniejszego rozmiaru kolejnosc danych (double int char); */
