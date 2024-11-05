#include <stdlib.h>

int random_num(int min, int max) {
    return rand() % (max - min + 1) + min;
}
