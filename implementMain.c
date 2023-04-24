#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "main.h"


/*allouer un maillon d'une skiplist --------------------------------------*/
void skipAllouer(struct skipMaillon** mP){
    *mP = (struct skipMaillon*)malloc(sizeof(struct skipMaillon));
    skipAffAdrBas(*mP, NULL);
    skipAffAdrSuivant(*mP, NULL);
}

/*affectation d'une valeur au maillon---------------------*/

void skipAffVal(struct skipMaillon* mP, int val){
    mP->valeur = val;
}

/*affectation d'une address du next maillon---------------------*/

void skipAffAdrSuivant(struct skipMaillon* mP, struct skipMaillon* suivantP){
    mP->suivant = suivantP;
}

/*affectation d'une address du maillon au dessous---------------------*/

void skipAffAdrBas(struct skipMaillon* mP, struct skipMaillon* basP){
    mP->bas = basP;
}

/*afficher la valeur d'un mallion------------------------*/

int skipValeur(struct skipMaillon* mP){
    return mP->valeur;
}
/* afficher le suivant à droite d'un maillon----------------------*/

struct skipMaillon* skipSuivant(struct skipMaillon* mP){
    return mP->suivant;
}

/* afficher le suivant au dessous d'un maillon----------------------*/

struct skipMaillon* bas(struct skipMaillon* mP){
    return mP->bas;
}

/*lire une Llc------------------------------------------*/

struct skipMaillon* skipLireLlc(){
    int n;
    int val;
    struct skipMaillon* P;
    struct skipMaillon* Q;
    struct skipMaillon* tete;
    printf("\nLe nombre des élements: ");
    scanf("%d", &n);
    printf("\nLa valeur: ");
    scanf("%d", &val);
    skipAllouer(&P);
    skipAffVal(P, val);
    tete = P;
    for (int i=2 ; i<=n ; i++){
        printf("\nLa valeur: ");
        scanf("%d", &val);
        skipAllouer(&Q);
        skipAffVal(Q, val);
        skipAffAdrSuivant(P , Q);
        P = Q;
    }
    skipAffAdrSuivant(P , NULL);
    return tete;
}
/*lire une Llc----------------random--------------------------*/

void skipLireLlcRand(struct skipMaillon** tete){
    int n;
    int val = 1;
    struct skipMaillon* P;
    struct skipMaillon* Q;
    time_t t;
    skipAllouer(&P);
    val = val + (rand() % 100);
    skipAffVal(P, val);
    *tete = P;
    for (int i=2 ; i<=25000000 ; i++){
        skipAllouer(&Q);
        val = val + (rand() % 100);
        skipAffVal(Q, val);
        skipAffAdrSuivant(P , Q);
        P = Q;
    }
    skipAffAdrSuivant(P , NULL);
}

/*afficher une Llc -------------------------------------*/

void skipEcrireLlc(struct skipMaillon* tete){
    struct skipMaillon* P = tete;
    int i = 1;
    while (P != NULL){
        printf("\nla valeur '%d': %d",i ,skipValeur(P));
        i++;
        P = skipSuivant(P);

    }
}

// suppression d'une valeur donnée dans une llc triée ----------------------------------

void sortLlcSuppVal(struct skipMaillon** tete, int val) {
    struct skipMaillon* ptr = *tete;
    struct skipMaillon* sauv;
    struct skipMaillon* prec = NULL;
    int teteVal = skipValeur(*tete);
    while(ptr != NULL && skipValeur(ptr) < val){
        prec = ptr;
        ptr = skipSuivant(ptr);
    }

    while(ptr != NULL && skipValeur(ptr) == val){
        sauv = ptr;
        if(prec != NULL){
            skipAffAdrSuivant(prec, skipSuivant(ptr));
        }
        ptr = skipSuivant(ptr);
        free(sauv);
    }
    if(teteVal == val){
        *tete = ptr;
    }
}

// recherche d'une valeur donnée dans une llc triée ----------------------------------

void sortLlcRechVal(struct skipMaillon* tete, int val, bool* found, int* cpt) {
    struct skipMaillon* ptr = tete;
    *cpt = 0;
    *found = false;
    while(ptr != NULL && skipValeur(ptr) < val){
        ptr = skipSuivant(ptr);
    }

    while(ptr != NULL && skipValeur(ptr) == val){
        *found = true;
        cpt++;
    }

}
/*lenght of llc ---------------------------------------*/

int skipLenLlc(struct skipMaillon* tete){
    int cpt = 0;
    while (tete != "nil"){
        cpt = cpt + 1;
        tete = skipSuivant(tete);
    }
    return cpt;
}
