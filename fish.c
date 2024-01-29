#include "Characters.h"

fish_t* create_fish() {
    fish_t* fish = (fish_t*)malloc(sizeof(fish_t));
    fish->energy = rand()%3 + 2;
    fish->x = rand()%15;
    fish->y = rand()%15;
    return fish;
}
