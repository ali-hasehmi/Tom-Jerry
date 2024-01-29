#ifndef TOM_JERRY_SQUARE_H
#define TOM_JERRY_SQUARE_H
#include <allegro5/allegro_image.h>
#include <allegro5/allegro.h>

#include <stdbool.h>

typedef enum state
{
    nothing,
    trap,
    mouse,
    player,
    dog,
    fish,
    bonus
} state;

typedef struct square
{
    state type;
    int x1, y1;
    int x2, y2;
    int r, g, b;
    void *character;

} square_t;


#endif //TOM_JERRY_SQUARE_H
