/*

Napisati funkciju za izvlačenje dobitne kombinacije igre Loto 6/45 prototipa:

void IzvlacenjeLota_6_od_45(int* kombinacija)

koja u jednodimenzionalno polje od 6 članova pohranjuje izvučenu kombinaciju 6 brojeva u rasponu 1-45.

Inicijalna vrijednost generatora pseudoslučajnih brojeva (pozivom funkcije srand) 
se inicijalizira na pozivajućoj razini (funkciji main) i ne treba je ponovno inicijalizirati.

Interval pseudoslučajnih brojeva prilagoditi traženom intervalu uz pomoć izraza koji 
koristi operaciju ostatka cjelobrojnog dijeljenja (prikazan na predavanjima).

Primjer jedne izvučene kombinacije gdje je seed = 1, može biti na Linux sustavu (Edgar):

29·17·28·26·24·2·
na Windows sustavu:

42·18·35·41·45·20·
Primjer druge izvučene kombinacije gdje je seed = 5, može biti na linux sustavu (Edgar):

26·6·31·28·42·38·
na Windows sustavu:

10·29·16·15·31·21·
Važno: Za transformaciju pseudoslučajnog broja u broj iz željenog intervala koristiti operator %, 
inače nećete dobiti jednak rezultat.
*/

void IzvlacenjeLota_6_od_45(int* kombinacija) {
    for(int i = 0; i < 6; i++) {
        kombinacija[i] = rand() % (45 - 1 + 1) + 1;
    }
}