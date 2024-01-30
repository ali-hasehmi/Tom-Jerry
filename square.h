#ifndef TOM_JERRY_SQUARE_H
#define TOM_JERRY_SQUARE_H

#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro.h>

#include <stdio.h>
#include <stdbool.h>

typedef struct trap trap_t;

typedef enum state
{
    NOTHING,
    MOUSE,
    CAT,
    DOG,
    FISH,
} state_t;

typedef struct square
{
    state_t type;
    int x1, y1;
    int x2, y2;
    int r, g, b;
    void *character;
    trap_t *trap;
    bool is_trap;
    bool is_bonus;
    bool walls[4]; // 0 : left, 1 : up, 2 : right ,3 : down
} square_t;

square_t *create_square(int x1, int y1, int x2, int y2);

void destroy_square(square_t *s);

void draw_square(square_t *s);

void update_square(square_t *s, state_t _new_type, void *_new_character);

bool set_square_as_trap(square_t *s);

#endif // TOM_JERRY_SQUARE_H
