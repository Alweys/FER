/*
Deklarirana je struktura

struct person_s {
  int code;
  char name[128];
  float salary;
};

Napisati funkciju s prototipom

bool capitalizeName(struct person_s *person)
koja sve riječi unesene u član name promijeni tako da počinju velikim slovom, 
a ostatak riječi pretvara u mala slova. Ako je name prazan niz, funkcija vraća false, inače true.

Osim slova, u name se mogu pojaviti samo još znakovi ' ' (space) i '-' (minus).

Primjeri:

Niz "pero peric" mijenja se u "Pero Peric", a rezultat funkcije je true

Niz "ana ANIC ivic" mijenja se u "Ana Anic Ivic", a rezultat funkcije je true

Niz "ana ivic-anic" mijenja se u "Ana Ivic-Anic", a rezultat funkcije je true

Prazan niz "" ostaje "", a rezultat funkcije je false

Napomena: ne treba predati glavni program, deklaraciju strukture niti naredbe #include, 
potrebno je predati samo funkciju.
*/
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

struct person_s {
  int code;
  char name[128];
  float salary;
};

bool maloSlovo(char znak) {
    return znak >= 'a' && znak <= 'z' ? true : false;
}

bool velikoSlovo(char znak) {
    return znak >= 'A' && znak <= 'Z' ? true : false;
}

char pretvoriSlovo(char znak, int opcija) {
    if(opcija == 0)
        return znak + ('A' - 'a');
    return znak - ('A' - 'a');
}

bool capitalizeName(struct person_s *person) {
    if(strcmp(person->name, "") == 0) return false;
    int i;
    for(i = 0; person->name[i] != '\0'; i++) {
        char* slovo = &person->name[i];
        if(velikoSlovo(*slovo))
            *slovo = pretvoriSlovo(*slovo, 1);
    }

    for(i = 0; person->name[i] != '\0'; i++) {
        char* slovo = &person->name[i];
        if(i == 0 && maloSlovo(*slovo))
            *slovo = pretvoriSlovo(*slovo, 0);
        else if((*(slovo - 1) == ' ' || *(slovo - 1) == '-') && maloSlovo(*slovo))
            *slovo = pretvoriSlovo(*slovo, 0);
    }

    return true;
}

int main(void) {
    struct person_s s;
    printf("Unesite ime > ");
    fgets(s.name, 128, stdin);
    char *p;
    if (p = strchr(s.name, '\n')) *p = '\n';

    capitalizeName(&s);

    printf("ime: %s\n", s.name);
    // ovdje ugraditi poziv funkcije i kontrolni ispis rezultata
    return 0;
}