#include <stdlib.h>
#include "dog.h"

dog_t* create_dog(int _attack,int _defense,int _speed) {
    dog_t* dog = (dog_t *)malloc(sizeof(dog_t));
    dog->attack = _attack;
    dog->defense = _defense;
    dog->speed = _speed;
    dog->x = rand()%15;
    dog->y = rand()%15;
    return dog;
}

void update(dog_t* dog ,int _x,int _y){
    dog->x = _x;
    dog->y = _y;
}

int destroy_dog(dog_t* dog) {
    free(dog);
}