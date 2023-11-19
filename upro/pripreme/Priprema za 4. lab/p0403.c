#include <stdio.h>

/* S tipkovnice učitati niz znakova (string) koji sigurno neće biti dulji od 200 znakova.
Niz može sadržavati bilo koji znak ASCII tablice koji se može tiskati (pozicije 32-126).
Odredite i na zaslon ispišite obrnuti niz i pri tome sva mala slova pretvorite u velika.
*/

#define MAX 200

int main() {
    char polje[MAX], duljina = 0;
    printf("Upisite znakovni niz > ");
    fgets(polje, 200, stdin);

    for(int i = 0; polje[i] != '\0'; i++) {
        duljina++;
        if(polje[i] >= 'a' && polje[i] <= 'z')
            polje[i] += ('A' - 'a');
    }

    printf("Obrnuti niz: ");
    for(int i = duljina - 1; i >= 0; i--)
        printf("%c", polje[i]);
    printf("\n");

    return 0;
}

// PrImJer