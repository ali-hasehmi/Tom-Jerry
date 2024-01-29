#include "Characters.h"

trap_t* create_t() {
    trap_t* trap = (trap_t*)malloc(sizeof(trap_t));
    trap->is_reveal = false;
    trap->x = rand()%15;
    trap->y = rand()%15;
    return trap;
}