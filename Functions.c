#include "Functions.h"
#include <stdio.h>
#include <math.h>

int combatCats(Cat cat_one,Cat cat_two) {
    if((cat_two.attack * cat_two.defense) > (cat_one.defense * cat_one.attack)) {
        cat_two.defense -=  (cat_one.attack * cat_one.defense / cat_two.attack);
        cat_one.attack = 1;
        cat_one.defense = 0;
        cat_two.mouses += cat_one.mouses;
        cat_one.mouses = 0;
        cat_one.is_limited = 2;
        return 2;
    }
    else if((cat_two.attack * cat_two.defense) < (cat_one.defense * cat_one.attack)) {
        cat_one.defense -=  (cat_two.attack * cat_two.defense / cat_one.attack);
        cat_two.attack = 1;
        cat_two.defense = 0;
        cat_one.mouses += cat_two.mouses;
        cat_two.mouses = 0;
        cat_two.is_limited = 2;
        return 1;
    }
    else {
        return 0;
    }
}

int combatDogs(Cat cat,Dog dog) {
    if((cat.attack * cat.defense) > (dog.defense * dog.attack)) {
        cat.defense -=  (dog.attack * dog.defense / cat.attack);
        dog.attack = 1;
        dog.defense = 0;
        dog.is_alive = false;
        return 1;
    }
    else if((cat.attack * cat.defense) < (dog.defense * dog.attack)) {
        cat.attack = 1;
        cat.defense = 0;
        cat.mouses = 0;
        cat.is_limited = 2;
        return 2;
    }
    else {
        return 0;
    }
}

int dice() {
    return (rand() % 6) + 1;
}

