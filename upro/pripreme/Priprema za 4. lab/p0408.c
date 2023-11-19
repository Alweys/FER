#include <stdio.h>

/*
S tipkovnice učitati cijele brojeve N, M, idxi i idxj. Nije potrebno provjeravati njihovu ispravnost.
Zatim inicijalizirati dvodimenzijsko polje polje veličine N(redaka) x M(stupaca) 
tako da nakon inicijalizacije svaki član polja ima vrijednost 0.

Potom, počevši od člana polje[idxi][idxj] popuniti matricu polje prema sljedećim pravilima:

Ako je vrijednost trenutnog člana polje[idxi][idxj] jednaka 1, popunjavanje matrice je gotovo
Ako je vrijednost trenutnog člana polje[idxi][idxj] jednaka 0, postavite mu vrijednost na 1,
te se pomaknite po retcima za idxi = idxi + i_smjer i po stupcima za idxj = idxj + j_smjer
Ako bi kretanje rezultiralo izlaskom iz matrice 
tj. ako bi idxi = idxi + i_smjer ili idxj = idxj + j_smjer rezultirali izlaskom iz matrice, 
smjer kretanja se onda mijenja na sljedeći način:
Kada stignemo do donjeg ili gornjeg ruba matrice, počinjemo se kretati po retcima u suprotnom smjeru (-i_smjer)
Kada stignemo do desnog ili lijevog ruba matrice, počinjemo se kretati po stupcima u suprotnom smjeru (-j_smjer)
U kutevima matrice je potrebno napraviti obje promjene smjera
Početni smjer kretanja je dijagonalno gore desno (indeks retka pada, a stupca raste):

po retcima i_smjer = 1
po stupcima j_smjer = -1
Na kraju ispišite dobivenu matricu polje nakon popunjavanja te duljinu prijeđenog puta (ukupni broj pomaka).
*/

int main() {
    int N, M, idxi, idxj, i_smjer = 1, j_smjer = -1, duljina = 0;
    printf("Upisite brojeve N, M, idxi i idxj > ");
    scanf("%d %d %d %d", &N, &M, &idxi, &idxj);
    int polje[N][M];

    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            polje[i][j] = 0;

    while(polje[idxi][idxj] == 0) {
        if(i_smjer == -1 && idxi == 0)
            i_smjer *= -1;
        else if(i_smjer == 1 && idxi == N - 1)
            i_smjer *= -1;
        if(j_smjer == 1 && idxj == M - 1)
            j_smjer *= -1;
        else if(j_smjer == -1 && idxj == 0) 
            j_smjer *= -1;
        polje[idxi][idxj] = 1;       
        idxi += i_smjer;
        idxj += j_smjer;
        duljina++;
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++)
            if(j == 0)
                printf("%d", polje[i][j]);
            else
                printf("%2d", polje[i][j]);
        printf("\n");
    }
    printf("Duljina: %d\n", duljina);

    return 0;
}

/*
5 10 2 3

10 3 0 2
*/