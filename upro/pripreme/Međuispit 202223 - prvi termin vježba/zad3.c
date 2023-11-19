#include <stdio.h>

int main() {
    int m, n;

    printf("Unesite m > ");
    scanf("%d", &m);

    printf("Unesite n > ");
    scanf("%d", &n);

    int polje[m][n], parovi[m];
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &polje[i][j]);
        }
        parovi[i] = 0;
    }

    int udaljenost;
    printf("Unesite trazenu udaljenost > ");
    scanf("%d", &udaljenost);

    for(int i = 0; i < m; i++) {
        for(int j = 1; j < n; j++) {
            //printf("%d - %d = %d\n", polje[i][j], polje[i][j-1], polje[i][j] - polje[i][j - 1]);
            if(polje[i][j] - polje[i][j - 1] == udaljenost) {
                parovi[i]++;
            }
        }
    }

    for(int i = 0; i < m; i++) {
        printf("%d. redak, parova: %d\n", i+1, parovi[i]);
    }
}

/*
1
4
1 2 3 4
1
*/