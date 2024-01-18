/*
Potrebno je napisati funkciju GenerirajTelefonskiBroj koja za ulazne parametre prima:

pokazivač broj na polje znakova tipa char
U funkciji GenerirajTelefonskiBroj potrebno je zamijeniti slovo x s pseudoslučajno generiranom znamenkom [0-9]. 
Ukoliko polje sadrži neki drugi znak, potrebno je taj znak zamijeniti znakom -.

Inicijalna vrijednost generatora pseudoslučajnih brojeva (pozivom funkcije srand) se 
inicijalizira na pozivajućoj razini (funkciji main) i ne treba je ponovno inicijalizirati.

Primjeri izvođenja funkcije koja koristi pseudoslučajno generirane brojeve:

prva linija prikazuje vrijednost parametra broj koji ulazi u funkciju GenerirajTelefonskiBroj
druga linija prikazuje vrijednost parametra broj na kraju izvođenja funkcije GenerirajTelefonskiBroj
Primjeri izvršavanja programa:

Primjer 1 (seed: 111):

Linux, Edgar:

x-x
1-7
Windows:

x-x
1-4

Primjer 2 (seed: 222):

Linux, Edgar:

xax
0-0
Windows:

xax
3-1
Primjer 3 (seed: 333):

Linux, Edgar:

xxx-xxx-xxxx
695-869-4325
Windows:

xxx-xxx-xxxx
661-888-3561
Važno: Za transformaciju pseudoslučajnog broja u broj iz željenog intervala koristiti operator %, inače nećete dobiti jednak rezultat.

Napomena: Kao rješenje zadatka predaje se samo implementirana funkcija koja ne smije sadržavati naredbe za ispis na standardni izlaz ili unos sa standardnog ulaza. Funkcija main i zaglavlja se ne predaju.
*/

#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  

void GenerirajTelefonskiBroj(char *broj) {
    int i;
    char brojevi[] = {'0','1','2','3','4','5','6','7','8','9'};
    for(i = 0; broj[i] != '\0'; i++) {
        switch(broj[i]) {
            case 'x': {
                broj[i] = brojevi[rand() % (9 - 0 + 1) + 0];
                break;
            }
            default: {
                broj[i] = '-';
                break;
            }
        }
    }
}

#define MAX_BROJ 100

int main()
{
  int seed;
  char broj[MAX_BROJ] = {'\0'};
  scanf("%d %s", &seed, broj);


  srand(seed);
  GenerirajTelefonskiBroj(broj);
  printf("%s", broj);


  return 0;
}