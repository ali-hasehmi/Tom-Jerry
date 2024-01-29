#ifndef TOM_JERRY_FISH_H
#define TOM_JERRY_FISH_H
#include <allegro5/allegro_image.h>
#include <allegro5/allegro.h>

#include <stdbool.h>

typedef struct fish
{
    int energy;
    int x, y;
    bool is_alive;
    ALLEGRO_BITMAP *image;
} fish_t;

#endif //TOM_JERRY_FISH_H
