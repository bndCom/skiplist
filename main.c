#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "main.h"
#include "machineAbstraite.h"
#include "menu.h"


int main()
{
    int choix;
    char key ;
    int val1;
    int val2;

    do {
        clearScreen();
        printf("\n");
        printf("=================================\n");
        printf("           MENU\n");
        printf("=================================\n");
        printf("1. Tester la recherche 1\n");
        printf("2. Tester la suppression 2\n");
        printf("3. Tester l'insértion 3\n");
        printf("4. Quiter\n");
        printf("=================================\n");
        printf("Entrer votre choix: ");
        scanf("%d", &choix);

        switch(choix) {
            case 1:
                printf("\nEntrer une grande valeur (millions) pour une bonne expérience ..");
                printf("\nValeur à trouver: ");
                scanf("%d", &val1);
                rechTest(val1); // ce module est dans menu.c
                break;
            case 2:
                printf("\nEntrer deux grandes différentes valeurs(millions) pour une bonne expérience ..");
                printf("\nValeur à supprimer dans skiplist: ");
                scanf("%d", &val1);
                printf("\nValeur à supprimer dans llc: ");
                scanf("%d", &val2);
                suppTest(val1, val2); // ce module est dans menu.c
                break;
            case 3:
                printf("\nYou chose Option 3.\n");
                break;
            case 4:
                printf("\nAu revoir!!!\n");
                break;
            default:
                printf("\nChoix invalide. Essayer autre fois.\n");
                break;
        }
        printf("\nClick 'ENTER' pour continuer ...");
        key = getchar(); // doublé pour éviter quelques problèmes
        key = getchar();
    } while(choix != 4);

    return 0;
}
