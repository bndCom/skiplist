#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "main.h"
#include "machineAbstraite.h"

// les variables ----------

struct skipMaillon* P;
struct skipMaillon* lightHouse;
struct skipMaillon* prec;
bool found;
int cpt;

// clear menu screen ---------------------------------------------------

void clearScreen() {
#ifdef _WIN32
    system("cls"); // pour windows
#else
    system("clear"); // pour linux et macOS
#endif
}

// test de la recherche ---------------------------------------

void rechTest(int val){

    skipLireLlcRand(&P); // lecture de la llc ( ce module est dans implementMain.c )
    skipCree(&lightHouse, P); // creation de la skiplist ( ce module est dans machineAbstraite.c )

    clock_t startTime = clock(); // recherche dans skiplist
    skipRech(lightHouse, val, &prec, &found, &cpt);
    double skipTime = (double)(clock() - startTime) / CLOCKS_PER_SEC;
    printf("\nskiplist: trouvé (0 pour faux, 1 pour vrai): %d, count: %d", found, cpt);

    startTime = clock();// recherche dans llc
    sortLlcRechVal(P, val, &found, &cpt);
    double llcTime = (double)(clock() - startTime) / CLOCKS_PER_SEC;
    printf("\nliste lc: trouvé (0 pour faux, 1 pour vrai): %d, count: %d", found, cpt);

    printf("\n----------------------------");

    printf("\n*skiplist recherche* Done in %f miliseconds", skipTime*1000);
    printf("\n*liste lc recherche* Done in %f miliseconds", llcTime*1000);
    printf("\nrecherche dans skiplist est plus rapide que llc %d fois", (int)(llcTime/ skipTime));

}

// test de la recherche ---------------------------------------

void suppTest(int val1, int val2){

    skipLireLlcRand(&P); // lecture de la llc ( ce module est dans implementMain.c )
    skipCree(&lightHouse, P); // creation de la skiplist ( ce module est dans machineAbstraite.c )

    clock_t startTime = clock(); // supp de skiplist
    skipSupp(lightHouse, val1, &P);
    double skipTime = (double)(clock() - startTime) / CLOCKS_PER_SEC;

    startTime = clock();// supp de llc
    sortLlcSuppVal(&P, val2);
    double llcTime = (double)(clock() - startTime) / CLOCKS_PER_SEC;

    printf("\n----------------------------");

    printf("\n*skiplist suppression* Done in %f miliseconds", skipTime*1000);
    printf("\n*liste lc suppression* Done in %f miliseconds", llcTime*1000);
    printf("\nsuppression du skiplist est plus rapide que llc %d fois", (int)(llcTime/ skipTime));

}








