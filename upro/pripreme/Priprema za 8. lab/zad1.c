/*
Napisati funkciju generirajSlucajniRedak prototipa:

void generirajSlucajniRedak(int n, int *mat)

koja kao parametre prima pokazivač na prvi element dvodimenzijskog polja cijelih brojeva (kvadratna matrica) 
i cijeli broj n koji predstavlja broj redaka kvadratne matrice. 
Funkcija mora prvo slučajno izabrati redak koji će "generirati", 
a zatim taj redak popuniti slučajno izabranim vrijednostima iz intervala [2, 8].

Inicijalna vrijednost generatora pseudoslučajnih brojeva (pozivom funkcije srand) 
se postavlja na pozivajućoj razini (npr. u funkciji main) i nemojte ju ponovno postavljati.

Napomena: Interval pseudoslučajnih brojeva prilagoditi traženom intervalu uz pomoć izraza koji 
koristi operaciju ostatka cjelobrojnog dijeljenja (prikazan na predavanjima).
*/
#include <stdio.h>
#include <stdlib.h>

void generirajSlucajniRedak(int n, int *mat) {
    int (*matrica)[n] = (void*)mat, i, j, random = rand() % n;
    
    for(i = 0; i < n; i++) {
        if(i != random) continue;
        for(j = 0; j < n; j++)
            matrica[i][j] = rand() % (8 - 2 + 1) + 2;
    }
}

#define RAND_UPPER_BOUND 8
#define RAND_LOWER_BOUND 2

void print_mat(int n, int mat[n][n]) {
   for(int i=0; i < n; i++) {
      for(int j=0; j < n; j++){
         printf("%d ", mat[i][j]);
      }
      printf("\n");
   }
}


int compare_2d_arrays(int n, int mat1[n][n], int mat2[n][n]) {
   for(int i=0; i < n; i++) {
      for(int j=0; j < n; j++){
         if (mat1[i][j] != mat2[i][j]) {
            return 1;
         }
      }
   }


   return 0;
}


int main(void) {
   int seed;
   scanf("%d", &seed);


   int my_mat[6][6] = {0};
   int expected_mat[6][6] = {0};


   srand(seed);
   generirajSlucajniRedak(6, &my_mat[0][0]);
   srand(seed);
   //generirajSlucajniREDAK(6, &expected_mat[0][0]);


   printf("Vas rezultat:\n");
   print_mat(6, my_mat);
   printf("------------------------\n");
   printf("Ocekivani rezultat:\n");
   print_mat(6, expected_mat);


   printf("------------------------\n");


   printf("Jednaki:");
   if (compare_2d_arrays(6, my_mat, expected_mat) == 0) {
      printf("DA");
   } else {
      printf("NE");
   }


   return 0;
}