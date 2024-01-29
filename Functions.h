#ifndef TOM_JERRY_FUNCTIONS_H
#define TOM_JERRY_FUNCTIONS_H
#include "Characters.h"
#include <time.h>
#include <stdlib.h>
int combatCats(Cat *cat_one, Cat *cat_two);
int combatDogs(Cat *cat, Dog *dog);
int dice();
void stayOnFish(Cat *cat, Fish *fish);
void stayOnBonus(Cat *cat);
void stayOnTrap(Cat *cat);
#endif // TOM_JERRY_FUNCTIONS_H
