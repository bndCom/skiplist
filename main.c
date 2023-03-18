#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/*Ici la main fonction ou on fait les differents oppérations sur les skipList ---------------------------------------*/

int main()
{

    struct skipMaillon* P;
    P = skipLireLlc();
    skipEcrireLlc(P);


    return 0;
}
