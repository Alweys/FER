#include <stdio.h>

/*
Napišite program koji će učitati prirodni broj n iz intervala [1, 10]. 
Broj n predstavlja dimenzije kvadratne matricu (n x n). 
Nadalje, program treba učitati vrijednosti matrice po retcima.

Za svaki stupac, potrebno je ispisati razliku suma trenutnog stupca i sljedećeg stupca. 
Od sume zadnjeg stupca potrebno je oduzeti sumu prvog stupca.

Nije potrebno provjeravati ispravnost unesenih vrijednosti.

Napomena: dvodimenzijsko polje definirati tako da se za njegovu pohranu troši minimalni potreban prostor.*/

int main() {
    int n;
    printf("Unesite n > ");
    scanf("%d", &n);
    int polje[n][n];
    int suma[n];
    for(int i = 0; i < n; i++)
        suma[i] = 0;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &polje[i][j]);

    for(int j = 0; j < n; j++)
        for(int i = 0; i < n; i++)
            suma[j] += polje[i][j] - polje[i][(j+1)%(n)];

    printf("Rezultat > ");
    for(int i = 0; i < n; i++)
        if(i == n-1)
            printf("%d\n", suma[i]);
        else
            printf("%d ", suma[i]);
    
    return 0;
}

/*
3
0 1 2
1 2 3
2 3 4

*/