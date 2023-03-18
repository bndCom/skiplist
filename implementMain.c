#include <stdio.h>
#include <stdlib.h>
#include "main.h"


/*allouer un maillon d'une skiplist --------------------------------------*/
void skipAllouer(struct skipMaillon** mP){
    *mP = (struct skipMaillon*)malloc(sizeof(struct skipMaillon));
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
    skipAffAdrSuivant(P , "nil");
    return tete;
}

/*afficher une Llc -------------------------------------*/

void skipEcrireLlc(struct skipMaillon* tete){
    struct skipMaillon* P = tete;
    int i = 1;
    while (P != "nil"){
        printf("\nla valeur '%d': %d",i ,skipValeur(P));
        i++;
        P = skipSuivant(P);

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
