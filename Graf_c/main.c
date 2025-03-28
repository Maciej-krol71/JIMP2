//inicjalizacja dzialania programu wywolania funkcji

//main()

//wczytanie pliku i parametrow wywolania

//stworzenie macierzy i wypelnienie

#include<stdio.h>
#include "macierz.h"
#include "plik.h"

int main(){
    char*plik="graf.csrrg";
    Macierz*m=czytajPlik(plik);
    wypiszMacierz(m);
}

//funkcja tworzenia struktury podgrafow

//petla for
//wypelnienie struktury podgrafow wierzcholkami w permutacjach
//if (sprawdzenie czy wierzcholki sie lacza)
//  if (sprawdzenie parametrow)
//      akceptacja wynikow i zapis do pliku
