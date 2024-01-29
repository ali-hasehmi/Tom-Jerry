#ifndef TOM_JERRY_TRAP_H
#define TOM_JERRY_TRAP_H
#include <allegro5/allegro_image.h>
#include <allegro5/allegro.h>

#include <stdbool.h>

typedef struct trap {
    bool is_reveal;
    int x, y;
    ALLEGRO_BITMAP *image;
}trap_t;

#endif //TOM_JERRY_TRAP_H
