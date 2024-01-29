#include <stdlib.h>
#include "dog.h"

dog_t* create_dog(int _attack,int _defense,int _speed,int _x,int _y) {
    dog_t* dog = (dog_t *)malloc(sizeof(dog_t));
    dog->attack = _attack;
    dog->defense = _defense;
    dog->speed = _speed;
    dog->x = _x;
    dog->y = _y;
    return dog;
}