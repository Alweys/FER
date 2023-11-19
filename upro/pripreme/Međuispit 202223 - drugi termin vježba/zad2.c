#include <stdio.h>

int main() {
    int i, n;
    do {
        printf("Unesite n: ");
        scanf("%d", &n);
    } while(n < 1);
    int polje[n], par[n], nep[n], brP = 0, brNep = 0;

    printf("Unesite clanove polja: ");
    for (i = 0; i < n; i++)
        scanf("%d", &polje[i]);

    for(int i = 0; i < n; i++) {
        if(polje[i] % 2 == 0) {
            par[brP] = polje[i];
            brP++;
        }
        else {
            nep[brNep] = polje[i];
            brNep++;
        }
    }
    for(int i = 0; i < n; i++) {
        if(i < brNep) {
            polje[i] = nep[i];
        }
        else {
            polje[i] = par[i - brNep];
        }
    }

    printf("Modificirano polje: ");
    for (i = 0; i < n; i = i + 1) {
      printf("%d ", polje[i]);
    }
    return 0;

}