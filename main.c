#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "machineAbstraite.h"
#include "menu.h"


int main()
{
    int choix;
    char key ;
    int val1;
    int val2;
    int maillonNbr;

    do {
        clearScreen();
        printf("\n");
        printf("=================================\n");
        printf("           MENU\n");
        printf("=================================\n");
        printf("1. Tester la recherche \n");
        printf("2. Tester la suppression \n");
        printf("3. Tester l'insértion \n");
        printf("4. Quiter\n");
        printf("=================================\n");
        printf("Entrer votre choix: ");
        scanf("%d", &choix);

        switch(choix) {
            case 1:
                printf("\nEntrer la taille de la liste (millions de maillons) pour une bonne expérience ..");
                printf("\nNombre de maillons: ");
                scanf("%d", &maillonNbr);
                printf("\nEntrer une grande valeur (millions) pour une bonne expérience ..");
                printf("\nValeur à trouver: ");
                scanf("%d", &val1);
                rechTest(val1, maillonNbr); // ce module est dans menu.c
                break;
            case 2:
                printf("\nEntrer la taille de la liste (millions de maillons) pour une bonne expérience ..");
                printf("\nNombre de maillons: ");
                scanf("%d", &maillonNbr);
                printf("\nEntrer deux grandes différentes valeurs(millions) pour une bonne expérience ..");
                printf("\nValeur à supprimer dans skiplist: ");
                scanf("%d", &val1);
                printf("\nValeur à supprimer dans llc: ");
                scanf("%d", &val2);
                suppTest(val1, val2, maillonNbr); // ce module est dans menu.c
                break;
            case 3:
                printf("\nEntrer la taille de la liste (millions de maillons) pour une bonne expérience ..");
                printf("\nNombre de maillons: ");
                scanf("%d", &maillonNbr);
                printf("\nEntrer une grande valeur (millions) pour une bonne expérience ..");
                printf("\nValeur à insérer: ");
                scanf("%d", &val1);
                insertTest(val1, maillonNbr); // ce module est dans menu.c
                break;
            case 4:
                printf("\nAu revoir!!!\n");
                break;
            default:
                printf("\nChoix non valide. Essayer autre fois.\n");
                break;
        }
        printf("\n\n\nClick 'ENTER' pour continuer ...");
        key = getchar(); // doublé pour éviter quelques problèmes
        key = getchar();
    } while(choix != 4);

    return 0;
}
