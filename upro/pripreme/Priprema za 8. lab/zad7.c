/*
Izračun dobitnog listića

Potrebno je napisati funkciju za obradu svih odigranih listića (pojednostavljene) igre Loto 6/45 u 
jednom izvlačenju.

Na početku programskog kôda kojeg ćete predati kao rješenje, izvan svih blokova, 
deklarirajte strukturu listic kojoj su članovi definirani na sljedeći način:
serijski_broj - cijeli broj tipa long
odigrana_kombinacija - jednodimenzionalno polje duljine 6 tipa int koje sadrži odigranu kombinaciju na listiću
Pomoću strukture listic, u programskom kôdu kojeg ne morate predati kao rješenje ovog zadatka, bit će definirana 
i inicijalizirana eksterna varijabla dobitni vidljiva u cijelom modulu.

Pomoću polja struktura listic, u programskom kôdu kojeg ne morate predati kao rješenje ovog zadatka, 
bit će definirana i inicijalizirana varijabla igra. 
U ovom polju će se pohraniti svi odigrani listići za jedno izvlačenje igre Loto 6/45. 
Tako definirano polje strukture će se kao parametar (putem pokazivača) predati funkciji za obradu.

Napišite funkciju ObradaIgre čiji prototip je:

void ObradaIgre (struct listic *svi_listici, int N, int *izvuceni_brojevi);

Parametri su definirani na slijedeći način:

prvi parametar je pokazivač na polje strukture listic a koje sadrži sve odigrane listiće
drugi parametar je broj odigranih listića, a
treći parametar je pokazivač na jednodimenzionalno polje izvučenih brojeva u igri.
Funkciju za izvlačenje brojeva IzvlacenjeLota_6_od_45 (koja je rješenje prethodnog zadatka) 
i main nije potrebno predati. Polje nije potrebno sortirati, 
dobitni je onaj listić koji sadrži sve izvučene brojeve u izvučenom redoslijedu. 
Postoji samo jedan dobitni listić.

U obradi je potrebno pronaći dobitni listić (sa svih 6 dobitnih brojeva u tom redoslijedu) 
iz polja ulaznih listića. 
Ako postoji dobitni listić sa izvučenom kombinacijom, 
potrebno je pohraniti vrijednosti serijskog broja i odigranu dobitnu kombinaciju u externu varijablu dobitni 
koju će glavni program iskoristiti za ispis. 
Ukoliko takav listić ne postoji u serijski_broj varijable dobitni treba upisati vrijednost -1. 
U tom slučaju ispisat će se poruka Nije izvucen dobitni 6!!. 
Ukoliko postoji, onda postoji samo jedan dobitni listić u ulaznim podacima.

Primjeri pomoću kojeg možete testirati funkciju:

U donjoj tablici su prikazani svi uplaćeni listići jedne igre (4 listića)

serijski broj	kombinacije
123456	8 35 25 15 30 10
654321	26 6 31 28 42 38
332245	6 15 45 5 25 10
569887	10 29 16 15 31 21
Izvučena kombinacija (sa pozivom parametra izvlačenja 5) je : 
26 6 31 28 42 38 ( na sustavu Linux (Edgar) ) te je dobitni listić 654321.

Izvučena kombinacija (sa pozivom parametra izvlačenja 5) je : 
26 6 31 28 42 38 ( na sustavu Windows ) te je dobitni listić 569887.

U donjoj tablici su prikazani svi uplaćeni listići druge igre (5 listića) na sustavu

serijski broj	kombinacije
58	12 44 35 22 8 3
98	11 5 9 4 3 2
99	1 2 3 4 5 6
100	6 5 4 3 2 1
101	3 8 45 14 7 18
Izvučena kombinacija (sa pozivom parametra izvlačenja 8) je : 
32 10 13 45 37 29 ( na sustavu Linux (Edgar) ) odnosno 20 1 42 9 6 4 ( na sustavu Windows ) 
te nema dobitnog listića u ovoj igri.
*/

#include <stdio.h>
#include <stdlib.h>

struct listic {
    long serijski_broj;
    int odigrana_kombinacija[6];
};

struct listic dobitni;

void IzvlacenjeLota_6_od_45(int* kombinacija) {
    for(int i = 0; i < 6; i++) {
        kombinacija[i] = rand() % (45 - 1 + 1) + 1;
    }
}

void ObradaIgre (struct listic *svi_listici, int N, int *izvuceni_brojevi) {
    int i, j;
    dobitni.serijski_broj = -1;
    for(i = 0; i < N; i++) {
        int dobitan = 1;
        for(j = 0; j < 6; j++) {
            if(svi_listici[i].odigrana_kombinacija[j] != izvuceni_brojevi[j]) {
                dobitan = 0;
                break;
            }
        }
        if(dobitan) {
            dobitni.serijski_broj = svi_listici[i].serijski_broj;
            for(j = 0; j < 6; j++)
                dobitni.odigrana_kombinacija[j] = svi_listici[i].odigrana_kombinacija[j];
            break;
        }
    }
}


int main() {
    int n=0;
    //incijalizacija varijabli
    dobitni.serijski_broj = 0;
    for (int b = 0; b < 6; b++)
        dobitni.odigrana_kombinacija[b] = 0;
    struct listic igra[100];

    scanf("%d", &n); //učitaj broj listića u igri
    for (int z = 0; z < 100; z++)
    {
        igra[z].serijski_broj = 0;
        igra[z].odigrana_kombinacija[0] = 0;
        igra[z].odigrana_kombinacija[1] = 0;
        igra[z].odigrana_kombinacija[2] = 0;
        igra[z].odigrana_kombinacija[3] = 0;
        igra[z].odigrana_kombinacija[4] = 0;
        igra[z].odigrana_kombinacija[5] = 0;
    }
        
    for (int k = 0; k < n; k++)
    {
        
        scanf("%ld %d %d %d %d %d %d", &igra[k].serijski_broj, &igra[k].odigrana_kombinacija[0],
            &igra[k].odigrana_kombinacija[1], &igra[k].odigrana_kombinacija[2], &igra[k].odigrana_kombinacija[3],
            &igra[k].odigrana_kombinacija[4], &igra[k].odigrana_kombinacija[5]);        
    }
        

    //izvlačenje
    int izvucenakombinacija[6], seed=0;
    scanf("%d", &seed);
    srand(seed);
    IzvlacenjeLota_6_od_45(izvucenakombinacija);

   

    ObradaIgre(igra, n, izvucenakombinacija);

    if (dobitni.serijski_broj != -1) {
        printf("serijski broj dobitnog listica je: %ld\n", dobitni.serijski_broj);
        printf("dobitna kombinacija je:");
            for (int j = 0; j < 6; j++)
                printf(" %d", dobitni.odigrana_kombinacija[j]);
    }
    else
            printf("Nije izvucen dobitni 6!!\n");   
}

/*

4
123456 8 35 25 15 30 10
654321 26 6 31 28 42 38
332245 6 15 45 5 25 10
569887 10 29 16 15 31 21
5
*/