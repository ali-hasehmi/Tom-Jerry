#ifndef TOM_JERRY_MOUSE_H
#define TOM_JERRY_MOUSE_H
#include <allegro5/allegro_image.h>
#include <allegro5/allegro.h>

#include <stdbool.h>

typedef struct mouse
{
    int speed;
    int x, y;
    int point;
    ALLEGRO_BITMAP *image;
} mouse_t;

mouse_t* create_mouse(int _speed,int _point);
void update(mouse_t* mouse,int _x,int _y);
int destroy_mouse(mouse_t* mouse);

#endif //TOM_JERRY_MOUSE_H
