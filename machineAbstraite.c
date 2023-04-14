#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "main.h"
#include "skipListSupp.h"

// module qui fait la recherche d'une valeur donnée dans une skiplist ----------------------------------------------------------------

bool skipRech(struct skipMaillon* lightHouse, int val, struct skipMaillon** prec, bool* found){

    struct skipMaillon* rechPtr = lightHouse;
    bool foundTemp = false;
    while(rechPtr != NULL && skipSuivant(rechPtr) != NULL && found == false){
        if(skipValeur(skipSuivant(rechPtr)) == val){
            foundTemp = true;
        }
        else if(skipValeur(skipSuivant(rechPtr)) < val){
            rechPtr = skipSuivant(rechPtr);
        }
        else{
            rechPtr = bas(rechPtr);
        }
    }
    // retourner les résulats de la recherche
    *prec = rechPtr; // ptr vers le maillon qui est chainné à gauche avec le maillon trouvé
    *found = foundTemp;
}

// ce module fait la suppression d'une valeur donnée dans une skiplist ----------------------------------------------------------------


void skipSupp(struct skipMaillon* lightHouse, int val){

    bool found;
    struct skipMaillon* prec;
    // trouver le ptr vers le maillon qui précède l'élément à supprimer
    skipRech(lightHouse, val, &prec, &found);
    if(found){
        suppNiveaux(prec);
    }













}
