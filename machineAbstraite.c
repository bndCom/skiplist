#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "main.h"
#include "skipListSupp.h"
#include "skipListRech.h"
#include "creeSkipList.h"

// module qui fait la recherche d'une valeur donnée dans une skiplist ----------------------------------------------------------------

void skipRech(struct skipMaillon* lightHouse, int val, struct skipMaillon** prec, bool* found, int* cpt){

    struct skipMaillon* preced = lightHouse;
    bool foundTemp = false;
    *cpt = 0;

    while(preced != NULL && !foundTemp){
        if (skipSuivant(preced) == NULL){
            preced = bas(preced);
        }
        else if(skipValeur(skipSuivant(preced)) > val ){
            preced = bas(preced);
        }
        else if(skipValeur(skipSuivant(preced)) == val){
            foundTemp = true;

            *cpt = skipValRepeat(lightHouse, preced, val);
        }
        else if(skipValeur(skipSuivant(preced)) < val){
            preced = skipSuivant(preced);
        }
    }
    // retourner les résulats de la recherche
    *prec = preced; // ptr vers le maillon qui est chainné à gauche avec le maillon trouvé
    *found = foundTemp;
}

// ce module fait la suppression d'une valeur donnée dans une skiplist ----------------------------------------------------------------


void skipSupp(struct skipMaillon* lightHouse, int val, struct skipMaillon** tete){

    bool found;
    struct skipMaillon* prec;
    struct skipMaillon* teteTemp;
    int cpt;
    int teteValSauv = skipValeur(*tete);
    // trouver le ptr vers le maillon qui précède l'élément à supprimer et le nombre de répetition
    skipRech(lightHouse, val, &prec, &found, &cpt);
    if(found){
        teteTemp = *tete;
        suppNiveaux(prec, val, &teteTemp);
        if(teteValSauv == val){ // cas où on supp premier él de la liste
            *tete = teteTemp;
        }
    }

}


void skipCree (struct skipMaillon ** lighthouse  , struct skipMaillon * tete ){

   int throwaway = 0;
   int i = 0 ;
   int maxlevel = 0 ;
     struct skipMaillon *ptr_guard;
     struct skipMaillon *guard ;
     struct skipMaillon *ptr_creation ;
     struct skipMaillon *new_guard ;
     struct skipMaillon *new_lightouse ;
     skipAllouer(&guard);
     ptr_guard = guard;
     skipAllouer(&(*lighthouse));
   skipAffAdrSuivant(*lighthouse,tete);


    while ( tete != NULL ){

            if (throwaway != 0 ){
        skipAffAdrSuivant(skipSuivant(ptr_guard),tete);
            }

        skipAffAdrSuivant(ptr_guard,tete);
throwaway++;
        while( key() != false )
{

     i++ ;

    skipAllouer(&ptr_creation);

    skipAffAdrBas(ptr_creation,skipSuivant(ptr_guard));

    skipAffVal(ptr_creation,skipValeur(skipSuivant(ptr_guard)));

    skipAffAdrSuivant(ptr_creation,NULL);


    if( i > maxlevel){


    skipAllouer(&new_guard);
    skipAllouer(&new_lightouse);
    skipAffAdrBas(ptr_guard,new_guard);
    skipAffAdrBas(new_lightouse,*lighthouse);
    skipAffAdrSuivant(new_lightouse,ptr_creation);
    skipAffAdrSuivant(new_guard,ptr_creation);
    skipAffAdrBas(new_guard,NULL);
    *lighthouse = new_lightouse;
    ptr_guard = new_guard;
    maxlevel++;

    } else{

  ptr_guard = bas(ptr_guard);

  skipAffAdrSuivant(skipSuivant(ptr_guard),ptr_creation);

  skipAffAdrSuivant(ptr_guard,ptr_creation);

    }


}

tete = skipSuivant(tete);
        i = 0;

        ptr_guard = guard;


}
}








