#ifndef TOM_JERRY_BONUS_H
#define TOM_JERRY_BONUS_H
#include <stdbool.h>
#include <allegro5/allegro.h>
typedef struct grid grid_t;

typedef struct bonus
{
    bool is_taken;
    int gift;
    int x;
    int y;
    ALLEGRO_BITMAP* image;
} bonus_t;

void init_bonus(grid_t *_g);

bonus_t *create_bonus();

void take_bonus(bonus_t * _b);

void update_bonus(bonus_t * _b);

#endif // TOM_JERRY_BONUS_H
