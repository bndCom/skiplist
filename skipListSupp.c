#include <stdio.h>
#include <stdlib.h>
#include "main.h"

// ce module permet de supprimer un élément donné d'une skiplist
void suppNiveaux(struct skipMaillon* prec){

    struct skipMaillon* sauv;
    while(prec != NULL){
        sauv = skipSuivant(prec); // maillon à supprimer
        skipAffAdrSuivant(prec, skipSuivant(sauv));
        free(sauv);
        prec = bas(prec);
    }
}
