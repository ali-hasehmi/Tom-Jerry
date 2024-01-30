#include "bonus.h"
#include <stdlib.h>

bonus_t* create_bonus() {
    bonus_t* bonus = (bonus_t*)malloc(sizeof(bonus_t));
    bonus->gift = 1;
    bonus->is_taken = false;
    return bonus;
}