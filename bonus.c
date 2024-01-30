#include "bonus.h"
#include <stdlib.h>

#include "grid.h"

#include <stdio.h>

grid_t *b_grid = NULL;

ALLEGRO_BITMAP *bonus_image = NULL;

void init_bonus(grid_t *_g)
{
    b_grid = _g;
    bonus_image = al_load_bitmap("./asset/bonus/bonus.png");
    if (bonus_image == NULL)
    {
        fprintf(stderr, "init_bonus(grid_t *) : bonus.png is not loaded\n");
    }
}

bonus_t *create_bonus()
{
    bonus_t *bonus = (bonus_t *)malloc(sizeof(bonus_t));
    bonus->gift = 1;
    bonus->is_taken = false;
    bonus->image = bonus_image;
    do
    {
        bonus->x = rand() % 15;
        bonus->y = rand() % 15;
    } while (b_grid->squares[bonus->y][bonus->x]->is_trap || b_grid->squares[bonus->y][bonus->x]->is_bonus);
    b_grid->squares[bonus->y][bonus->x]->is_bonus = true;
    b_grid->squares[bonus->y][bonus->x]->bonus = bonus;
    return bonus;
}

void take_bonus(bonus_t *_b)
{
    _b->is_taken = true;
    b_grid->squares[_b->y][_b->x]->is_bonus = false;
    b_grid->squares[_b->y][_b->x]->bonus = NULL;
}

void update_bonus(bonus_t *_b)
{
    if (_b->is_taken)
    {
        return;
    }
    draw_image_at(_b->image, b_grid, _b->x, _b->y);
}
