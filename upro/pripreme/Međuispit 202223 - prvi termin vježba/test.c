#include <stdio.h>

int main() {

    int i;
    float f = 3.11415f;

    i = f + .5;
    printf("%d\n", i);

    f = 3.81415f;

    i = f + .5;
    printf("%d\n", i);
}

// #include <stdio.h>
// #define MAX 10

// int main(void)
// {
//     float tezinski_prosjek = 0.f, suma_ECTS = 0.f;
//     int sifStudent;
// // (*) definicija polja rezultati čiji su elementi struktura i inicijalizacija prva 2 elementa 

//     struct rez {
//         int sif_student;
//         float ECTS;
//         int ocjena;
//     };

//     struct rez rezultati[MAX];

//     rezultati[0].sif_student = 1;
//     rezultati[0].ECTS = 5.5f;
//     rezultati[0].ocjena = 5;
//     rezultati[1].sif_student = 2;
//     rezultati[1].ECTS = 5.5f;
//     rezultati[1].ocjena = 4;

//     scanf("%d", &sifStudent);

//     for (int i = 0; i < MAX; i++)
//         if (rezultati[i].sif_student == sifStudent && rezultati[i].ocjena > 1) {
//             tezinski_prosjek += rezultati[i].ECTS * rezultati[i].ocjena;
//             suma_ECTS += rezultati[i].ECTS;
//         }
//     if (suma_ECTS > 0.f)
//        printf("Tezinski prosjek: %5.2f\n", tezinski_prosjek / suma_ECTS);
//     return 0;
// }