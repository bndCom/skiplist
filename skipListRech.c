#include <stdio.h>
#include <stdlib.h>
#include "main.h"

// trouver le ptr du précédent dans la LLC originale ------------------------------------------
struct skipMaillon* skipOrigin(struct skipMaillon* lightHouse, struct skipMaillon* ptr){

    struct skipMaillon* origin = ptr;
    while(bas(origin) != NULL){
         origin = bas(origin);
    }
    if(lightHouse == ptr){ // cas où le precedent est le lightHouse on peut pas avoir l'origin du llc,
                            // on essaie de faire ça
        origin = bas(skipSuivant(origin));
    }
    return origin;
}

// trouver le nombre du repetition d'une valeur trouvée dans une llc ----------------------------------------
int llcValRepeat(struct skipMaillon* tete, int val){

        int cpt = 0;
        struct skipMaillon* ptr = tete;
        while(skipValeur(ptr) != val){ // trouver ptr vers 1ère apparition de la valeur
            ptr = skipSuivant(ptr);
        }
        while(ptr != NULL && skipValeur(ptr) == val){ // calculer
            cpt++;
            ptr = skipSuivant(ptr);
        }
        return cpt;
}

// trouver le nombre du repetition d'une valeur trouvée dans une skipList ---------------- module essentiel------------------------
int skipValRepeat(struct skipMaillon* lightHouse, struct skipMaillon* prec, int val){

    struct skipMaillon* origin = skipOrigin(lightHouse, prec);

    return llcValRepeat(origin, val);

}





