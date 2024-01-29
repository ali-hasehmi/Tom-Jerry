#ifndef TOM_JERRY_CAT_H
#define TOM_JERRY_CAT_H
#include <allegro5/allegro_image.h>
#include <allegro5/allegro.h>

#include <stdbool.h>
#include "mouse.h"

typedef struct cat
{
    int defense, attack, mouses;
    int is_limited;
    mouse_t mouse[18];
    int x, y;
    ALLEGRO_BITMAP *image;

} cat_t;

typedef struct player
{
    cat_t type;
    int point;
    int x, y;
    int actions;
    bool is_turn;
    ALLEGRO_BITMAP *image;
} player_t;

#endif //TOM_JERRY_CAT_H
