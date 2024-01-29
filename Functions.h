#ifndef TOM_JERRY_FUNCTIONS_H
#define TOM_JERRY_FUNCTIONS_H
#include "Characters.h"
#include <time.h>
#include <stdlib.h>
void miceAdder(cat_t* cat_one,cat_t* cat_two);
int combatCats(cat_t *cat_one, cat_t *cat_two);
int combatDogs(cat_t *cat, dog_t *dog);
int dice();
void stayOnFish(cat_t *cat, fish_t *fish);
void stayOnBonus(cat_t *cat);
void stayOnTrap(cat_t *cat);
#endif // TOM_JERRY_FUNCTIONS_H
