#include <stdio.h>

int main() {
    int m, br = 0;
    printf("Unesite m > ");
    scanf("%d", &m);
    int polje[m][m], dijag[m];
    for(int i = 0; i < m; i++)
        for(int j = 0; j < m; j++)
            scanf("%d", &polje[i][j]);

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < m; j++) {
            if(i == j) {
                dijag[br] = polje[i][j];
                br++;
            }
        }
    }
    for(int i = 0; i < m; i++) {
        for(int j = i; j < m - 1 - i; j++) {
            if(dijag[j] >= dijag[j+1]) {
                int temp = dijag[j];
                dijag[j] = dijag[j+1];
                dijag[j+1] = temp;
            }
        }
    }
    br = 0;
    printf("Ispis:\n");
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < m; j++) {
            if(i == j) {
                polje[i][j] = dijag[br];
                br++;
            }
            printf("%4d", polje[i][j]);
        }
        printf("\n");
    }
    

    return 0;
}

/*
3
3 -1 4
5 -3 -2
2 1 -1
*/