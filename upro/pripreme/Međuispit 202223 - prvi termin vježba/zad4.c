#include <stdio.h>

#define MAX 30
#define MAX_ASCII 128

int main() {
    char ulaz[MAX + 1], izlaz[MAX + 1];
    int znakovi[MAX_ASCII] = { 0 }, brojac = 0;
    printf("Upisite ulazni niz > ");
    fgets(ulaz, MAX + 1, stdin);

    for(int i = 0; ulaz[i] != '\0'; i++) {
        if(ulaz[i] >= 'a' && ulaz[i] <= 'z') {
            if(znakovi[(int)ulaz[i]] == 0) {
                izlaz[brojac] = ulaz[i];
                znakovi[(int)ulaz[i]]++;
                brojac++;
            }
        }
    }
    izlaz[brojac] = '\0';

    printf("Izlaz: %s\n", izlaz);
    printf(" Ulaz: %s", ulaz);
    return 0;
}

/*
bbBaacc egf !1234567890 NNmmm
*/