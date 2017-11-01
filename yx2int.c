
#include "yx2int.h"
#include "assert.h"

int xy2int(int x, int y, int taille) {
    return x + (y-1)*taille;
}

