
#ifndef TOM_JERRY_CHARACTERS_H
#define TOM_JERRY_CHARACTERS_H

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

typedef enum dogs
{
    Bulldog,
    Pitbull,
    Shepherd,
    Bulldog_jr
} dogs;

typedef enum mice
{
    Four = 4,
    Three = 3,
    Two = 2,
    One = 1,
    Zero = 0
} mice;

typedef struct square
{
    state type;
    int x1, y1;
    int x2, y2;
    int r, g, b;
    void *character;

} square_t;

typedef struct mouse
{

    mice type;
    int speed;
    int x, y;
    ALLEGRO_BITMAP *image;

} mouse_t;

typedef struct cat
{

    int defense, attack, mouses;
    int is_limited;
    mouse_t mouse[18];
    int x, y;
    ALLEGRO_BITMAP *image;
    
} cat_t;

typedef struct player
{
    cat_t type;
    int point;
    int x, y;
    ALLEGRO_BITMAP *image;
} player_t;

typedef struct dog
{

    dogs type;
    int attack, defense, speed;
    bool is_alive;
    int x, y;
    ALLEGRO_BITMAP *image;

} dog_t;

typedef struct fish
{
    int energy;
    int x, y;
    ALLEGRO_BITMAP *image;
} fish_t;

#endif // TOM_JERRY_CHARACTERS_H
