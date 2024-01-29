#ifndef TOM_JERRY_DOG_H
#define TOM_JERRY_DOG_H

#include <allegro5/allegro_image.h>
#include <allegro5/allegro.h>

#include <stdbool.h>
#include "grid.h"

typedef struct dog
{
    int attack, defense, speed;
    bool is_alive;
    int x, y;
    ALLEGRO_BITMAP *image;
} dog_t;

void init_dog(grid_t *g);

dog_t *create_dog(int attack, int defense, int speed);

void update_dog(dog_t *dog, int _x, int _y);

int destroy_dog(dog_t *dog);


#endif // TOM_JERRY_DOG_H
