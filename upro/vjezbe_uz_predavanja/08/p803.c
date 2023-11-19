#include <stdio.h>

/*
Učitati vrijednosti za broj redaka m i broj stupaca n dvodimenzijskog cjelobrojnog polja. Ne treba
provjeravati jesu li upisane ispravne vrijednosti. Po retcima učitati vrijednosti članova
dvodimenzijskog cjelobrojnog polja od m redaka i n stupaca. Nakon što su sve vrijednosti
upisane, pronaći i ispisati indekse najmanjih članova u svakom stupcu.

Primjer izvršavanja programa:

Upisite m, n > 4 5
Upisite 4 x 5 clanova >
1 2 7 4 2
4 3 2 1 3
1 3 2 1 1
4 0 2 0 2
1. stupac: (0, 0), (2, 0)
2. stupac: (3, 1)
3. stupac: (1, 2), (2, 2), (3, 2)
4. stupac: (3, 3)
5. stupac: (2, 4)
*/

int main() {
    int m, n;

    printf("Upisite m, n > ");
    scanf("%d %d", &m, &n);

    int polje[m][n], najmanji[n];
    printf("Upisite %d x %d clanova > ", m, n);
    for(int i = 0; i < m; i++)          // Standardni unos
        for(int j = 0; j < n; j++)
            scanf("%d", &polje[i][j]);

    for(int j = 0; j < n; j++) {    // Obrnuta for petlja, prvo idemo ve po stupcima pa onda po redkima
        najmanji[j] = polje[0][j];
        for(int i = 0; i < m; i++)
            if(polje[i][j] <= najmanji[j])  /*  Ako je trenutni element v stupcu manji od 
                                                najmanjeg v polju od najmanjih brojeva stupaca, 
                                                postavi ga na kak najmanji*/
                najmanji[j] = polje[i][j];
    }

    for(int j = 0; j < n; j++) {            // Opet ista petlja
        printf("%d. stupac: ", j+1);
        int prvi = 1;
        for(int i = 0; i < m; i++) {
            if(polje[i][j] == najmanji[j])  //  Provjera ak je trenutni element v stupcu jednak najmanjem
                if(prvi) {                  /*  Provjera ak je prvi element, 
                                                radi lepog formatiranja bez zareza v ispisu na pocetku*/
                    printf("(%d, %d)", i, j);
                    prvi = 0;
                }
                else
                    printf(", (%d, %d)", i, j);
        }
        printf("\n");
    }
}