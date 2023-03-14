#ifndef THE_HERETIC_RNG_H
#define THE_HERETIC_RNG_H

#include <stdlib.h>

int GenerateRandomChance();

int GenerateRandomChance(){
    int RNG, random = 1;

    srand(time(0) * random);
    random = rand();
    srand(random);
    RNG = rand() % 100 + 1;
    return RNG;
}

int GenerateRandom(int lower, int upper, int count);

int GenerateRandom(int lower, int upper, int count){
    int random = 1;

    srand(time(0) * random);
    random = rand();
    srand(random);
    int i;
    for (i = 0; i < count; i++) {
        int num = (rand() %
           (upper - lower + 1)) + lower;
        return num;
    }
}

#endif //THE_HERETIC_RNG_H
