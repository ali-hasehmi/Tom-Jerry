#include "Characters.h"

#include "fish.h"

ALLEGRO_BITMAP *fish_image = NULL;
grid_t *f_grid = NULL;
void init_fish(grid_t *g)
{
    f_grid = g;
    fish_image = al_load_bitmap("./asset/fish/fish.png");
    if(fish_image == NULL){
        fprintf(stderr, "init_fish(grid_t *): Can't load fish image\n");
    }
}

fish_t *create_fish()
{
    fish_t *fish = (fish_t *)malloc(sizeof(fish_t));
    fish->image = fish_image;
    fish->energy = rand() % 3 + 2;
    fish->x = rand() % 15;
    fish->y = rand() % 15;
    draw_image_at(fish_image, f_grid, fish->x, fish->y);
    update_square(f_grid->squares[fish->y][fish->x], FISH, fish);
    return fish;
}

void update_fish(fish_t *f, bool _is_alive)
{
    f->is_alive = _is_alive;
    if (!f->is_alive)
    {
        update_square(f_grid->squares[f->y][f->x], NOTHING, NULL);
        return;
    }
    draw_image_at(f->image, f_grid, f->x, f->y);
    update_square(f_grid->squares[f->y][f->x], FISH, (void *)f);
}

void destroy_fish(fish_t *f)
{
    free(f);
}
