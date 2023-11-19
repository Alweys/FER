#include <stdio.h>
#include <math.h>
/*Napisati program koji će s tipkovnice učitati realni broj veći od nule koji predstavlja radijus kugle.
Ako je radijus ispravno upisan, ispisati radijus i volumen kugle. Inače, ispisati poruku Neispravan
radijus kugle.*/

int main() {
    float radijus;

    printf("Upisite radijus kugle > ");
    scanf("%f", &radijus);
    if(radijus < 0) {
        printf("Neispravan radijus kugle");
        return 0;
    }

    printf("Volumen kugle radijusa %.3f je %.3f", radijus, ((4/3.f)*pow(radijus, 3)*M_PI));
}