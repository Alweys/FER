#include <stdio.h>

void transponiraj(int* src, int* dst, int n, int m) {
    int (*source)[m] = (void*)src;
    int (*dest)[n] = (void*)dst;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            dest[j][i] = source[i][j];
}

int main() {
    int polje[3][3] = { 0, 1, 2, 3, 4, 5, 6, 7, 8};
    int polje2[3][3];

    transponiraj(&polje[0][0], &polje2[0][0], 3, 3);

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            printf("%5d", polje2[i][j]);
        }
        printf("\n");
    }
}