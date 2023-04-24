#include <stdio.h>
#include <stdlib.h>
#include "main.h"

// ce module permet de supprimer un élément donné d'une skiplist
void suppNiveaux(struct skipMaillon* prec, int val, struct skipMaillon** teteTemp){

    struct skipMaillon* sauv;
    struct skipMaillon* actuel = skipSuivant(prec) ; // maillon à supprimer
    struct skipMaillon* proch = skipSuivant(actuel); // maillon (à chainer) aprés tous les maillons qui ont la valeur à supprimer

    while(prec != NULL){

        while(proch != NULL && skipValeur(proch) == val){// supp les éléments repétés aprés actuel (le plus haut)
            sauv = proch;
            proch = skipSuivant(proch);
            free(sauv);
        }
        while(skipValeur(skipSuivant(prec)) < val){ // sauter tous les élements entre prec et le maillon à supprimer
            prec = skipSuivant(prec);
        }
        skipAffAdrSuivant(prec, proch);
        sauv = actuel;
        actuel = bas(actuel);
        if(actuel != NULL){
            proch = skipSuivant(actuel);
        }
        prec = bas(prec);
        free(sauv);
        *teteTemp = proch;

    }
}
