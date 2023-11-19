#include <stdio.h>

/*Napisati program koji će s tipkovnice u varijable z1, z2, z3 i z4 učitati po jednu znamenku
četveroznamenkastog broja m. Nije potrebno provjeravati jesu li upisane ispravne znamenke.
Ispisati učitane znamenke, izračunati i ispisati broj m.*/

int main() {
    int znam, i = 0, broj = 0, pomak = 1000;
    printf("Upisite 4 cijela broja (po jednu znamenku) > ");
    for(i ; i < 4; i++) {
        scanf("%d", &znam);
        printf("z%d = %d\n", i+1, znam);
        broj += pomak * znam;
        pomak /= 10;
    }
    printf("m = %d", broj);
}