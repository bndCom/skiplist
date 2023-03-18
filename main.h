#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED


/*declaration de la structure maillon--------------------*/

struct skipMaillon{
    int valeur;
    struct maillon* suivant;
    struct maillon* bas;
};

/*allouer un maillon d'une skiplist --------------------------------------*/

void skipAllouer(struct skipMaillon** mP);

/*affectation d'une valeur au maillon---------------------*/

void skipAffVal(struct skipMaillon* mP, int val);

/*affectation d'une address du next maillon---------------------*/

void skipAffAdrSuivant(struct skipMaillon* mP, struct skipMaillon* suivantP);

/*affectation d'une address du maillon au dessous---------------------*/

void skipAffAdrBas(struct skipMaillon* mP, struct skipMaillon* basP);

/*afficher la valeur d'un mallion------------------------*/

int skipValeur(struct skipMaillon* mP);

/* afficher le suivant à droite d'un maillon----------------------*/

struct skipMaillon* skipSuivant(struct skipMaillon* mP);

/* afficher le suivant au dessous d'un maillon----------------------*/

struct skipMaillon* bas(struct skipMaillon* mP);

/*lire une Llc------------------------------------------*/

struct skipMaillon* skipLireLlc();

/*afficher une Llc -------------------------------------*/

void skipEcrireLlc(struct skipMaillon* tete);
/*lenght of llc ---------------------------------------*/

int skipLenLlc(struct skipMaillon* tete);

#endif // MAIN_H_INCLUDED
