#ifndef TOM_JERRY_MOUSE_H
#define TOM_JERRY_MOUSE_H
#include <allegro5/allegro_image.h>
#include <allegro5/allegro.h>

#include <stdbool.h>

#include "grid.h"

typedef enum mice
{
    ONE,
    TWO,
    THREE,
    DEAD
} mice_t;

typedef struct mouse
{
    mice_t type;
    int speed;
    int x, y;
    int point;
    bool is_alive;
    int actions;
    ALLEGRO_BITMAP *image;
} mouse_t;

void init_mouse(grid_t* g);
mouse_t *create_mouse(mice_t type);
mouse_t *create_mouse_with_xy(int _x,int _y);
void update_mouse(mouse_t *mouse, int _x, int _y);
int destroy_mouse(mouse_t *mouse);
void eat_mouse(mouse_t* mouse);
int move_mouse(mouse_t* _m,mouse_t* cats[2]);

#endif // TOM_JERRY_MOUSE_H
