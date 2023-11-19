#include <stdio.h>
#include <stdbool.h>

#define MIN 1
#define MAX 50

int djeljiv3(int x) {
    //printf("%d %d\n", x, );

    if(3 - (x % 3) == 1)
        return x + 1;

    if(3 - (x % 3) == 2)
        return x - 1;

    return x;
}

bool jeLiProst(int x) {
    int brojac = 0;
    for(int i = MIN; i <= x; i++)
        if(x % i == 0 && x != 1)
            brojac++;
    if(brojac == 2)
        return true;
    
    return false;
}

int main() {
    int N, i = MIN, brojac = 0;
    do {
        printf("Upisite N > ");
        scanf("%d", &N);
    } while(!(N >= MIN && N <= MAX));


    while(brojac < N) {
        if(jeLiProst(i)) {
            brojac++;
            printf("%d ", djeljiv3(i));
        }
        i++;
    }

}