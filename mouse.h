#ifndef TOM_JERRY_MOUSE_H
#define TOM_JERRY_MOUSE_H
#include <allegro5/allegro_image.h>
#include <allegro5/allegro.h>

#include <stdbool.h>

typedef struct mouse
{
    int speed;
    int x, y;
    ALLEGRO_BITMAP *image;
} mouse_t;

#endif //TOM_JERRY_MOUSE_H
