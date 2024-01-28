
#ifndef TOM_JERRY_CHARACTERS_H
#define TOM_JERRY_CHARACTERS_H
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
}Mouse;


typedef struct cat {
    int defense, attack, mouses;
    int is_limited;
    Mouse mouse[18];
}Cat;

typedef struct player {
    Cat type;
    int point;
}Player;

typedef struct dog {
    dogs type;
    int attack, defense, speed;
    bool is_alive;
}Dog;

typedef struct map {
    square nodes[15][15];
}map;

typedef struct fish{
    int energy;
}Fish;

#endif //TOM_JERRY_CHARACTERS_H
