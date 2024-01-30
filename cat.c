#include "cat.h"

grid_t *c_grid = NULL;

ALLEGRO_BITMAP *cat_image1 = NULL;
ALLEGRO_BITMAP *cat_image2 = NULL;

void init_cat(grid_t *g)
{
    c_grid = g;
    cat_image1 = al_load_bitmap("./asset/cats/cat-1.png");
    if (cat_image1 == NULL)
    {
        fprintf(stderr, "init_cat(grid_t *): Couldn't Load cat-1.png\n");
    }
    cat_image2 = al_load_bitmap("./asset/cats/cat-2.png");
    if (cat_image1 == NULL)
    {
        fprintf(stderr, "init_cat(grid_t *): Couldn't Load cat-2.png\n");
    }
}
cat_t *create_cat()
{
    cat_t *cat = (cat_t *)malloc(sizeof(cat_t));
    cat->point = 0;
    cat->defense = 5;
    cat->attack = 2;
    cat->mouses = 0;
    cat->image = cat_image1;
    for (int i = 0; i < 18; i++)
    {
        cat->mouse[i] = *(create_mouse(DEAD));
    }
    cat->x = c_grid->width / 2;
    cat->y = c_grid->height / 2;
    update_square(c_grid->squares[cat->y][cat->x], CAT, (void *)cat);
    draw_image_at(cat->image, c_grid, cat->x, cat->y);
    return cat;
}
void update_cat(cat_t *cat, int _x, int _y)
{
    update_square(c_grid->squares[cat->y][cat->x], NOTHING, (void *)NULL);
    // switch (state)
    // {
    // case ONFISH:
    //     cat->defense += fish->energy;
    //     break;
    // case ONBONUS:
    //     cat->attack++;
    //     break;
    // }
        void *character = c_grid->squares[_y][_x]->character;
    switch (c_grid->squares[_y][_x]->type)
    {

    case DOG:
        // Combat with dog
        break;

    case CAT:
        // Combat with another Cat
        break;

    case FISH:
        // eat fish and gain Energy
        cat->defense += ((fish_t *)character)->energy;
        printf("eating fish\n");
        eat_fish(((fish_t *)character));
        break;

    case MOUSE:
        // Capture Mouse and Gain Point
        break;

    case BONUS:
        // Eat Bonus and gain Power(Attack)
        break;

    default:
        break;
    }
    if (c_grid->squares[_y][_x]->is_trap)
    {
        // Cat get on the Trap hence
        // It must suffer the one of the consequences :
        // Release the Richest Mice's of the cat
        // Reduce Attack by 2
        // Reduce Energy by 3
    }
    cat->x = _x;
    cat->y = _y;
    update_square(c_grid->squares[cat->y][cat->x], CAT, (void *)CAT);
    draw_image_at(cat->image, c_grid, cat->x, cat->y);
}

int destroy_cat(cat_t *cat)
{
    free(cat);
}

int move_cat(cat_t *_cat, int _dx, int _dy)
{
    if (!isValid(c_grid, _cat->x, _cat->y, _cat->x + _dx, _cat->y + _dy))
    {
        return 1;
    }
    if (_cat->actions < 0)
    {
        return -1;
    }
    update_cat(_cat, _cat->x + _dx, _cat->y + _dy);
}
