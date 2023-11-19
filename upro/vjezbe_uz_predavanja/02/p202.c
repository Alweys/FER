#include <stdio.h>

/*Napisati program koji će s tipkovnice učitati stanje bankovnog računa izraženo u lipama. Nije
potrebno provjeravati je li upisan ispravan broj. Ispisati stanje bankovnog računa izraženo u broju
kuna i broju lipa. */

int main() {
    int lipe;
    printf("Upisite stanje racuna u lipama > ");
    scanf("%d", &lipe);
    printf("Kuna: %d Lipa: %d\n", lipe/100, lipe%100);
}