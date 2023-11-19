#include <stdio.h>
#define D_GR 1972 // donja granica intervala
#define G_GR 2013 // gornja granica intervala
int main(void) {
   int broj;
   //XXXXXXXXXXXXXXXXXXXXXXXXXX
   int brojac[G_GR - D_GR + 1] = { 0 };
   /* ucitavanje brojeva i inkrementiranje odgovarajucih brojaca */
   do {
      printf("Upisite broj u intervalu [%d, %d] > ", D_GR, G_GR);
      scanf("%d", &broj);
      if (broj >= D_GR && broj <= G_GR) {
         brojac[broj - D_GR] = brojac[broj - D_GR] + 1;
      }
   } while (broj >= D_GR && broj <= G_GR); 
   printf("\n");
   /* ispis sadrzaja onih brojaca koji su veci od nule */
   int i;
   for (i = D_GR; i <= G_GR; i = i + 1) {
      if (brojac[i - D_GR] > 0) {
         printf("Broj %d se pojavio %d puta\n", i, brojac[i - D_GR]);
      }
    }
    return 0;
}