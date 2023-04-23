#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "main.h"
#include "machineAbstraite.h"

/*void generateDotFile(struct skipMaillon *head, char *filename) {
    FILE *fp = fopen(filename, "w");
    fprintf(fp, "digraph SkipList {\n");
    fprintf(fp, "  node [shape=circle];\n");
    fprintf(fp, "  rankdir=LR;\n");
    fprintf(fp, "\n");

    // Iterate through each level of the skip list
    struct skipMaillon *currentLevel = head;
    while (currentLevel != NULL) {
        fprintf(fp, "  { rank=same; ");
        // Iterate through each node on this level
        struct skipMaillon *currentNode = currentLevel;
        while (currentNode != NULL) {
            // Generate .dot entry for this node
            fprintf(fp, "node%d [label=\"%d\"];\n", skipValeur(currentNode), skipValeur(currentNode));
            if (skipSuivant(currentNode) != NULL) {
                fprintf(fp, "node%d -> node%d;\n", skipValeur(currentNode), skipValeur(skipSuivant(currentNode)));
            }
            if (bas(currentNode) != NULL) {
                fprintf(fp, "node%d -> node%d [style=dashed];\n", skipValeur(currentNode), skipValeur(bas(currentNode)));
            }
            currentNode = skipSuivant(currentNode);
        }
        fprintf(fp, "  }\n");
        currentLevel = bas(currentLevel);
    }

    fprintf(fp, "}\n");
    fclose(fp);
}*/
/*Ici la main fonction ou on fait les differents oppérations sur les skipList ---------------------------------------*/
int elLevel(struct skipMaillon* lightHouse){
    int cpt = 1;
    while(lightHouse != NULL){
        cpt++;
        lightHouse = skipSuivant(lightHouse);
    }
    return cpt;
}
int main()
{

    struct skipMaillon* P;
    struct skipMaillon* lightHouse;
    struct skipMaillon* prec;
    struct skipMaillon* level1_1;
    struct skipMaillon* level1_2;
    struct skipMaillon* level1_3;
    struct skipMaillon* level2_1;
    struct skipMaillon* level2_3;
    struct skipMaillon* lightHouseBas;
    bool found;
    int cpt;
    P = skipLireLlc();
    skipAllouer(&lightHouse);
    skipAllouer(&lightHouseBas);
    skipAllouer(&level1_1);
    skipAffVal(level1_1, skipValeur(P));
    skipAllouer(&level1_2);
    skipAffVal(level1_2, skipValeur(skipSuivant(P)));
    skipAllouer(&level1_3);
    skipAffVal(level1_3, skipValeur(skipSuivant(skipSuivant(P))));
    skipAllouer(&level2_1);
    skipAffVal(level2_1, skipValeur(P));
    skipAllouer(&level2_3);
    skipAffVal(level2_3, skipValeur(skipSuivant(skipSuivant(P))));
    skipAffAdrSuivant(lightHouse, level2_1);
    skipAffAdrSuivant(lightHouseBas, level1_1);
    skipAffAdrSuivant(level2_1, level2_3);
    skipAffAdrSuivant(level1_1, level1_2);
    skipAffAdrSuivant(level1_2, level1_3);
    skipAffAdrBas(lightHouse, lightHouseBas);
    skipAffAdrBas(level2_1, level1_1);
    skipAffAdrBas(level1_1, P);
    skipAffAdrBas(level1_2, skipSuivant(P));
    skipAffAdrBas(level2_3, level1_3);
    skipAffAdrBas(level1_3, skipSuivant(skipSuivant(P)));
    //skipCree(&lightHouse, P);
    //skipRech(lightHouse, 5, &prec, &found, &cpt);
    //printf("\nlighthouse: %p, prec: %p, found: %d, cpt: %d", lightHouse, prec,found, cpt);
    skipEcrireLlc(P);
    printf("\n-----------------");
    skipSupp(lightHouse, 5);
    skipEcrireLlc(P);
    //cpt = 0;
    //skipRech(lightHouse, 5, &prec, &found, &cpt);
    //printf("\nlighthouse: %p, prec: %p, found: %d, cpt: %d", lightHouse, prec,found, cpt);
    //cpt = elLevel(lightHouse);
    //printf("\n%d", cpt);
    //generateDotFile(lightHouse, "skiplist_virt.dot");



    return 0;
}
