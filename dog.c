#include <stdlib.h>
#include "dog.h"

ALLEGRO_BITMAP *dog_image  = NULL;
grid_t *g_grid = NULL;

void init_dog(grid_t *g)
{
    g_grid = g;
    dog_image = al_load_bitmap("dog02.png");
    if(dog_image == NULL){
        fprintf(stderr, "[!] init_dog():dog image Could not be loaded\n");
    }
}

void update_dog(dog_t *dog, int _x, int _y)
{
    dog->x = _x;
    dog->y = _y;
    draw_image_at(dog->image, g_grid, dog->x, dog->y);
}

dog_t *create_dog(int _attack, int _defense, int _speed)
{
    //load_dog_image();
    dog_t *dog = (dog_t *)malloc(sizeof(dog_t));
    dog->attack = _attack;
    dog->defense = _defense;
    dog->speed = _speed;
    dog->is_alive = true;
    dog->x = rand() % 15;
    dog->y = rand() % 15;
    dog->image = dog_image;
    draw_image_at(dog->image, g_grid, dog->x, dog->y);
    return dog;
}

int destroy_dog(dog_t *dog)
{
    al_destroy_bitmap(dog->image);
    free(dog);
}