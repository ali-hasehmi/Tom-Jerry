#ifndef TOM_JERRY_SQUARE_H
#define TOM_JERRY_SQUARE_H

#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro.h>

#include <stdio.h>
#include <stdbool.h>

typedef enum state
{
    NOTHING,
    TRAP,
    MOUSE,
    CAT,
    DOG,
    FISH,
    BONUS,
} state_t;

typedef struct square
{
    state_t type;
    int x1, y1;
    int x2, y2;
    int r, g, b;
    void *character;

} square_t;

square_t *create_square(int x1, int y1, int x2, int y2);

void destroy_square(square_t *s);

void draw_square(square_t *s);

void update_square(square_t *s, state_t _new_type, void *_new_character);

#endif // TOM_JERRY_SQUARE_H
