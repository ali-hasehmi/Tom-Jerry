#include <stdlib.h>
#include "dog.h"

ALLEGRO_BITMAP *dog_image1 = NULL;
ALLEGRO_BITMAP *dog_image2 = NULL;
ALLEGRO_BITMAP *dog_image3 = NULL;
ALLEGRO_BITMAP *dog_image4 = NULL;
grid_t *d_grid = NULL;

void init_dog(grid_t *g)
{
    d_grid = g;
    dog_image1 = al_load_bitmap("./asset/dogs/dog01.png");
    if (dog_image1 == NULL)
    {
        fprintf(stderr, "[!] init_dog():dog image 1 Could not be loaded\n");
    }

    dog_image2 = al_load_bitmap("./asset/dogs/dog02.png");
    if (dog_image2 == NULL)
    {
        fprintf(stderr, "[!] init_dog():dog image 2 Could not be loaded\n");
    }

    dog_image3 = al_load_bitmap("./asset/dogs/dog03.png");
    if (dog_image3 == NULL)
    {
        fprintf(stderr, "[!] init_dog():dog image 3 Could not be loaded\n");
    }

    dog_image4 = al_load_bitmap("./asset/dogs/dog04.png");
    if (dog_image4 == NULL)
    {
        fprintf(stderr, "[!] init_dog():dog image 4 Could not be loaded\n");
    }
}

void update_dog(dog_t *dog, int _x, int _y)
{
    if (!dog->is_alive)
    {
        return;
    }
    if (dog->x == _x && dog->y == _y)
    {
        draw_image_at(dog->image, d_grid, dog->x, dog->y);
        update_square(d_grid->squares[dog->y][dog->x], DOG, (void *)dog);
        return;
    }
    update_square(d_grid->squares[dog->y][dog->x], NOTHING, NULL);
    dog->x = _x;
    dog->y = _y;
    draw_image_at(dog->image, d_grid, dog->x, dog->y);
    update_square(d_grid->squares[dog->y][dog->x], DOG, (void *)dog);
}

dog_t *create_dog(dogtype_t type)
{
    // load_dog_image();
    dog_t *dog = (dog_t *)malloc(sizeof(dog_t));
    switch (type)
    {
    case PITBULL:
        dog->attack = 5;
        dog->speed = 5;
        dog->defense = 30;
        dog->image = dog_image1;
        break;
    case BULLDOG:
        dog->attack = 2;
        dog->speed = 2;
        dog->defense = 15;
        dog->image = dog_image2;
        break;
    case SHEPHERD:
        dog->attack = 2;
        dog->speed = 3;
        dog->defense = 20;
        dog->image = dog_image3;
        break;
    case BULLDOGJR:
        dog->attack = 1;
        dog->speed = 1;
        dog->defense = 5;
        dog->image = dog_image4;
        break;
    default:
        break;
    }
    dog->is_alive = true;
    do
    {
        dog->x = rand() % 15;
        dog->y = rand() % 15;
    } while (d_grid->squares[dog->y][dog->x]->type != NOTHING);
    draw_image_at(dog->image, d_grid, dog->x, dog->y);
    update_square(d_grid->squares[dog->y][dog->x], DOG, (void *)dog);
    return dog;
}

int destroy_dog(dog_t *dog)
{
    al_destroy_bitmap(dog->image);
    free(dog);
}

void kill_dog(dog_t *_dog)
{
    _dog->is_alive = false;
    update_square(d_grid->squares[_dog->y][_dog->x], NOTHING, NULL);
}

int move_dog(dog_t *_dog)
{
    if (!_dog->is_alive)
    {
        return -1;
    }
    // bool best_move = false;
    int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int new_x, new_y;
    // for (int i = 0; i < 4; ++i)
    // {
    //     int dx = dir[i][0];
    //     int dy = dir[i][1];
    //     new_x = _dog->x + dx;
    //     new_y = _dog->y + dy;
    //     if (d_grid->squares[new_y][new_x]->type == CAT)
    //     {
    //         best_move = true;
    //         break;
    //     }
    // }

    do
    {
        int rand_num = rand() % 4;
        new_x = _dog->x + dir[rand_num][0];
        new_y = _dog->y + dir[rand_num][1];
    } while (!isValid(d_grid, _dog->x, _dog->y, new_x, new_y));

    update_dog(_dog, new_x, new_y);
}