#ifndef TOM_JERRY_BONUS_H
#define TOM_JERRY_BONUS_H
#include <stdbool.h>

typedef struct bonus {
    bool is_taken;
    int gift;
}bonus_t;

bonus_t* create_bonus();

#endif //TOM_JERRY_BONUS_H
