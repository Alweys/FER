#include <stdio.h>
#define MAX 30

int main() {
    char niz[MAX + 1];
    int imin = 0, imax = 0;
    printf("Upisite niz > ");
    fgets(niz, MAX + 1, stdin);
    for(int i = 0; niz[i] != '\0'; i++){
        if(niz[i] == '\n'){
            niz[i] = '\0';
        }
    }
    for(int i = 0; niz[i] != '\0'; i++) {
        //printf("%2d %2c %2d %2d %2d\n", i, niz[i], (int)niz[i], imin, imax);
        if((int)niz[i] <= (int)niz[imin])
            imin = i;
        if((int)niz[i] > (int)niz[imax])
            imax = i;
    }
    printf("imin = %d, imax = %d\n", imin, imax);

    if(imin > imax) {
        for(int i = imin; i >= imax; i--)
        printf("%c", niz[i]);

        return 0;
    }

    for(int i = imin; i <= imax; i++)
        printf("%c", niz[i]);
    return 0;
}

/*
!123 ABC abc!

!abc 123 ABC!
*/