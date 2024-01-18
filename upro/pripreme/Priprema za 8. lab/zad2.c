/*

Napišite funkciju nadiNajveciOpseg prototipa
void nadiNajveciOpseg(int n, struct pravokutnik* pravokutnici)

Parametar n predstavlja broj elemenata u polju pravokutnici. 
Vaša funkcija treba od danih pravokutnika odrediti onaj s najvećim opsegom i 
treba vratiti rezultat preko eksterne statičke varijable pod nazivom rjesenje 
(ova varijabla je već definirana tako da ju ne morate vi definirati). 
Navedna statička varijabla je u kodu definirana ovako:

struct pravokutnik rjesenje;

U slučaju da više pravokutnika ima maksimalan opseg, 
odaberite onaj koji se u polju pojavljuje ranije (onaj koji ima manji indeks).

Također deklarirajte i strukturu pravokutnik koja definira pravokutnik u 
kartezijevom koordinatnom sustavu preko dvije nasuprotne (nesusjedne) točke pravokutnika 
(pretpostavlja se da su stranice pravokutnika paralelne s x i y osi). Struktura treba imati sljedeće članove:

x1: x koordinata prve točke
y1: y koordinata prve točke
x2: x koordinata druge točke
y2: y koordinata druge točke
Primjer izvođenja:

Pravokutnik 1: (0, 0) - (1, 1)
Pravokutnik 2: (16, 15) - (0, 1)
Pravokutnik 3: (-1, -2) - (0, 1)

Maksimalan opseg:
(16, 15) - (0, 1)
*/

#include <stdio.h>
#include <string.h>

int abs(int broj) {
    return broj < 0 ? broj * -1 : broj;
}

struct pravokutnik {
    int x1, y1, x2, y2;
};

int vratiOpseg(int x1, int y1, int x2, int y2) {
    return 2 * abs(x2 - x1) + 2 * abs(y2 - y1);
}

void nadiNajveciOpseg(int n, struct pravokutnik* pravokutnici) {
    struct pravokutnik najveci = *pravokutnici;
    rjesenje = najveci;
    int i, najveciOpseg = vratiOpseg(najveci.x1, najveci.y1, najveci.x2, najveci.y2);
    for(i = 0; i < n; i++) {
        struct pravokutnik trenutni = *(pravokutnici + i);
        int opseg = vratiOpseg(trenutni.x1, trenutni.y1, trenutni.x2, trenutni.y2);
        if(opseg > najveciOpseg) {
            najveciOpseg = opseg;
            rjesenje = trenutni;
        }
    }
}