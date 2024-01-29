
#ifndef TOM_JERRY_CHARACTERS_H
#define TOM_JERRY_CHARACTERS_H

#include <allegro5/allegro_image.h>
#include <allegro5/allegro.h>

#include <stdbool.h>
typedef enum state { nothing, trap, mouse, player, dog, fish, bonus}state;
typedef enum dogs {Bulldog, Pitbull, Shepherd, Bulldog_jr}dogs;
typedef enum mice { Four= 4 ,Three = 3, Two = 2, One = 1 , Zero = 0}mice;

typedef struct square {
    state type;

}square;

typedef struct mouse{
    mice type;
    int speed;
    int x,y;
    ALLEGRO_BITMAP *image;
}Mouse;


typedef struct cat {
    int defense, attack, mouses;
    int is_limited;
    Mouse mouse[18];
    int x,y;
    ALLEGRO_BITMAP *image;
}Cat;

typedef struct player {
    Cat type;
    int point;
    int x,y;
    ALLEGRO_BITMAP *image;
}Player;

typedef struct dog {
    dogs type;
    int attack, defense, speed;
    bool is_alive;
    int x,y;
    ALLEGRO_BITMAP *image;
}Dog;


typedef struct fish{
    int energy;
    int x,y;
    ALLEGRO_BITMAP *image;
}Fish;

#endif //TOM_JERRY_CHARACTERS_H
