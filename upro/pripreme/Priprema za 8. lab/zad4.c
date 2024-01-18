/*
1. Na početku programskog kôda kojeg ćete predati kao rješenje, izvan svih blokova, 
deklarirajte strukturu dionica_s kojoj su članovi definirani na sljedeći način:

oznaka - jedinstvena oznaka dionice tipa char[] koja se sastoji od maksimalno 5 znakova 
(potrebno je koristiti predefinirani makro MAX_OZNAKA)
cijena - broj tipa float
naziv - naziv dionice char[] koji se sastoji maksimalno 20 znakova 
(potrebno je koristiti predefinirani makro MAX_NAZIV)
2. Osim strukture dionica_s, potrebno je definirati strukturu portfelj_s kojoj su 
članovi definirani na sljedeći način:

oznaka - jedinstvena oznaka dionice tipa char[] koja se sastoji od maksimalno 5 znakova 
(potrebno je koristiti predefinirani makro MAX_OZNAKA)
kolicina - cijeli broj tipa int koji predstavlja koliko posjedujemo dionica s oznakom oznaka
3. Potrebno je napisati funkciju IzracunajVrijednostPortfelja čiji je prototip:

float IzracunajVrijednostPortfelja(struct dionica_s *dionice, int broj_dionica, 
struct portfelj_s *moj_portfelj, int broj_dionica_u_mom_portfelju);
funkcija mora vratiti ukupnu vrijednost svih dionica koje se nalaze u strukturi portfelj_s
vrijednost jedne dionice računa se:
umnožak količine dionice koju posjedujemo u portfelju i vrijednosti dionice
ako se u portfelju nalazi dionica koja se ne nalazi u listi svih dionica tada 
vrijednost te dionice ne treba uračunati u vrijednost portfelja
Primjer izvođenja programa:

Broj dionica: 1
MSFT 10.00 Microsoft
Broj dionica u mom portfelju: 1
MSFT 20
Vrijednost portfelja: 200.00
Broj dionica: 3
MSFT 10.00 Microsoft
TSLA 20.00 Tesla
AMZN 30.00 Amazon
Broj dionica u mom portfelju: 2
MSFT 20
AMZN 20
Vrijednost portfelja: 800.00
Broj dionica: 3
MSFT 10.00 Microsoft
TSLA 20.00 Tesla
AMZN 30.00 Amazon
Broj dionica u mom portfelju: 2
GOOGL 20
AAPL 20
Vrijednost portfelja: 0.00
Napomena 1: Glavna funkcija main će na standardni ulaz učitati podatke od dionicama i portfelju.

Napomena 2: Kao rješenje zadatka predaje se samo implementirana funkcija koja ne smije sadržavati naredbe za ispis na standardni izlaz ili unos sa standardnog ulaza. Funkcija main i zaglavlja se ne predaju.
*/

#include <stdio.h>  
#include <string.h> 

#define MAX_DIONICA 100
#define MAX_DIONICA_U_PORTFELJU 20
#define MAX_NAZIV 20
#define MAX_OZNAKA 5

struct dionica_s {
    char oznaka[MAX_OZNAKA];
    float cijena;
    char naziv[MAX_NAZIV];
};

struct portfelj_s 
{
    char oznaka[MAX_OZNAKA];
    int kolicina;
};

float IzracunajVrijednostPortfelja(struct dionica_s *dionice, int broj_dionica, struct portfelj_s *moj_portfelj, int broj_dionica_u_mom_portfelju) {
    float vrijednost = 0;
    int i, j = 0;
    for(i = 0; i < broj_dionica; i++) {
        if(strcmp(dionice[i].oznaka, moj_portfelj[j].oznaka) == 0) {
            vrijednost += dionice[i].cijena * moj_portfelj[j].kolicina;
            j++;
        }
    }

    return vrijednost;
}

int main ()
{
  int broj_dionica;
  printf ("Broj dionica: ");
  scanf ("%d", &broj_dionica);


  struct dionica_s dionice[MAX_DIONICA + 1];
  for (int i = 0; i < broj_dionica; i++)
    {
      scanf ("%s", dionice[i].oznaka);
      scanf ("%f", &dionice[i].cijena);
      scanf ("%s", dionice[i].naziv);
    }


  int broj_dionica_u_mom_portfelju;
  printf ("Broj dionica u mom portfelju: ");
  scanf ("%d", &broj_dionica_u_mom_portfelju);


  struct portfelj_s moj_portfelj[MAX_DIONICA_U_PORTFELJU + 1];
  for (int i = 0; i < broj_dionica_u_mom_portfelju; i++)
    {
      scanf ("%s", moj_portfelj[i].oznaka);
      scanf ("%d", &moj_portfelj[i].kolicina);
    }


  float ukupna_vrijednost = IzracunajVrijednostPortfelja (dionice, broj_dionica, moj_portfelj, broj_dionica_u_mom_portfelju);
  printf ("Vrijednost portfelja: %.2f", ukupna_vrijednost);


  return 0;
}

/*
3
MSFT 10.00 Microsoft
TSLA 20.00 Tesla
AMZN 30.00 Amazon
2
MSFT 20
AMZN 20

*/