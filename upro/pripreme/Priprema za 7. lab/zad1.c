#include <stdio.h>

void obrni (char *src, char *dst) {
    int i, cnt = 0, k = 0;
    for(cnt = 0; src[cnt] != '\0'; cnt++);
    for(i = cnt - 1; i >= 0; i--) {
        dst[k] = src[i];
        k++;
    }
    dst[cnt] = '\0';
}

int main() {
    char arr[128] = { 0 };
    char* dst = &arr[0];
    obrni("asdf", dst);
    printf("%s\n", dst);
    return 0;
}