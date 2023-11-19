#include <stdio.h>

/*
Napisati program koji pronalazi najveću sumu kontinuiranog pod-polja unutar zadanog polja cijelih brojeva 
te ispisuje sumu te sadržaj pronađenog pod-polja.

S tipkovnice treba učitati vrijednosti za veličinu jednodimenzionalnog polja m. 
Ne treba provjeravati jesu li upisane ispravne vrijednosti. 
Potrebno je učitati vrijednosti elemanata polja, 
te ispisati sadržaj pronađenog pod-polja kao i iznos najveće sume pod-polja. 
Pogledati primjere niže za pojašnjenja (nisu primjeri izvršavanja programa):

Polje od 9 članova {8 3 8 -5 4 3 -4 3 5}
ima najveću sumu kada se zbroji  tipovi[SVI]h 9 članova: 25

Polje od 9 članova {8 3 8 -5 4 3 -4 3 -2}
ima najveću sumu kada se zbroji  tipovi[PRVIH] 6 članova: 21

Polje od 12 članova {38 3 -50 100 200 300 400 500 600 700 800 900}
ima najveću sumu kada se zbroje članovi 4..12: 4500

Polje od 4 člana {38 3 -50 100}
ima najveću sumu kada se računa član: 4
*/

enum tipovi {
    SVI = 0,
    PRVIH = 1,
    OD_DO = 2
};

struct tip{
    int id_pocetak;
    int id_kraj;
    int suma;
};

int main() {
    int m, najveca_suma = 0, najveci_tip = 0;
    struct tip tipovi[3];
    printf("Upisite velicinu polja m > ");
    scanf("%d", &m);
    int polje[m];

    printf("Upisite %d clanova polja m > ", m);
    for(int i = 0; i < m; i++)
        scanf("%d", &polje[i]);
    
    for(int i = 0; i < m; i++)
        najveca_suma += polje[i];
    
    tipovi[SVI].suma = najveca_suma;
    najveca_suma = 0;
    for(int i = 0; i < m; i++) {
        int suma = 0, j;
        for(j = 0; j < m - i; j++)
            suma += polje[j];
        if(suma > najveca_suma) {
            najveca_suma = suma;
            tipovi[PRVIH].id_kraj = j;
        }
    }
    tipovi[PRVIH].suma = najveca_suma;

    najveca_suma = 0;
    for(int i = 0; i < m; i++) {
        int suma = 0, j, k;
        for(j = m; j >= i; j--) {
            suma = 0;
            for(k = i; k < j; k++)
                suma += polje[k];
            if(suma > najveca_suma) {
                najveca_suma = suma;
                tipovi[OD_DO].id_pocetak = i;
                tipovi[OD_DO].id_kraj = j;
            }
        }
        
    }
    tipovi[OD_DO].suma  = najveca_suma;

    for(int i = 0; i < 3; i++)
        if(tipovi[i].suma > tipovi[najveci_tip].suma)
            najveci_tip = i;
    printf("Pronadjeno pod-polje:");
    switch(najveci_tip) {
        case SVI: {
            for(int i = 0; i < m; i++)
                printf(" %d", polje[i]);
            printf("\nNajveca suma kontinuiranog pod-polja je: %d", tipovi[SVI].suma);
            break;
        }
        case PRVIH: {
            for(int i = 0; i < tipovi[PRVIH].id_kraj; i++)
                printf(" %d", polje[i]);
            printf("\nNajveca suma kontinuiranog pod-polja je: %d", tipovi[PRVIH].suma);
            break;
        }
        case OD_DO: {
            for(int i = tipovi[OD_DO]. id_pocetak; i < tipovi[OD_DO].id_kraj; i++)
                printf(" %d", polje[i]);
            printf("\nNajveca suma kontinuiranog pod-polja je: %d", tipovi[OD_DO].suma);
            break;
        }
    }
    return 0;
}

/*
9
8 3 8 -5 4 3 -4 3 5

9
8 3 8 -5 4 3 -4 3 -2

12
38 3 -50 100 200 300 400 500 600 700 800 900

4
38 3 -50 100

	
8
-2 -3 4 -1 -2 1 5 -3

Upisite velicinu polja m > 9
Upisite 9 clanova polja m > 8 3 8 -5 4 3 -4 3 5
Pronadjeno pod-polje : 8 3 8 -5 4 3 -4 3 5
Najveca suma kontinuiranog pod-polja je: 25


*/