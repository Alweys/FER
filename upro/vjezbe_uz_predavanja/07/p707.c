#include <stdio.h>

/*
Učitavati cijele brojeve iz zatvorenog intervala [1, 20000] dok god se ne upiše broj izvan tog
intervala. Prebrojati koliko je upisano brojeva iz intervala [1, 100], koliko iz intervala [101, 200],
koliko iz intervala [201, 300], ..., koliko iz intervala [19901, 20000]. Pronaći i ispisati interval u
kojem ima najviše upisanih brojeva. Ako ima više intervala u kojima ima jednak broj (najveći)
upisanih brojeva, ispisati sve takve intervale.

Upisite brojeve [1, 20000] > 1501 107 115 1521 55 11 19054 1545 199 0
[101, 200]: 3
[1501, 1600]: 3
*/

#define MIN_BROJ 1
#define MAX_BROJ 20000

int main() {
    int upis, najveci = 0, brojevi[MAX_BROJ] = { 0 }; // Deklaracija, svaki element v polju postavis na 0 z { 0 }

    printf("Upisite brojeve [%d, %d] > ", MIN_BROJ, MAX_BROJ); // Unos
    do {
        scanf("%d", &upis);
        if(!(upis >= MIN_BROJ && upis <= MAX_BROJ)) // Ak nije v intervalu breakaj
            break;

        brojevi[upis - (upis % 100)]++; /*  upis - (upis % 100) -> to da prvi element v zadanom intervalu, 
                                            npr. unos = 961, 961 % 100 = 96, 961 - 61 = 900
                                            onda v polju na prvom elementu samo v intervalu povecavas brojac
                                            znaci brojac se povecava na: brojevi[0], brojevi[100], 
                                            brojevi[200], brojevi[300] ... brojevi[19000]
                                        */
    } while (upis >= MIN_BROJ && upis <= MAX_BROJ);

    for(int i = 0; i < MAX_BROJ; i+=100) /* provjeravamo brojeve brojevi[0], brojevi[100], 
                                            brojevi[200], brojevi[300] ... brojevi[19000]
                                            zato pocnemo z 0 i povecavamo i za 100    
                                        */
        if(brojevi[i] > najveci)    // ak je zbroj veci od najveceg, spremi ga kao najveci
            najveci = brojevi[i];

    for(int i = 0; i < MAX_BROJ; i+=100)
        if(brojevi[i] == najveci)   // ispisi samo one de je zbroj == najvecem
            printf("[%d, %d]: %d\n", i+1, i+100, najveci);

    return 0;
}