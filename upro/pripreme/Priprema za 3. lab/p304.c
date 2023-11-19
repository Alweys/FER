#include <stdio.h>

/*
S tipkovnice učitati cijeli broj n koji predstavlja broj elemenata u polju. 
Nakon toga učitati n cijelih brojeva u polje. 
Svaki od elemenata zamijeniti zbrojem tog elementa i elemenata većih indeksa od trenutnog. 
Nakon izračuna ispisati dobiveno polje.
*/

int main() {
    int n;
    printf("Unesite duljinu polja: ");
    scanf("%d", &n);

    int polje[n];
    printf("Unesite elemente polja:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &polje[i]);
    
    printf("Izracunato polje: ");
    for(int i = 0; i < n; i++) {
        int zbroj = 0;
        for(int j = i; j < n; j++)
            zbroj += polje[j];
        printf("%d ", zbroj);
    }
    return 0;
}

/*
5 4 1 9 8 8
*/