#include <stdio.h>

int dot_produkt (int *a, int *b, int n) {
    int suma = 0;
    for(int i = 0; i < n; i++) suma += a[i] * b[i];
    return suma;
}

void mat_vec_produkt(int *X, int *a, int n, int *ret) {
    int (*matrica)[n] = (void*)X;
    for(int i = 0; i < n; i++)
        ret[i] = dot_produkt(a, matrica[i], n);
}