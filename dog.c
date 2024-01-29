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

dog_t *create_dog(dogtype_t type)
{
    //load_dog_image();
    dog_t *dog = (dog_t *)malloc(sizeof(dog_t));
    switch (type) {
        case PITBULL:
            dog->attack = 5;
            dog->speed = 5;
            dog->defense = 30;
            break;
        case BULLDOG:
            dog->attack = 2;
            dog->speed = 2;
            dog->defense = 15;
            break;
        case SHEPHERD:
            dog->attack = 2;
            dog->speed = 3;
            dog->defense = 20;
            break;
        case BULLDOGJR:
            dog->attack = 1;
            dog->speed = 1;
            dog->defense = 5;
            break;
        default:
            break;
    }
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