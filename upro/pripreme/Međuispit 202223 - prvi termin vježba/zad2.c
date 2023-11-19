#include <stdio.h>

int main() {
    int n, i;
    do {
        printf("Unesite n > ");
        scanf("%d", &n);
    } while(!(n > 0));

    int a[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for(i = 0; i < n; i++) {
        if(n % 2 == 1) {
            if(i == n - 1)
                continue;
        }
        int temp;
        if(i % 2 == 0) {
            temp = a[i];
            a[i] = a[i+1];
            a[i+1] = temp;
        }
    }

    for (i = 0; i < n; i = i + 1) {
        printf("%d ", a[i]);
    }

    return 0;
}

/*
6
1 5 3 9 5 8

5
3 9 8 6 4
*/