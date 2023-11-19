#include <stdio.h>

/*
Napišite program koji s tipkovnice učitava prirodni broj N (broj članova polja) 
te učitava polje od N prirodnih brojeva. 
Zatim s tipkovnice učitati novi prirodni broj te indeks na koji će biti dodan u postojeće polje. 
Ostali članovi polja se u odnosu na umetnutog člana pomiču udesno, a zadnji član će izaći "izvan" polja. 
Program treba ispisati početno te novodobiveno polje.

Unesene vrijednosti nije potrebno provjeravati. 
Pretpostaviti da će uvijek biti odabran indeks unutar dimenzija odabranog polja.
*/

int main() {
    int n, index, vrijednost;

    printf("Unesite broj clanova polja:");
    scanf("%d", &n);
    int polje[n];
    printf("Unesite clanove polja (%d):\n", n);
    for(int i = 0; i < n; i++)
        scanf("%d", &polje[i]);

    printf("Unesite vrijednost novog clana te indeks:\n");
    scanf("%d %d", &vrijednost, &index);

    printf("Pocetno polje\n");
    for(int i = 0; i < n; i++)
        printf("%d ", polje[i]);

    int ispisano = 0;
    printf("\nNovodobiveno polje\n");
    for(int i = 0; i < n; i++) {
        if(i < index)
            printf("%d ", polje[i]);
        else {
            if(!ispisano) {
                printf("%d ", vrijednost);
                ispisano = 1;
                n--;
                i--;
            }
            else {
                printf("%d ", polje[i]);
            }    
        }
    }
    return 0;
}

//10 3 12 27 83 2 54 3 21 105 8 1000 4