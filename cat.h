#ifndef TOM_JERRY_CAT_H
#define TOM_JERRY_CAT_H
#include <allegro5/allegro_image.h>
#include <allegro5/allegro.h>

#include <stdbool.h>
#include "mouse.h"
#include "Characters.h"

typedef enum status
{
    ONFISH,
    ONBONUS
} status_t;

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

void init_cat(grid_t *g);
cat_t *create_cat();
void update_cat(cat_t *cat, int _x, int _y);
int destroy_cat(cat_t *cat);

#endif // TOM_JERRY_CAT_H
