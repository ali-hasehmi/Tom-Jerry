#include "Functions.h"
#include <stdio.h>
#include <math.h>

void miceAdder(cat_t *cat_one, cat_t *cat_two)
{
    if (cat_two == NULL)
    {
        for (int i = 0; i < 18; i++)
        {
            cat_one->mouse[i] = NULL;
        }
        cat_one->mouses = 0;
        cat_one->point = 0;
    }
    else
    {

        mouse_t *new_mouses[18];
        int itr = 0;
        for (int i = 0; i < 18; i++)
        {
            printf("loop1\n");
            if (cat_one->mouse[i])
            {
                new_mouses[itr++] = cat_one->mouse[i];
            }
        }
        for (int i = 0; i < 18; i++)
        {
            printf("loop2\n");
            if (cat_two->mouse[i])
            {
                new_mouses[itr++] = cat_two->mouse[i];
            }
        }
        printf("loops ended\n");
        cat_one->mouses += cat_two->mouses;
        cat_one->point += cat_two->mouses;
        cat_two->point = 0;
        miceAdder(cat_two, NULL);
    }
}

int combatCats(cat_t *cat_one, cat_t *cat_two)
{
    printf("combatCats called\n");
    if (cat_one == NULL || cat_two == NULL)
    {
        fprintf(stderr, "combatCats(cat_t *,cat_t *) : nullptr\n");
        return 1;
    }
    printf("%d %d %d %d", cat_two->attack, cat_two->defense, cat_one->attack, cat_one->defense);
    printf("in combat baby");
    if ((cat_two->attack * cat_two->defense) > (cat_one->defense * cat_one->attack))
    {
        printf("if one");
        cat_two->defense -= (cat_one->attack * cat_one->defense / cat_two->attack);
        cat_one->attack = 1;
        cat_one->defense = 0;
        miceAdder(cat_two, cat_one);
        cat_one->is_limited = 2;
        return 0;
    }
    else if ((cat_two->attack * cat_two->defense) < (cat_one->defense * cat_one->attack))
    {
        cat_one->defense -= (cat_two->attack * cat_two->defense / cat_one->attack);
        cat_two->attack = 1;
        cat_two->defense = 0;
        miceAdder(cat_one, cat_two);
        cat_two->is_limited = 2;
        return 1;
    }
    else
    {
        return -1;
    }
}

int combatDogs(cat_t *cat, dog_t *dog)
{
    if ((cat->attack * cat->defense) > (dog->defense * dog->attack))
    {
        cat->defense -= (dog->attack * dog->defense / cat->attack);
        kill_dog(dog);
        return 1;
    }
    else if ((cat->attack * cat->defense) < (dog->defense * dog->attack))
    {
        cat->attack = 1;
        cat->defense = 0;
        for(int i = 0 ; i < 18 ; i++) {
            if(cat->mouse[i])
                release_mouse(cat->mouse[i]);
        }
        miceAdder(cat, NULL);
        cat->is_limited = 2;
        return 0;
    }
    else
    {
        return -1;
    }
}

int dice()
{
    return (rand() % 6) + 1;
}

void stayOnTrap(cat_t *cat)
{
    for (int i = 0; i < cat->mouses; i++)
    {
        for (int j = i + 1; j < cat->mouses; j++)
        {
            if (cat->mouse[i] == NULL)
            {
                cat->mouse[i] = cat->mouse[j];
                cat->mouse[j] = NULL;
            }
            else if (cat->mouse[j] == NULL)
            {
            }
            else if ((cat->mouse[i]->point <= cat->mouse[j]->point))
            {
                mouse_t *tmp = cat->mouse[j];
                cat->mouse[j] = cat->mouse[i];
                cat->mouse[i] = tmp;
            }
        }
    }
    if (cat->mouses)
    {
        release_mouse(cat->mouse[0]);
        cat->point -= cat->mouse[0]->point;
        cat->mouse[0] = NULL;
        cat->mouses--;
    }
    else if (cat->attack > 2)
        cat->attack -= 2;
    else if (cat->attack <= 2)
        cat->defense -= 3;
}

void stayOnMouse(cat_t *cat, mouse_t *mouse)
{
    for (int i = 0; i < 18; i++)
    {
        if (cat->mouse[i] == NULL)
        {
            cat->mouse[i] = mouse;
            break;
        }
    }
    cat->mouses++;
    cat->point += mouse->point;
}
