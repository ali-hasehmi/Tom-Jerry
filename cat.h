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

typedef enum cat_type
{
    CAT_ONE = 0,
    CAT_TWO = 1
} cat_type_t;

typedef struct cat
{
    cat_type_t type;
    int point;
    int defense, attack, mouses;
    mouse_t *mouse[18];
    int x, y;
    int actions;
    bool is_turn;
    int is_limited;
    ALLEGRO_BITMAP *image;
} cat_t;

void init_cat(grid_t *g);
cat_t *create_cat(cat_type_t _t);
void update_cat(cat_t *cat, int _x, int _y);
int destroy_cat(cat_t *cat);
int move_cat(cat_t *_cat, int _dx, int _dy);
#endif // TOM_JERRY_CAT_H
