#include <stdio.h>
#include <math.h>

void stddev(float *a, int n, float *std) {
    int i, suma = 0;
    float mean, tmp = 0;
    for(i = 0; i < n; i++) suma += a[i];
    mean = suma / (float)n;

    for(i = 0; i < n; i++) tmp += (a[i] - mean) * (a[i] - mean);
    *std = sqrt(tmp / (float)n);
}

int IndexOfMaxdev(float *a, int n, int m) {
    float (*matrica)[m] = (void*)a, temp = 0, najveci = 0;
    int i, imin = 0;
    for(i = 0; i < n; i++) {
        stddev(matrica[i], m, &temp);
        if(temp > najveci) {
            najveci = temp;
            imin = i;
        }
    }

    return imin;
}