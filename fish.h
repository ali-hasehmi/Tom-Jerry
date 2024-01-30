#ifndef TOM_JERRY_FISH_H
#define TOM_JERRY_FISH_H
#include <allegro5/allegro_image.h>
#include <allegro5/allegro.h>

#include <stdbool.h>

#include "grid.h"

typedef struct fish
{
    int energy;
    int x, y;
    bool is_alive;
    ALLEGRO_BITMAP *image;
} fish_t;

void init_fish(grid_t *g);

fish_t* create_fish();

void update_fish(fish_t *f);

void eat_fish(fish_t* _f);

void destroy_fish(fish_t *f);

#endif //TOM_JERRY_FISH_H
