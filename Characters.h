
#ifndef TOM_JERRY_CHARACTERS_H
#define TOM_JERRY_CHARACTERS_H
#include <stdbool.h>
typedef enum state { Nothing, Trap, Mouse, Playr, Dogs, Fish, Bonus}state;
typedef enum dogs {Bulldog, Pitbull, Shepherd, Bulldog_jr}dogs;
typedef enum mice { Three, Two, One }mice;

typedef struct square {
    state type;

}square;

typedef struct cat {
    int defense, attack, mouses;
    int is_limited;
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

typedef struct mouse{
    mice type;
    int point, speed;
}mouse;
typedef struct map {
    square nodes[15][15];
}map;

#endif //TOM_JERRY_CHARACTERS_H
