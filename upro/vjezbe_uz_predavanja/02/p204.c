#include <stdio.h>
#include <math.h>

/*Napisati program koji će s tipkovnice učitati peteroznamenkasti pozitivni cijeli broj. Nije potrebno
provjeravati je li upisan ispravan broj. Ispisati prvu, treću i petu znamenku učitanog broja*/

int main() {
    int broj;
    printf("Upisite 5-znamenkasti cijeli broj > ");
    scanf("%d", &broj);
    printf("%d %d %d", (broj/(int)pow(10, 4))%10, (broj/(int)pow(10, 2))%10, (broj/(int)pow(10, 0))%10 );
}