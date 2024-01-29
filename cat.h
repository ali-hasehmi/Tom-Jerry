#ifndef TOM_JERRY_CAT_H
#define TOM_JERRY_CAT_H
#include <allegro5/allegro_image.h>
#include <allegro5/allegro.h>

#include <stdbool.h>
#include "mouse.h"
#include "Characters.h"

typedef enum status { ONFISH , ONBONUS }status_t;

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

cat_t* create_cat();
void update_cat(cat_t* cat,state_t state,fish_t* fish);
int destroy_cat();

#endif //TOM_JERRY_CAT_H
