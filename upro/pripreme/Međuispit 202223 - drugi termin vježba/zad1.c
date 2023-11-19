#include <stdio.h>

int main() {
    int n;
    double suma = 0.0f;
    printf("Unesite n > ");
    scanf("%d", &n);

    if(n < 2) {
        printf("Neispravan n");
        return 0;
    }

    for(int i = 1; i <= n; i++) {
        long double sumaTi = 0.0f;
        for(int j = 1; j <= i; j++) {
            sumaTi += (double)j;
        }
        
        suma += (1.0f / (sumaTi*1.0f));

    }
    printf("%.9f", suma);

    return 0;
}