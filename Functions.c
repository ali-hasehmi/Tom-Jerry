#include "Functions.h"
#include <stdio.h>
#include <math.h>

void miceAdder(cat_t* cat_one,cat_t* cat_two) {
    if(cat_two == NULL) {
        for(int i = 0 ; i < 18 ; i++) {
           cat_one->mouse[i] = *create_mouse(DEAD);
        }
    }
    else {
        mice_t new_mouses[18];
        int itr = 0;
        for(int i = 0 ; i < 18 ; i++) {
            if( cat_one->mouse[i].type != DEAD ) {
                new_mouses[itr++] = cat_one->mouse[i];
            }
        }
        for(int i = 0 ; i < 18 ; i++) {
            if( cat_two->mouse[i].type != DEAD ) {
                new_mouses[itr++] = cat_two->mouse[i];
            }
        }
        cat_one->mouses += cat_two->mouses;
        cat_two->mouses = 0;
    }
}


int combatCats(cat_t *cat_one,cat_t *cat_two)
{
    if ((cat_two->attack * cat_two->defense) > (cat_one->defense * cat_one->attack))
    {
        cat_two->defense -= (cat_one->attack * cat_one->defense / cat_two->attack);
        cat_one->attack = 1;
        cat_one->defense = 0;
        miceAdder(cat_two,cat_one);
        cat_one->is_limited = 2;
        return 2;
    }
    else if ((cat_two->attack * cat_two->defense) < (cat_one->defense * cat_one->attack))
    {
        cat_one->defense -= (cat_two->attack * cat_two->defense / cat_one->attack);
        cat_two->attack = 1;
        cat_two->defense = 0;

        cat_two->is_limited = 2;
        return 1;
    }
    else
    {
        return 0;
    }
}

int combatDogs(cat_t *cat, dog_t *dog)
{
    if ((cat->attack * cat->defense) > (dog->defense * dog->attack))
    {
        cat->defense -= (dog->attack * dog->defense / cat->attack);
        dog->attack = 1;
        dog->defense = 0;
        dog->is_alive = false;
        return 1;
    }
    else if ((cat->attack * cat->defense) < (dog->defense * dog->attack))
    {
        cat->attack = 1;
        cat->defense = 0;
        cat->mouses = 0;
        cat->is_limited = 2;
        return 2;
    }
    else
    {
        return 0;
    }
}

int dice()
{
    return (rand() % 6) + 1;
}

void stayOnFish(cat_t *cat, fish_t *fish)
{
    cat->defense += fish->energy;
}

void stayOnBonus(cat_t *cat)
{
    cat->attack++;
}

void stayOnTrap(cat_t *cat)
{
    for (int i = 0; i < cat->mouses; i++)
    {
        for (int j = i + 1; j < cat->mouses; j++)
        {
            if ((cat->mouse[i].point <= cat->mouse[j].point) && cat->mouse[i].type != DEAD && cat->mouse[j].type != DEAD)
            {
                mouse_t tmp = cat->mouse[j];
                cat->mouse[j] = cat->mouse[i];
                cat->mouse[i] = tmp;
            }
        }
    }
    if (cat->mouses)
    {

        cat->mouse[0].point = 0;
        cat->mouses--;
    }
    else if (cat->attack > 2)
        cat->attack -= 2;
    else if (cat->attack <= 2)
        cat->defense -= 3;
}