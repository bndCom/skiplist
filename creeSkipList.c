#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "main.h"
bool key() {
    bool key_temp;

    int a = rand();

    if (a % 2 == 0) {
        key_temp = true;
    } else {
        key_temp = false;
    }
    return key_temp;
}
