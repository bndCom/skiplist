#include <stdbool.h>
#ifndef MACHINEABSTRAITE_H_INCLUDED
#define MACHINEABSTRAITE_H_INCLUDED

    void skipSupp(struct skipMaillon* lightHouse, int val,struct skipMaillon** tete);
    void skipRech(struct skipMaillon* lightHouse, int val, struct skipMaillon** prec, bool* found, int* cpt);
    void skipCree (struct skipMaillon ** lighthouse  , struct skipMaillon * tete );

#endif
