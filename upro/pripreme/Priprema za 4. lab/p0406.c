#include <stdio.h>

/*
S tipkovnice je potrebno učitati niz znakova (string) niz. 
Niz neće biti dulji od 50 znakova te ga ne treba provjeravati.

Potrebno je ispisati koji se znak najčešće pojavljuje u nizu niz te koliko se puta ponovio taj znak.

Znak "A" se ponavlja 5 puta.

Ukoliko postoji više znakova koji se ponavljaju jednako puta, tada je potrebno ispisati sve znakove, 
te njihov broj ponavljanja. 
Ispis znakova treba biti takav da se prvo ispisuje onaj znak koji ima najmanju vrijednost u ASCII tablici 
pa nakon njega znak sa sljedećom najmanjom vrijednosti i tako dalje.

Znakovi "A", "C", "a" se ponavljaju 3 puta.

Ako je na kraju niza učitana oznaka za novi red, potrebno ju je izbaciti.
*/

#define MAX 50
#define ASCII_MAX 256

int main() {
    char polje[MAX], znakovi[ASCII_MAX] = { 0 };
    int najveci = 0, brNajvecih = 0;
    _Bool prvi = 0;
    
    printf("Unesite niz > ");
    fgets(polje, MAX, stdin);

    for(int i = 0; polje[i] != '\0'; i++)
        znakovi[(int)polje[i]]++;

    for(int i = 0; i < ASCII_MAX; i++) {
        if(znakovi[i] == 0)
            continue;
        if(znakovi[i] > znakovi[najveci])
            najveci = i;
        else if(znakovi[i] == znakovi[najveci])
            brNajvecih++;
    }

    if(brNajvecih >= 1)
        printf("Znakovi");
    else
        printf("Znak");

    for(int i = 0; i < ASCII_MAX; i++) {
        if(znakovi[i] == 0 || znakovi[i] < znakovi[najveci])
            continue;
        
        if(brNajvecih >= 1) {
            if(!prvi) {
                printf(" \"%c\"", (char)i);
                prvi = 1;
                continue;
            }
            printf(", \"%c\"", (char)i);
            continue;
        }
        printf(" \"%c\"", (char)i);

    }
    if(brNajvecih >= 1) {
        printf(" se ponavljaju %d puta.\n", znakovi[najveci]);
        return 0;
    }

    printf(" se ponavlja %d puta.\n", znakovi[najveci]);

    return 0;
}

/*
aaaaAA

Ovojetest

Znak aaa se ponavlja 6 puta.

...........---..-----qqqqwwwwwwwwwwwwwwww...\n

    asdasdasdasd

Priprema-za-4.-labos
*/