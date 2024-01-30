#ifndef TOM_JERRY_TRAP_H
#define TOM_JERRY_TRAP_H
#include <allegro5/allegro_image.h>
#include <allegro5/allegro.h>

#include <stdbool.h>

#include "grid.h"

typedef struct trap
{
    bool is_reveal;
    int x, y;
    ALLEGRO_BITMAP *image;
} trap_t;

void init_trap(grid_t *g);
trap_t *create_trap();
void update_trap(trap_t *t);
void destroy_trap(trap_t *t);
#endif // TOM_JERRY_TRAP_H
