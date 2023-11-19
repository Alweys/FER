#include <stdio.h>

/*
Napišite program koji će za dvodimenzijsko polje cijelih brojeva s jednakim brojem redaka i stupaca N 
(kvadratnu matricu) izračunati sumu svih brojeva koji se nalaze u zadanom retku i stupcu. 
Element matrice u kojem se zadani redak i stupac "sijeku" zbraja se samo jedanput.

S tipkovnice program treba učitati prirodni broj N. 
Zatim je potrebno s tipkovnice učitati po retcima članove kvadratne matrice. 
Na kraju je potrebno učitati redni broj retka i stupca čije elemente zbrajamo 
(0 je redni broj prvog retka/stupca). 
Nije potrebno provjeravati ispravnost unesenih vrijednosti.
*/

int main() {
    int N, redak, stupac, suma = 0;
    printf("Upisite broj redaka/stupaca matrice > ");
    scanf("%d", &N);
    int polje[N][N];
    printf("Upisite %dx%d clanova > \n", N, N);
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            scanf("%d", &polje[i][j]);
    printf("Upisite redni broj retka > ");
    scanf("%d", &redak);
    printf("Upisite redni broj stupca > ");
    scanf("%d", &stupac);

    for(int j = 0; j < N; j++)
        suma += polje[redak][j];
    for(int i = 0; i < N; i++)
        if(i != redak)
            suma += polje[i][stupac];
    printf("Suma brojeva koji se nalaze u retku %d i stupcu %d je %d.", redak, stupac, suma);
    return 0;
}

/*
3
9 -3 4
5 2 -1
-3 4 5
0
2
*/