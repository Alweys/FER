#include <stdio.h>

/*
S tipkovnice učitati niz znakova (string) koji sigurno neće biti dulji od 150 znakova.
Niz može sadržavati bilo koji znak ASCII tablice koji se može tiskati (pozicije 32-126).
Treba napisati program koji će ukloniti sve znakove koji su uneseni, a koji nisu dio engleske abecede. 
Ukoliko ulazni string ne sadrži niti jedan znak engleskog alfabeta treba ispisati tekst prazan string.
*/

#define MAX 150

int main() {
    char polje[MAX];
    _Bool prazan = 1;
    printf("Upisite znakovni niz > ");
    fgets(polje, MAX, stdin);

    printf("Izlazni znakovni niz je : ");
    for(int i = 0; polje[i] != '\0'; i++)
        if((polje[i] >= 'a' && polje[i] <= 'z') || (polje[i] >= 'A' && polje[i] <= 'Z')) {
            prazan = 0;
            printf("%c", polje[i]);
        }
    if(prazan) {
        printf("prazan string\n");
        return 0;
    }

    printf("\n");
    return 0;
}

/*
p2'r-o@gram84iz./

12321[]

Na mladima svijet ostaje!?
*/