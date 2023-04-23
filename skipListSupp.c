#include <stdio.h>
#include <stdlib.h>
#include "main.h"

// ce module permet de supprimer un élément donné d'une skiplist
void suppNiveaux(struct skipMaillon* prec, int val, struct skipMaillon** teteTemp){

    struct skipMaillon* sauv;
    struct skipMaillon* actuel = skipSuivant(prec) ; // maillon à supprimer
    struct skipMaillon* proch = skipSuivant(actuel); // maillon (à chainer) aprés tous les maillons qui ont la valeur à supprimer
    /*skipAffAdrSuivant(prec, proch);
    free(sauv);
    prec = bas(prec);*/

    while(prec != NULL){
        /*sauv = skipSuivant(prec);
        proch = skipSuivant(sauv);*/
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
        //printf("\n%d", skipValeur(teteTemp));
        //printf("\n in supp %d", skipValeur(teteTemp) == val);
    //if(skipValeur(teteTemp) == val){
        //printf("\n im vaaaaal");
        //teteTemp = proch;

        /*while(skipValeur(skipSuivant(prec)) < val){ // sauter tous les élements entre prec et le maillon à supprimer
            prec = skipSuivant(prec);
        }
        suppEtChainHoriz(prec, val);
        prec = bas(prec);
        /*sauv = skipSuivant(prec); // maillon à supprimer
        skipAffAdrSuivant(prec, skipSuivant(sauv));
        free(sauv);*/
    }
}
