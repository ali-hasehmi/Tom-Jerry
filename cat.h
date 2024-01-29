#ifndef TOM_JERRY_CAT_H
#define TOM_JERRY_CAT_H
#include <allegro5/allegro_image.h>
#include <allegro5/allegro.h>

#include <stdbool.h>
#include "mouse.h"

typedef struct cat
{
    int point;
    int defense, attack, mouses;
    mouse_t mouse[18];
    int x, y;
    int actions;
    bool is_turn;
    int is_limited;
    ALLEGRO_BITMAP *image;
} cat_t;

cat_t* create_cat(int attack,int defense,int mouses);
void update_cat();
int destroy_cat();

#endif //TOM_JERRY_CAT_H
