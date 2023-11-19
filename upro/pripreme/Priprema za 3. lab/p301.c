#include <stdio.h>

/*
S tipkovnice učitati cijeli broj n koji predstavlja broj redaka i stupaca dvodimenzionalnog polja. 
Po retcima učitati cijele brojeve kao vrijednosti članova polja.
U drugo polje jednakih dimenzija upisati elemente jednake elementima prvog polja rotiranog za 90 stupnjeva 
u smjeru kazaljke na satu. 
Ispisati dobiveno polje.
*/

int main() {
    int n;
    printf("Unesite dimenzije polja: ");
    scanf("%d", &n);
    
    int polje[n][n];
    printf("Unesite elemente polja: \n");
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &polje[i][j]);

    for(int i = 0; i < n; i++)
        for(int j = i; j < n; j++) {
            int temp = polje[i][j];
            polje[i][j] = polje[j][i];
            polje[j][i] = temp;
        }

    printf("Izracunato polje: \n");
    for(int i = 0; i < n; i++) {
        for(int j = n - 1; j >= 0; j--)
            printf("%d ", polje[i][j]);
        printf("\n");
    }
    return 0;
}

/* 
1 2 3
4 5 6
7 8 9
*/