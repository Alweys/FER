#include <stdio.h>

/*
S tipkovnice učitati vrijednosti za broj redaka m i broj stupaca n dvodimenzijskog cjelobrojnog polja. 
Ako vrijednosti m i n nisu jednake, prekinuti s izvršavanjem programa i ispisati odgovarajuću poruku.

Po retcima učitati prirodne brojeve kao vrijednosti članova polja od m redaka i n stupaca. 
Nakon što su sve vrijednosti upisane, napisati program koji ispisuje razliku zbroja kvadrata glavne dijagonale 
i sporedne dijagonale polja.
*/

int main() {
    int m, n, zbroj[2] = { 0 };

    printf("Unesi dimenzije: ");
    scanf("%d %d", &m, &n);
    if(m != n) {
        printf("Dimenzije ne odgovaraju kvadratnoj matrici!\n");
        return 0;
    }
    int polje[m][n];
    printf("Unesi clanove polja:\n");
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &polje[i][j]);

    printf("Odabrana je matrica: \n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            printf(" %d", polje[i][j]);
        printf("\n");
    }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) {
            if(i == j)
                zbroj[0] += polje[i][j] * polje[i][j];
            if((i + j) == (n - 1))
                zbroj[1] += polje[i][j] * polje[i][j];
        }

    printf("Razlika zbrojeva je %d.\n", zbroj[0] - zbroj[1]);

    return 0;
}

/*
3 3 
1 2 3
4 5 6
7 8 9

3 3 1 2 3 4 5 6 7 8 9

*/