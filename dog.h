#ifndef TOM_JERRY_DOG_H
#define TOM_JERRY_DOG_H

#include <allegro5/allegro_image.h>
#include <allegro5/allegro.h>

#include <stdbool.h>

typedef struct dog
{
    int attack, defense, speed;
    bool is_alive;
    int x, y;
    ALLEGRO_BITMAP *image;
} dog_t;

dog_t* create_dog(int attack,int defense,int speed);



#endif //TOM_JERRY_DOG_H
